#include "Component.h"
class Light;
class PlayerMovement;
class Lighter : public Component {
protected:

private:
	float chargeSpeed_;
	float dischargeSpeed_;
	float actualCharge_; //de 0 a 1
	Light* light_;
	PlayerMovement* pM_;

public:
	Lighter() : actualCharge_(1) {};
	~Lighter() {};
	virtual bool init(luabridge::LuaRef parameterTable = { nullptr })override;

	static std::string GetName() { return "Lighter"; }

	virtual void update();
	virtual void start();
};