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
	transform->lookAt(transform->getParent()->getComponent<Transform>()->position());
}

void CameraController::updateLookAt()
{
	transform->lookAt(transform->getParent()->getComponent<Transform>()->position());
}

void CameraController::update()
{
	transform->Translate(Vector3D(0, 0, (InputManager::Instance()->getMouseWheel().y - wheelPos) * 10));
	wheelPos = InputManager::Instance()->getMouseWheel().y;
	std::cout << wheelPos;

	transform->setGlobalRotation(Vector3D(transform->rotation().x, transform->rotation().z, transform->getParent()->getComponent<Transform>()->rotation().z));
	updateLookAt();
}
