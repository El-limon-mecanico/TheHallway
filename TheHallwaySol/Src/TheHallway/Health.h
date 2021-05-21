#pragma once
#include "Component.h"
class QuackEntity;
class Health : public Component {
private:
	int lives_;
	Vector3D initialPos_;
	std::vector<QuackEntity*> hearts_;
	QuackEntity* player_;
	const int HEART_SIZE = 64;
	int WINDOW_WIDTH;
public:
	Health() {};
	~Health() { hearts_.clear(); };
	virtual bool init(luabridge::LuaRef parameterTable = { nullptr }) override;
	static std::string GetName() { return "Health"; }
	virtual void start();
	virtual void update();
	void hit();
};