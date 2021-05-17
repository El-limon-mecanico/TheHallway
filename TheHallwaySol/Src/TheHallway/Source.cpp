#include <iostream>
#include <fstream>
#include "QuackEnginePro.h"
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

	srand(time(NULL));

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
		QuackEnginePro::Instance()->start("Scenes/scene1.lua", "scene1");
	}
	return 0;
}
