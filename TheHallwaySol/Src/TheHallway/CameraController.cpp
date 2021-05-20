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
	/*transform->Translate(Vector3D(0, 0, (InputManager::Instance()->getMouseWheel().y - wheelPos) * 10));
	wheelPos = InputManager::Instance()->getMouseWheel().y;
	std::cout << wheelPos;*/

	float mouseDeltaY_ = InputManager::Instance()->getMousePositionRelative().y - 0.5;
	float mouseDeltaX_ = InputManager::Instance()->getMousePositionRelative().x - 0.5;
	std::cout << "\n" << mouseDeltaY_ << "\n";
	std::cout << mouseDeltaX_ << "\n";
	transform->Rotate(Vector3D(mouseDeltaY_ * 1, 0, 0));
}

void CameraController::setCameraSpeed(float speed)
{
	cameraSpeed_ = speed;
}
