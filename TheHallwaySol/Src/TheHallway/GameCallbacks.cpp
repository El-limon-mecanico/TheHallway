#include "GameCallbacks.h"
#include <assert.h>
#include <iostream>
#include "CallBacks.h"
#include "SceneMng.h"
std::unique_ptr<GameCallbacks> GameCallbacks::instance_;

void GameCallbacks::ToEZGame()
{

	std::cout << "Ir al EZjuego\n";
	SceneMng::Instance()->loadScene("Scenes/EZGame.lua", "EZGame");
	//SceneMng::Instance()->pushNewScene("Scenes/scene1.lua", "scene1");
	//TODO hacer que nos lleve al juego
}
void GameCallbacks::toMedGame()
{

	std::cout << "Ir al Medjuego\n";
	SceneMng::Instance()->loadScene("Scenes/MedGame.lua", "MedGame");
	//SceneMng::Instance()->pushNewScene("Scenes/scene1.lua", "scene1");
	//TODO hacer que nos lleve al juego
}
void GameCallbacks::hardGame()
{

	std::cout << "Ir al Hard juego\n";
	SceneMng::Instance()->loadScene("Scenes/HardGame.lua", "HardGame");
	//SceneMng::Instance()->pushNewScene("Scenes/scene1.lua", "scene1");
	//TODO hacer que nos lleve al juego
}
void GameCallbacks::fromMainMenuToControls() {
	std::cout << "Ir a los controles\n";
	SceneMng::Instance()->loadScene("Scenes/MenuCtrl.lua", "menuctrl");
	//SceneMng::Instance()->pushNewScene("Scenes/MenuCtrl.lua", "menuctrl");
}
void GameCallbacks::fromMainMenuToLvlSelector() {
	std::cout << "Ir a los lvls\n";
	SceneMng::Instance()->loadScene("Scenes/LvlSelector.lua", "lvlSelector");
	//SceneMng::Instance()->pushNewScene("Scenes/MenuCtrl.lua", "menuctrl");
}
void GameCallbacks::fromControlsToMain()
{
	SceneMng::Instance()->loadScene("Scenes/MenuPpl.lua", "menuppl");
	//SceneMng::Instance()->popCurrentScene();
	std::cout << "Ir al menu ppl\n";
}
void GameCallbacks::fromGameOverToMain()
{
	SceneMng::Instance()->loadScene("Scenes/MenuPpl.lua", "menuppl");
	//SceneMng::Instance()->popCurrentScene();
	std::cout << "Ir al menu ppl\n";
}
void GameCallbacks::fromGameOverToLvlSelector()
{
	SceneMng::Instance()->loadScene("Scenes/LvlSelector.lua", "lvlSelector");
	//SceneMng::Instance()->popCurrentScene();
	std::cout << "Ir al menu ppl\n";
}
void GameCallbacks::initCallbacks()
{
	CallBacks::instance()->addMethod("ToEzGame", ToEZGame);
	CallBacks::instance()->addMethod("ToMedGame", toMedGame);
	CallBacks::instance()->addMethod("ToHardGame", hardGame);
	CallBacks::instance()->addMethod("menupplToLvlSelector", fromMainMenuToLvlSelector);
	CallBacks::instance()->addMethod("menupplToControls", fromMainMenuToControls);
	CallBacks::instance()->addMethod("controlsToMenuppl", fromControlsToMain);

	CallBacks::instance()->addMethod("gOtoMainMenu", fromGameOverToMain);
	CallBacks::instance()->addMethod("gOtoLvlSelector",fromGameOverToLvlSelector);
}


bool GameCallbacks::Init()
{
	assert(instance_.get() == nullptr);
	instance_.reset(new GameCallbacks());
	instance_.get()->initCallbacks();
	return instance_.get();
}

GameCallbacks* GameCallbacks::Instance()
{
	assert(instance_.get() != nullptr);
	return instance_.get();
}
