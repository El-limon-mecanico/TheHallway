#include <iostream>
#include <fstream>
#include "QuackEnginePro.h"
////////////////////////////Includes Agus///////////////////////////////////
#include "SceneMng.h"
#include "MeshRenderer.h"
#include "QuackEntity.h"
#include "LoopMovement.h"
///////////////////////////////////////////////////////////////////////////
#include "FactoryManager.h"
#include "MazeCreator.h"
#include "Lighter.h"
#include "PlayerMovement.h"
#include "CameraController.h"
void pruebasAgus() {
	FactoryManager::instance()->add<LoopMovement>();
	QuackEntity* cube = new QuackEntity("Cubito");
		MeshRenderer* r = cube->addComponent<MeshRenderer>();
		r->setMeshByPrefab(PrefabType::PT_CUBE);
		//r->setMaterial("cubooo");
		std::vector<Vector3D> v;
		v.push_back(Vector3D(-10, -3, 5));
		v.push_back(Vector3D(-17, 6, -6));
		v.push_back(Vector3D(7, -5, 4));
		LoopMovement* lM = cube->addComponent<LoopMovement>(0.02,v);
		cube->transform()->setLocalPosition({ 6,0,0 });
		cube->transform()->Scale(Vector3D(8, 8, 8));
		SceneMng::Instance()->getCurrentScene()->addEntity(cube);
}
void mainAgus() {

	//QuackEnginePro::Instance()->update();
		
}
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
		FactoryManager::instance()->add<CameraController>();
#ifdef AGUS
		pruebasAgus();
#endif // AGUS
		QuackEnginePro::Instance()->start("Scenes/scene1.lua", "scene1");
	}
	return 0;
}
