#include <iostream>
#include <fstream>
#include "QuackEnginePro.h"
#include "FactoryManager.h"
#include "Lighter.h"
#include "Light.h"
#include "PlayerMovement.h"
#include "Health.h"
#include "CameraController.h"
#include "MazeManager.h"
#include "Light.h"
#include "Lever.h"
#include "Exit.h"
#include "GameCallbacks.h"
#include "QuackUI.h"
#include "LoopMovement.h"
#include "ChasePlayer.h"
#include "MinimapController.h"
#include "MazeRunner.h"

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
		FactoryManager::instance()->add<CameraController>();
		FactoryManager::instance()->add<MazeManager>();
		FactoryManager::instance()->add<PlayerMovement>();
		FactoryManager::instance()->add<Lever>();
		FactoryManager::instance()->add<Exit>();
		FactoryManager::instance()->add<LoopMovement>();
		FactoryManager::instance()->add<Lighter>();
		FactoryManager::instance()->add<ChasePlayer>();
		FactoryManager::instance()->add<Health>();
		FactoryManager::instance()->add<MinimapController>();
		FactoryManager::instance()->add<MazeRunner>();

		UIElement::addScheme("TheHallway.scheme");
		Light::setAmbientLight(Vector3D(0, 0, 0));
		//QuackEnginePro::Instance()->setFullScreen(true);
		QuackEnginePro::Instance()->start("Scenes/MenuPpl.lua", "MenuPpl");
	}
	return 0;
}
