#include "GameCallbacks.h"
#include <assert.h>
#include <iostream>
#include "CallBacks.h"
std::unique_ptr<GameCallbacks> GameCallbacks::instance_;

void GameCallbacks::fromMainMenuToGame()
{
	std::cout << "Ir al juego\n";
	//TODO hacer que nos lleve al juego
}

void GameCallbacks::fromMainMenuToControls() {
	std::cout << "Ir a los controles\n";
	//TODO hacer que nos lleve a los controles
}
void GameCallbacks::fromControlsToMain()
{
	std::cout << "Ir al menu ppl\n";
}
void GameCallbacks::initCallbacks()
{
	CallBacks::instance()->addMethod("menupplToGame", fromMainMenuToGame);
	CallBacks::instance()->addMethod("menupplToControls", fromMainMenuToControls);
	CallBacks::instance()->addMethod("controlsToMenuppl",fromControlsToMain);
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
