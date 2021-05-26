#include "MinimapController.h"
#include "Transform.h"
#include "QuackCamera.h"
#include "QuackEnginePro.h"
#include "QuackEntity.h"
#include "InputManager.h"
#include "SceneMng.h"
#include "Image.h"

bool MinimapController::init(luabridge::LuaRef parameterTable)
{
	return true;
}

void MinimapController::start()
{
	player_ = SceneMng::Instance()->getCurrentScene()->getObjectWithName("Player")->transform();
	entity_->getComponent<Image>()->setEnable(active_);
}

void MinimapController::update()
{
	transform->setGlobalPosition(Vector3D(player_->position().x, transform->position().y, player_->position().z));

	if (InputManager::Instance()->getKeyDown(SDL_SCANCODE_TAB))
	{
		active_ = !active_;

		entity_->getComponent<QuackCamera>()->setzOrder(2 * active_);
		entity_->getComponent<Image>()->setEnable(active_);
	}
}
