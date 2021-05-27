#include "ChasePlayer.h"
#include "Transform.h"
#include "QuackEntity.h"
#include "Rigidbody.h"
#include "LoopMovement.h"
#include "PlayerMovement.h"
#include "SceneMng.h"


bool ChasePlayer::init(luabridge::LuaRef parameterTable)
{
	bool correct = readVariable<float>(parameterTable, "Speed",&speed_);

	// al principio de la partida, no persigue al jugador
	return correct;
}

void ChasePlayer::start()
{
	assert(entity_->hasComponent<Rigidbody>());
	rb_ = entity_->getComponent<Rigidbody>();

	setEnable(false);
}
void ChasePlayer::update() {

	//si nos hemos alejado mucho, volvemos al merodeo
	float dist = (transform->position() - playerTr_->position()).magnitude();
	if (dist > maxDistance_)
	{
		// volvemos al comportamiento de merodeo
		// assert porque no tenemos otro movimiento para los enemigos
		assert(entity_->hasComponent<LoopMovement>());
		entity_->getComponent<LoopMovement>()->setEnable(true);
		entity_->getComponent<LoopMovement>()->move();		

		setEnable(false);
	}
	else
	{
		direction_ = playerTr_->position();
		transform->lookAt(direction_);

		rb_->setVelocity(transform->forward * speed_);
	}
}

void ChasePlayer::onTriggerEnter(QuackEntity* other, Vector3D point)
{
	if (other->hasComponent<PlayerMovement>())
	{
		// dejamos de perseguir al jugador
		setEnable(false);
	}
}
