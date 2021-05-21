#include <iostream>
#include <fstream>
#include "QuackEnginePro.h"
#include "FactoryManager.h"
#include "MazeCreator.h"
#include "Lighter.h"
#include "PlayerMovement.h"
#include "GameCallbacks.h"
#include "QuackUI.h"
#include "LoopMovement.h"
#include "ChasePlayer.h"

#if (defined _DEBUG) //|| !(defined _WIN64)
int main() {
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
#else
#include <windows.h>
int WINAPI
WinMain(HINSTANCE zHInstance, HINSTANCE prevInstance, LPSTR lpCmdLine, int nCmdShow) {
#endif
	srand(time(NULL));
	// AQUI FALTA MANEJO DE ERRORES Y EXCEPCIONES
	if (QuackEnginePro::Init("The Hallway")) {
		GameCallbacks::Init();
		FactoryManager::instance()->add<LoopMovement>();
		FactoryManager::instance()->add<MazeCreator>();
		FactoryManager::instance()->add<Lighter>();
		FactoryManager::instance()->add<PlayerMovement>();
		UIElement::addScheme("TheHallway.scheme");
		FactoryManager::instance()->add<ChasePlayer>();
		QuackEnginePro::Instance()->start("Scenes/scene1.lua", "scene1");
	}
	return 0;
}
