#include "Health.h"
#include "QuackEntity.h"
bool Health::init(luabridge::LuaRef parameterTable)
{
	lives_ = readVariable<int>(parameterTable, "MaxLives");
	return true;
}

void Health::start()
{
	initialPos_ = entity_->transform()->position();
}

void Health::hit()
{
	lives_--;
	if (lives_ > 0) {
		entity_->transform()->setGlobalPosition(initialPos_);
		//quitar una de las tres vidas de la UI
	}
	else {
		//pasar a pantalla de game Over
	}

}


