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
}
void GameCallbacks::toMedGame()
{

	std::cout << "Ir al Medjuego\n";
	SceneMng::Instance()->loadScene("Scenes/MedGame.lua", "MedGame");
}
void GameCallbacks::hardGame()
{

	std::cout << "Ir al Hard juego\n";
	SceneMng::Instance()->loadScene("Scenes/HardGame.lua", "HardGame");
}
void GameCallbacks::toControls() {
	std::cout << "Ir a los controles\n";
	SceneMng::Instance()->pushNewScene("Scenes/MenuCtrl.lua", "menuctrl");
}
void GameCallbacks::back()
{
	SceneMng::Instance()->popCurrentScene();
}
void GameCallbacks::toMenuPpl()
{
	SceneMng::Instance()->loadScene("Scenes/MenuPpl.lua", "menuppl");
}
void GameCallbacks::toLvlSelector()
{
	SceneMng::Instance()->loadScene("Scenes/LvlSelector.lua", "lvlSelector");
	std::cout << "Ir al menu ppl\n";
}
void GameCallbacks::initCallbacks()
{
	CallBacks::instance()->addMethod("ToEzGame", ToEZGame);
	CallBacks::instance()->addMethod("ToMedGame", toMedGame);
	CallBacks::instance()->addMethod("ToHardGame", hardGame);
	CallBacks::instance()->addMethod("toLvlSelector", toLvlSelector);
	CallBacks::instance()->addMethod("toControls", toControls);
	CallBacks::instance()->addMethod("back", back);
	CallBacks::instance()->addMethod("toMenuppl", toMenuPpl);
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
