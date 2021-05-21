#include "Health.h"
#include "QuackEntity.h"
#include "SceneMng.h"
#include "Scene.h"
bool Health::init(luabridge::LuaRef parameterTable)
{
	lives_ = readVariable<int>(parameterTable, "MaxLives");
	return true;
}

void Health::start()
{
	initialPos_ = entity_->transform()->position();
	for (int i = 0; i < lives_; i++) {
		
	}
}

void Health::hit()
{
	lives_--;
	if (lives_ > 0) {
		entity_->transform()->setGlobalPosition(initialPos_);
		//quitar una de las tres vidas de la UI
	}
	else {
		SceneMng::Instance()->loadScene("Scenes/GameOver.lua", "gameover");
	}

}


