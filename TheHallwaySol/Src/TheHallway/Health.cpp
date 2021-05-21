#include "Health.h"
#include "QuackEntity.h"
#include "Image.h"
#include "SceneMng.h"
#include "Scene.h"
#include "InputManager.h"
#include "QuackEnginePro.h"

bool Health::init(luabridge::LuaRef parameterTable)
{
	lives_ = readVariable<int>(parameterTable, "MaxLives");
	return true;
}

void Health::start()
{
	player_ = SceneMng::Instance()->getCurrentScene()->getObjectWithName("Player");
	WINDOW_WIDTH = 1000; // PILLAR EL TAMAÑO DE LA PANTALLA
	initialPos_ = player_->transform()->position();
	for (int i = 0; i < lives_; i++) {
		std::string name = "heart_" + std::to_string(i);
		QuackEntity* q = new QuackEntity();
		float pos = ((float)HEART_SIZE / WINDOW_WIDTH)* i;
		q->addComponent<Image>(name, "heart.png", false, false,
			true, std::pair<float, float>(pos,0), std::pair<float, float>(HEART_SIZE, HEART_SIZE), "TheHallway/StaticImage");
		SceneMng::Instance()->getCurrentScene()->addEntity(q);
		hearts_.push_back(q);
	}

}


void Health::hit()
{
	lives_--;
	if (lives_ > 0) {
		//resetea la posicion del jugador
		player_->transform()->setGlobalPosition(initialPos_);
		//quita una de las vidas de la UI
		hearts_.at(lives_)->getComponent<Image>()->setEnable(false);
	}
	else {
		SceneMng::Instance()->loadScene("Scenes/GameOver.lua", "gameover");
	}

}


