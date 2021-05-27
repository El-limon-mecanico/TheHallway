#include "PlayerMovement.h"
#include "InputManager.h"
#include "Transform.h"

#include "Rigidbody.h"
#include "QuackEntity.h"
#include "QuackEnginePro.h"
#include "CameraController.h"
#include <iostream>
#include "AudioSource.h"
#include "SceneMng.h"

bool PlayerMovement::init(luabridge::LuaRef parameterTable)
{
	bool correct  = readVariable<float>(parameterTable, "WalkingSpeed",&walkingSpeed_);
	correct = readVariable<float>(parameterTable, "RunningSpeed", &runningSpeed_);
	correct = readVariable<float>(parameterTable, "CameraSpeed",&cameraSpeed_);
	
	if(!correct)
		return false ;

	InputManager::Instance()->captureMouse();

	return true;
}



void PlayerMovement::start() {
	rb_ = entity_->getComponent<Rigidbody>();
	walkSound_ = transform->getChildByName("WalkSound")->getComponent<AudioSource>();
	runningSound_ = transform->getChildByName("RunSound")->getComponent<AudioSource>();
	CameraController* c = transform->getChild(0)->getComponent<CameraController>();
	if(c)
		c->setCameraSpeed(cameraSpeed_ * 0.75);
	
}

void PlayerMovement::rotate()
{
    float mouseDeltaX_ =  InputManager::Instance()->getMouseAxis(Horizontal) * QuackEnginePro::Instance()->time()->deltaTime();

    rb_->setAngularVelocity(Vector3D(0, -mouseDeltaX_ * cameraSpeed_, 0));
}

void PlayerMovement::move() {
	if (moving_) {
		if (InputManager::Instance()->getKeyDown(SDL_SCANCODE_LSHIFT))
			running = true;
		else if (InputManager::Instance()->getKeyUp(SDL_SCANCODE_LSHIFT))
			running = false;

		float VelocityX = (InputManager::Instance()->getAxis(Horizontal));
		float VelocityY = (InputManager::Instance()->getAxis(Vertical));
		Vector3D hor = transform->right * -VelocityX;
		Vector3D ver = transform->forward * VelocityY;
		Vector3D vel = (hor + ver);

		rb_->setVelocity(vel * (walkingSpeed_ + runningSpeed_ * running));
		if(vel.magnitude()!=0){
			if (!walkSound_->isPlaying() && !running) {
				runningSound_->stop();
				walkSound_->play();
			}
			else if (!runningSound_->isPlaying()&&running) {
				walkSound_->stop();
				runningSound_->play();
			}
		}
		else if (vel.magnitude() == 0) {
			walkSound_->stop();
			runningSound_->stop();
		}
	}
	else {
		rb_->setVelocity(Vector3D(0,0,0));
		walkSound_->stop();
		runningSound_->stop();
	}
}

void PlayerMovement::update() {
	rotate();
	move();
	if (InputManager::Instance()->getKeyDown(SDL_SCANCODE_ESCAPE)) {
		InputManager::Instance()->setMouseVisibility(true);
		SceneMng::Instance()->pushNewScene("Scenes/Pause.lua", "Pause");
	}
}
void PlayerMovement::onEnable()
{
	InputManager::Instance()->setMouseVisibility(false);
}