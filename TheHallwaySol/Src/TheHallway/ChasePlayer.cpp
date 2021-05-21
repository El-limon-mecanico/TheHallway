#include "ChasePlayer.h"
#include "Transform.h"
#include "QuackEntity.h"
#include "Rigidbody.h"
#include "LoopMovement.h"
#include "PlayerMovement.h"
#include "SceneMng.h"

bool ChasePlayer::init(luabridge::LuaRef parameterTable)
{
	LuaRef speed = readVariable<LuaRef>(parameterTable, "Speed");
	speed_ = speed;

	// al principio de la partida, no persigue al jugador
	return true;
}

void ChasePlayer::start()
{
	assert(SceneMng::Instance()->getCurrentScene()->getObjectWithName("Player"));
	playerTr_ = SceneMng::Instance()->getCurrentScene()->getObjectWithName("Player")->transform();

	assert(entity_->hasComponent<Rigidbody>());
	rb_ = entity_->getComponent<Rigidbody>();
	setEnable(false);
}
void ChasePlayer::update() {

	//si nos hemos alejado mucho, volvemos al merodeo
	float dist = (transform->position() - playerTr_->position()).magnitude();
	if (dist > maxDistance_)
		setEnable(false);
	else
	{
		direction_ = playerTr_->position();
		transform->lookAt(direction_);

		rb_->setVelocity(transform->forward * speed_);
	}
}


// TODO: ACTUALIZAR SALUD DEL JUGADOR
void ChasePlayer::onTriggerEnter(QuackEntity* other, Vector3D point)
{
	if (other->hasComponent<PlayerMovement>())
	{
		// matar al jugador
		// cambiar cuando tengamos un componente health

		// dejamos de perseguir al jugador
		setEnable(false);
	}
}

void ChasePlayer::onDisable()
{
	// volvemos al comportamiento de merodeo
	// assert porque no tenemos otro movimiento para los enemigos
	assert(entity_->hasComponent<LoopMovement>());
	entity_->getComponent<LoopMovement>()->setEnable(true);
}
