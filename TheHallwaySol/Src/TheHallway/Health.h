#pragma once
#include "Component.h"
class QuackEntity;
class Health : public Component {
private:
	int lives_;
	Vector3D initialPos_;
public:
	Health() {};
	~Health() {};
	virtual bool init(luabridge::LuaRef parameterTable = { nullptr }) override;
	static std::string GetName() { return "Health"; }
	virtual void start();

	void hit();
};