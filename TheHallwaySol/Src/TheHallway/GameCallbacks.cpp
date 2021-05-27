#include "GameCallbacks.h"
#include <assert.h>
#include <iostream>
#include "CallBacks.h"
#include "SceneMng.h"
#include "InputManager.h"
#include "QuackEnginePro.h"
std::unique_ptr<GameCallbacks> GameCallbacks::instance_;

void GameCallbacks::ToEZGame()
{
	InputManager::Instance()->setMouseVisibility(false);
	SceneMng::Instance()->loadScene("Scenes/EZGame.lua", "EZGame");
}
void GameCallbacks::toMedGame()
{

	InputManager::Instance()->setMouseVisibility(false);
	std::cout << "Ir al Medjuego\n";
	SceneMng::Instance()->loadScene("Scenes/MedGame.lua", "MedGame");
}
void GameCallbacks::hardGame()
{
	InputManager::Instance()->setMouseVisibility(false);
	std::cout << "Ir al Hard juego\n";
	SceneMng::Instance()->loadScene("Scenes/HardGame.lua", "HardGame");
}
void GameCallbacks::toControls() {
	InputManager::Instance()->setMouseVisibility(true);

	std::cout << "Ir a los controles\n";
	SceneMng::Instance()->pushNewScene("Scenes/MenuCtrl.lua", "MenuCtrl");
}
void GameCallbacks::back()
{
	SceneMng::Instance()->popCurrentScene();
}
void GameCallbacks::toMenuPpl()
{
	SceneMng::Instance()->loadScene("Scenes/MenuPpl.lua", "MenuPpl");
}
void GameCallbacks::quit()
{
	QuackEnginePro::Instance()->quit();
}
void GameCallbacks::toQuitScene()
{
	SceneMng::Instance()->pushNewScene("Scenes/QuitScene.lua", "QuitScene");
}
void GameCallbacks::toLvlSelector()
{
	SceneMng::Instance()->loadScene("Scenes/LvlSelector.lua", "LvlSelector");
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
	CallBacks::instance()->addMethod("toQuitScene", toQuitScene);
	CallBacks::instance()->addMethod("quit", quit);
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
