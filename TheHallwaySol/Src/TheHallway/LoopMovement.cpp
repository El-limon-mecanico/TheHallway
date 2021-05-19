#include "LoopMovement.h"
#include "Transform.h"
#include "QuackEntity.h"
#include "Rigidbody.h"
#include "SceneMng.h"
#include "Scene.h"
#include "ChasePlayer.h"

bool LoopMovement::init(luabridge::LuaRef parameterTable)
{
	LuaRef speed = readVariable<LuaRef>(parameterTable, "Speed");
	playerTriggerDistance_ = readVariable<LuaRef>(parameterTable, "Distance");
	speed_ = speed;
	LuaRef ob = readVariable<LuaRef>(parameterTable, "Objectives");
	for (size_t i = 1; i <= ob.length(); i++)
	{
		Vector3D v;
		v.x = ob[i][1];
		v.y = ob[i][2];
		v.z = ob[i][3];
		objectives_.push_back(v);
	}
	return true;
}

void LoopMovement::updateObjective() {
	bool update = false;

	Vector3D distance = objectives_[actualObjective_] - transform->position();
	update = (distance.magnitude() <= 1);

	if (update) {
		actualObjective_ = (actualObjective_ + 1) % (objectives_.size());
		transform->lookAt(objectives_[actualObjective_]);
		updateVelocity();
	}
}

void LoopMovement::updateVelocity()
{
	assert(rb_);
	transform->lookAt(objectives_[actualObjective_]);
	rb_->setVelocity(transform->forward * speed_);
}
void LoopMovement::start()
{
	assert(SceneMng::Instance()->getCurrentScene()->getObjectWithName("Player"));
	playerTr_ = SceneMng::Instance()->getCurrentScene()->getObjectWithName("Player")->transform();
	assert(entity_->hasComponent<Rigidbody>());
	rb_ = entity_->getComponent<Rigidbody>();
	rb_->setGravity({ 0,0,0 });
	transform->lookAt(objectives_[actualObjective_]);
	updateVelocity();
}
void LoopMovement::update() {
	updateObjective();
	// si estamos cerca del jugador, empezamos a perseguirle
	float distance = (transform->position() - playerTr_->position()).magnitude();
	std::cout << distance << "\n";
	if (distance < playerTriggerDistance_)
	{
		setEnable(false);
	}
}

/// <summary>
/// busca el punto mas cercano del circuito. Desde ahi empieza el circuito
/// </summary>
void LoopMovement::onEnable()
{
	// buscamos el objetivo mas cercano para volver al circuito
	float distanceMagn = INT_MAX;
	int index = 0;
	for (int i = 0; i < objectives_.size(); i++)
	{
		Vector3D distance = objectives_[i] - transform->position();
		float auxDist = distance.magnitude();
		if (auxDist < distanceMagn)
		{
			distanceMagn = auxDist;
			index = i;
		}
	}

	// cambiamos el objetivo por el que hemos calculado
	actualObjective_ = index;
	if(rb_)
		updateVelocity();
}

void LoopMovement::onDisable()
{
	// volvemos al comportamiento de persecucion
	// assert porque no tenemos otro movimiento para los enemigos
	assert(entity_->hasComponent<ChasePlayer>());
	entity_->getComponent<ChasePlayer>()->setEnable(true);
}

