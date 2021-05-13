#include <iostream>
#include <fstream>
#include "QuackEnginePro.h"
#include "Lighter.h"
#include "PlayerMovement.h"
#include "FactoryManager.h"
#include "MazeCreator.h"
#include "Rigidbody.h"
#include "MeshRenderer.h"
#include "QuackEntity.h"
#include "SceneMng.h"

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
		QuackEntity* cube = new QuackEntity("Cubito");
		cube->transform()->setGlobalPosition({ 0,10,0 });
		MeshRenderer* r = cube->addComponent<MeshRenderer>();
		r->setMeshByPrefab(PrefabType::PT_CUBE);
		Rigidbody* rb = cube->addComponent<Rigidbody>();
		rb->setRigidbody(1, ColliderType::CT_BOX);


		FactoryManager::instance()->add<MazeCreator>();
		SceneMng::Instance()->loadScene("Scenes/maze.lua", "scene1");
		SceneMng::Instance()->getCurrentScene()->addEntity(cube);
		QuackEnginePro::Instance()->start();
	}

	return 0;
}
