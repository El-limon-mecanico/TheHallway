#include "Exit.h"
#include "QuackEntity.h"
#include "PlayerMovement.h"
#include "QuackEnginePro.h"
#include "SceneMng.h"
#include "InputManager.h"

void Exit::onCollisionEnter(QuackEntity* other, Vector3D point)
{
	if (other->hasComponent<PlayerMovement>())
	{
		SceneMng::Instance()->loadScene("Scenes/menu.lua", "menuPrincipal");
	}
}
