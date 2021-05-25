#include "Lever.h"
#include "QuackEntity.h"
#include "MazeManager.h"
#include "InputManager.h"
#include "MeshRenderer.h"
#include "PlayerMovement.h"
#include "QuackEnginePro.h"
#include "Rigidbody.h"
#include "SceneMng.h"


bool Lever::init(luabridge::LuaRef parameterTable)
{
	readVariable<float>(parameterTable, "Total", &total_);
	readVariable<float>(parameterTable, "ChargingVel", &chargingVel_);
	readVariable<float>(parameterTable, "UncharginVel", &unchargingVel_);
	return true;
}

void Lever::update()
{
	// si el jugador esta en contacto con la manivela y presiona la tecla, se carga la manivela
	if (player_ && InputManager::Instance()->getKey(SDL_SCANCODE_SPACE))
	{
  		progress_ += QuackEnginePro::Instance()->time()->deltaTime() * chargingVel_;
		std::cout << progress_ << ", " << total_ << std::endl;
		if (progress_ >= total_)
			charged_ = true;
	}
	
	// si se puede descargar la manivela, se descarga
	else if (progress_ > 0)
	{
		progress_ -= QuackEnginePro::Instance()->time()->deltaTime() * unchargingVel_;
	}

	if (charged_)
		setEnable(false);
}

void Lever::onTriggerEnter(QuackEntity* other, Vector3D point)
{
	if (other->hasComponent<PlayerMovement>())
	{
		player_ = true;
	}
}

void Lever::onTriggerExit(QuackEntity* other, Vector3D point)
{
	if (other->hasComponent<PlayerMovement>())
	{
		player_ = false;
	}
}

void Lever::onDisable()
{
	assert(mazeMng_);
	assert(entity_->hasComponent<MeshRenderer>());
	assert(entity_->hasComponent<Rigidbody>());
	
	entity_->getComponent<MeshRenderer>()->setEnable(false);
	mazeMng_->activateLever();
}
