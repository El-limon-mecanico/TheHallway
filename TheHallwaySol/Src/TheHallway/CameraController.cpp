#include "CameraController.h"
#include "Transform.h"
#include "QuackCamera.h"
#include "QuackEnginePro.h"
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
	float mouseDeltaY_ = InputManager::Instance()->getMouseAxis(Vertical) * QuackEnginePro::Instance()->time()->deltaTime();
	float newAngle = yAngle_ + mouseDeltaY_ * cameraSpeed_;

	if(newAngle < 70 && newAngle > -70)
	{
		yAngle_ = newAngle;
		transform->Rotate(Vector3D(mouseDeltaY_ * cameraSpeed_, 0, 0));
	}
}

void CameraController::setCameraSpeed(float speed)
{
	cameraSpeed_ = speed;
}
