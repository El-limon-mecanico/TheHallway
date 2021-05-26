#include "Lighter.h"
#include "Light.h"
#include "InputManager.h"
#include "QuackEntity.h"
#include "QuackEnginePro.h"
#include "PlayerMovement.h"
#include "ProgressBar.h"

bool Lighter::init(luabridge::LuaRef parameterTable)
{

	bool correct  = readVariable<float>(parameterTable, "ChargeSpeed",&chargeSpeed_);
	correct &= readVariable<float>(parameterTable, "DischargeSpeed", &dischargeSpeed_);
	return correct;
}


void Lighter::update() {
	// si la linterna no est� apagada y se pulsa el bot�n de carga, se carga la linterna     
	if (InputManager::Instance()->getMouseButtons().leftDown) {
		//cargas si se puede hacer
		if (actualCharge_ < 1) {
			//desactivas el movimiento
			if (pM_->getMoving())
				pM_->setMoving(false);
			actualCharge_ += QuackEnginePro::Instance()->time()->deltaTime() * chargeSpeed_;
			if (actualCharge_ > 1) //si llega al m�ximo, setea
				actualCharge_ = 1;
		}
	}
	else {
		//activa el movimiento si fuese necesario
		if (!pM_->getMoving())
			pM_->setMoving(true);
		//descargas
		if (actualCharge_ >0) {
			actualCharge_ -= QuackEnginePro::Instance()->time()->deltaTime() * dischargeSpeed_;
			if (actualCharge_ < 0)//si llega al m�nimo, setea
				actualCharge_ = 0;
		}
	}
	light_->setDistance(distance_* actualCharge_);
	if(actualCharge_<0.25)
		progressBar_->setProperty("ProgressColour", "FFFF0000");
	progressBar_->setProgress(actualCharge_);

}

void Lighter::start()
{
	light_ = entity_->getComponent<Light>();
	distance_ = light_->getDistance();
	pM_ = entity_->getComponent<PlayerMovement>();
	progressBar_ = entity_->getComponent<ProgressBar>();
	progressBar_->setProperty("ProgressColour", "FFFFFFFF");
}
