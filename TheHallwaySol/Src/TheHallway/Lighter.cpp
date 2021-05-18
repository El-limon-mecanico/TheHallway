#include "Lighter.h"
#include "Light.h"
#include "InputManager.h"
#include "QuackEntity.h"
#include "QuackEnginePro.h"
#include "PlayerMovement.h"


bool Lighter::init(luabridge::LuaRef parameterTable)
{
	chargeSpeed_ = readVariable<float>(parameterTable, "ChargeSpeed");
	dischargeSpeed_ = readVariable<float>(parameterTable, "DischargeSpeed");
	return true;
}


void Lighter::update() {
	// si la linterna no est� apagada y se pulsa el bot�n de carga, se carga la linterna     
	if (InputManager::Instance()->getMouseButtons().leftDown) {
		//cargas si se puede hacer
		if (actualCharge_ < 1) {
			//desactivas el movimiento
			/*if (pM_->isEnable())
				pM_->setEnable(false);*/
			actualCharge_ += QuackEnginePro::Instance()->time()->deltaTime() * chargeSpeed_;
			if (actualCharge_ > 1) //si llega al m�ximo, setea
				actualCharge_ = 1;
		}
	}
	else {
		//activa el movimiento si fuese necesario
		/*if (!pM_->isEnable())
			pM_->setEnable(true);*/
		//descargas
		if (actualCharge_ >0) {
			actualCharge_ -= QuackEnginePro::Instance()->time()->deltaTime() * dischargeSpeed_;
			if (actualCharge_ < 0)//si llega al m�nimo, setea
				actualCharge_ = 0;
		}
	}
	light_->setDistance(1000 * actualCharge_);
	std::cout << "CARGA DE LA LINTERNA: " << actualCharge_ * 100 << "%\n";
}

void Lighter::start()
{
	light_ = entity_->getComponent<Light>();
	pM_ = entity_->getComponent<PlayerMovement>();
}
