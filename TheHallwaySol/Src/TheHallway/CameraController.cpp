#include "CameraController.h"
#include "Transform.h"
#include "QuackCamera.h"
#include "QuackEntity.h"
#include "InputManager.h"
#include <iostream>

bool CameraController::init(luabridge::LuaRef parameterTable)
{
	return true;
}

void CameraController::start()
{

}

void CameraController::update()
{
	float mouseDeltaY_ = InputManager::Instance()->getMousePositionRelative().y - 0.5;
	transform->Rotate(Vector3D(mouseDeltaY_ * cameraSpeed_, 0, 0));
}

void CameraController::setCameraSpeed(float speed)
{
	cameraSpeed_ = speed;
}
