#include "Lighter.h"
#include "Light.h"
#include "InputManager.h"
#include "QuackEntity.h"
#include "QuackEnginePro.h"
#include "PlayerMovement.h"
#include "ProgressBar.h"

bool Lighter::init(luabridge::LuaRef parameterTable)
{
	readVariable<float>(parameterTable, "ChargeSpeed", &chargeSpeed_);
	readVariable<float>(parameterTable, "DischargeSpeed", &dischargeSpeed_);
	return true;
}


void Lighter::update() {
	// si la linterna no está apagada y se pulsa el botón de carga, se carga la linterna     
	if (InputManager::Instance()->getMouseButtons().leftDown) {
		//cargas si se puede hacer
		if (actualCharge_ < 1) {
			//desactivas el movimiento
			if (pM_->getMoving())
				pM_->setMoving(false);
			actualCharge_ += QuackEnginePro::Instance()->time()->deltaTime() * chargeSpeed_;
			if (actualCharge_ > 1) //si llega al máximo, setea
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
			if (actualCharge_ < 0)//si llega al mínimo, setea
				actualCharge_ = 0;
		}
	}
	light_->setDistance(distance_* actualCharge_);
	if(actualCharge_>0.5)
		progressBar_->setProperty("ProgressColour", "FF00FF00");
	else if(actualCharge_>0.1)
		progressBar_->setProperty("ProgressColour", "FFFFFF00");
	else
		progressBar_->setProperty("ProgressColour", "FFFF0000");
	progressBar_->setProgress(actualCharge_);

}

void Lighter::start()
{
	light_ = entity_->getComponent<Light>();
	distance_ = light_->getDistance();
	pM_ = entity_->getComponent<PlayerMovement>();
	progressBar_ = entity_->getComponent<ProgressBar>();
}
