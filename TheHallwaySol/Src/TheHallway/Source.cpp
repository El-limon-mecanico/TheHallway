#include <iostream>
#include <fstream>
#include "QuackEnginePro.h"
#include "FactoryManager.h"
#include "MazeCreator.h"
#include "Lighter.h"
#include "Light.h"
#include "PlayerMovement.h"
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
	if (QuackEnginePro::Init()) {
		FactoryManager::instance()->add<LoopMovement>();
		FactoryManager::instance()->add<MazeCreator>();
		FactoryManager::instance()->add<Lighter>();
		FactoryManager::instance()->add<PlayerMovement>();
		FactoryManager::instance()->add<ChasePlayer>();
		Light::setAmbientLight(Vector3D(0, 0, 0));
		QuackEnginePro::Instance()->start("Scenes/scene1.lua", "scene1");
	}
	return 0;
}
