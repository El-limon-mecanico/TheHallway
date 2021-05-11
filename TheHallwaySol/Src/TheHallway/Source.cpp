#include <iostream>
#include <fstream>
#include "QuackEnginePro.h"
////////////////////////////Includes Agus///////////////////////////////////
#define AGUS
#include "MeshRenderer.h"
#include "QuackEntity.h"
#include "Enemies/Protector/LoopMovement.h"
///////////////////////////////////////////////////////////////////////////
#if (defined _DEBUG) //|| !(defined _WIN64)
void pruebasAgus() {
		QuackEntity* cube = new QuackEntity("Cubito");
		MeshRenderer* r = cube->addComponent<MeshRenderer>();
		r->setMeshByPrefab(PrefabType::PT_CUBE);
		std::vector<Vector3D> v;
		v.push_back(Vector3D(0, 0, 0));
		v.push_back(Vector3D(7, 7, 0));
		v.push_back(Vector3D(9, 15, 0));
		LoopMovement* lM = cube->addComponent<LoopMovement>(5.3,v);

}
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
#ifdef AGUS
		pruebasAgus();
#else
		QuackEnginePro::Instance()->start();
		
#endif // AGUS
	}
	return 0;
}
