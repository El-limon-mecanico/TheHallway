#include "Lever.h"
#include "QuackEntity.h"
#include "MazeManager.h"
#include "InputManager.h"
#include "MeshRenderer.h"
#include "PlayerMovement.h"
#include "QuackEnginePro.h"
#include "Rigidbody.h"
#include "SceneMng.h"
#include "AudioSource.h"
#include "ProgressBar.h"

void Lever::start()
{
	sound_ = entity_->getComponent<AudioSource>();
}

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
		if(!sound_->isPlaying())
		sound_->play();
	}
	
	// si se puede descargar la manivela, se descarga
	else {
		if (progress_ > 0)
		{
			progress_ -= QuackEnginePro::Instance()->time()->deltaTime() * unchargingVel_;
		}
			sound_->stop();
	}
	if (charged_)
		finish();
	pb_->setProgress(progress_ / total_);
}

void Lever::onTriggerEnter(QuackEntity* other, Vector3D point)
{
	if (other->hasComponent<PlayerMovement>())
	{
		player_ = true;
		pb_->setEnable(true);
	}
}

void Lever::onTriggerExit(QuackEntity* other, Vector3D point)
{
	if (other->hasComponent<PlayerMovement>())
	{
		player_ = false;
		pb_->setEnable(false);
	}
}

void Lever::finish()
{
	assert(mazeMng_);
	sound_->stop();
	pb_->setEnable(false);
	mazeMng_->activateLever();
	entity_->destroy();
}

void Lever::start()
{
	pb_ = entity_->addComponent<ProgressBar>("Lever_"+entity_->name(), true, std::pair<float,float>{ 0.4,0.8 }, std::pair<float, float>{ 400,60 }, "TheHallway/ProgressBar");
	pb_->setProgress(0);
	pb_->setEnable(false);
}
