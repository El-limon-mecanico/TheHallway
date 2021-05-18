#include "Lever.h"
#include "QuackEntity.h"
#include "PlayerMovement.h"
#include "QuackEnginePro.h"


void Lever::update()
{
	// si el jugador esta en contacto con la manivela y presiona la tecla, se carga la manivela
	if (player_ && InputManager::Instance()->isKeyDown(SDL_SCANCODE_SPACE))
	{
		progress_ += QuackEnginePro::Instance()->time()->deltaTime();
		std::cout << progress_ << "\n";
	}
	
	// si se puede descargar la manivela, se descarga
	else if (progress_ > 0)
	{
		progress_ -= QuackEnginePro::Instance()->time()->deltaTime() * 5;
	}
}

void Lever::onCollisionEnter(QuackEntity* other, Vector3D point)
{
	if (other->hasComponent<PlayerMovement>())
	{
		player_ = true;
	}
}

void Lever::onCollisionExit(QuackEntity* other, Vector3D point)
{
	if (other->hasComponent<PlayerMovement>())
	{
		player_ = false;
	}
}
