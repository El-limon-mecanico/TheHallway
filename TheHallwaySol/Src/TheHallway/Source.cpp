#include <iostream>
#include <fstream>
#include "QuackEnginePro.h"
////////////////////////////Includes Agus///////////////////////////////////
#include "SceneMng.h"
#include "MeshRenderer.h"
#include "QuackEntity.h"
#include "LoopMovement.h"
#include "../CEGUI/CEGUIQuack.h"
///////////////////////////////////////////////////////////////////////////
#include "FactoryManager.h"
#include "MazeCreator.h"
#include "Lighter.h"
#include "PlayerMovement.h"

#if (defined _DEBUG) //|| !(defined _WIN64)
int main() {
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
#else
#include <windows.h>
int WINAPI
WinMain(HINSTANCE zHInstance, HINSTANCE prevInstance, LPSTR lpCmdLine, int nCmdShow) {
#endif

	//esto es una prueba de los recursos
	std::ifstream f("Assets/fichero.txt");
	if (f.is_open())
	{
		std::cout << "El fichero se ha abierto\n";
		f.close();
	}
	else
	{
		std::cerr << "ERROR: el fichero no se ha abierto\n";
	}


	// AQUI FALTA MANEJO DE ERRORES Y EXCEPCIONES
	if (QuackEnginePro::Init()) {
		FactoryManager::instance()->add<MazeCreator>();
		FactoryManager::instance()->add<Lighter>();
		FactoryManager::instance()->add<PlayerMovement>();
		QuackEnginePro::Instance()->start("Scenes/UIAgus.lua", "scene1");
	}
	return 0;
}
