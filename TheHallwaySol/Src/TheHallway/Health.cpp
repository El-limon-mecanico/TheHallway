#include "Health.h"
#include "QuackEntity.h"
#include "Image.h"
#include "SceneMng.h"
#include "Scene.h"
#include "InputManager.h"
#include "QuackEnginePro.h"
#include "AudioSource.h";
#include "PlayerMovement.h"
bool Health::init(luabridge::LuaRef parameterTable)
{
	bool correct = readVariable<int>(parameterTable, "MaxLives",&lives_);
	return correct;
}

void Health::start()
{
	WINDOW_WIDTH = QuackEnginePro::Instance()->getWindoWidth(); 
	initialPos_ = entity_->transform()->position();
	for (int i = 0; i < lives_; i++) {
		std::string name = "heart_" + std::to_string(i);
		QuackEntity* q = new QuackEntity();
		float pos = ((float)HEART_SIZE / WINDOW_WIDTH)* i;
		q->addComponent<Image>(name, "heart.png", false, false,
			true, std::pair<float, float>(pos,0), std::pair<float, float>(HEART_SIZE, HEART_SIZE), "TheHallway/StaticImage");
		SceneMng::Instance()->getCurrentScene()->addEntity(q);
		hearts_.push_back(q);
	}
	Transform* screamsTransform=transform->getChildByName("ScreamSounds")->getComponent<Transform>();
	//Se hace rand()+1 ya que sino el hijo en la posicion 0 tendria mas posibilidades que el resto
	int child = (rand()+1) % screamsTransform->getChildren().size();
	std::cout << child << "\n";
	scream_=screamsTransform->getChild(child)->getComponent<AudioSource>();
}


void Health::hit()
{
	lives_--;
	entity_->getComponent<PlayerMovement>()->setMoving(false);
	if (lives_ > 0) {
		//resetea la posicion del jugador
		entity_->transform()->setGlobalPosition(initialPos_);
		//quita una de las vidas de la UI
		hearts_.at(lives_)->getComponent<Image>()->setEnable(false);
	}
	else {
		InputManager::Instance()->setMouseVisibility(true);
		SceneMng::Instance()->loadScene("Scenes/GameOver.lua", "GameOver");
	}

}

void Health::onTriggerEnter(QuackEntity* other, Vector3D point)
{
	if (other->tag() == "Enemy") {
		hit();
		scream_->play();
	}
}


