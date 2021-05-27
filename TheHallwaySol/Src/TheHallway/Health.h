#pragma once
#include "Component.h"
class AudioSource;
class QuackEntity;
class Health : public Component {
private:
	int lives_;
	Vector3D initialPos_;
	std::vector<QuackEntity*> hearts_;
	const int HEART_SIZE = 64;
	int WINDOW_WIDTH;
	AudioSource* scream_ = nullptr;
public:
	Health() {};
	~Health() { hearts_.clear(); };
	virtual bool init(luabridge::LuaRef parameterTable = { nullptr }) override;
	static std::string GetName() { return "Health"; }
	virtual void start();
	void hit();
	virtual void onTriggerEnter(QuackEntity* other, Vector3D point);
};