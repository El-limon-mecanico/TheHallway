#include "Exit.h"
#include "QuackEntity.h"
#include "PlayerMovement.h"
#include "QuackEnginePro.h"
#include "SceneMng.h"
#include "InputManager.h"

void Exit::onTriggerEnter(QuackEntity* other, Vector3D point)
{
	if (other->hasComponent<PlayerMovement>())
	{
		InputManager::Instance()->setMouseVisibility(true);
		SceneMng::Instance()->loadScene("Scenes/WinScene.lua", "WinScene");
	}
}
