#include "PlayerMovement.h"
#include "InputManager.h"
#include "Transform.h"

#include "Rigidbody.h"
#include "QuackEntity.h"
#include "QuackEnginePro.h"
#include "CameraController.h"
#include <iostream>

bool PlayerMovement::init(luabridge::LuaRef parameterTable)
{
	walkingSpeed_ = readVariable<LuaRef>(parameterTable, "WalkingSpeed");
	runningSpeed_ = readVariable<LuaRef>(parameterTable, "RunningSpeed");
	cameraSpeed_ = readVariable<LuaRef>(parameterTable, "CameraSpeed");

	rb_ = entity_->getComponent<Rigidbody>();
	InputManager::Instance()->captureMouse();

	return true;
}

void PlayerMovement::start() {
	transform->getChild(0)->getComponent<CameraController>()->setCameraSpeed(cameraSpeed_ * 0.75);
}

void PlayerMovement::rotate()
{
    float mouseDeltaX_ =  InputManager::Instance()->getMousePositionRelative().x - 0.5;

    rb_->setAngularVelocity(Vector3D(0, -mouseDeltaX_ * cameraSpeed_, 0));
}

void PlayerMovement::move() {



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
}

void PlayerMovement::update() {
	rotate();
	if(moving_) move();
}