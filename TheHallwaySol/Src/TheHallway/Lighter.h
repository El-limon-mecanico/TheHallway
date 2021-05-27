#include "Component.h"
class Light;
class PlayerMovement;
class AudioSource;
class ProgressBar;
class Lighter : public Component {
protected:

private:
	float chargeSpeed_=0;
	float dischargeSpeed_=0;
	float actualCharge_=0; //de 0 a 1
	float distance_=0; 
	Light* light_=nullptr;
	PlayerMovement* pM_=nullptr;
	AudioSource* sound_=nullptr;
	ProgressBar* progressBar_=nullptr;
public:
	Lighter() : actualCharge_(1) {};
	~Lighter() {};
	virtual bool init(luabridge::LuaRef parameterTable = { nullptr })override;

	static std::string GetName() { return "Lighter"; }

	virtual void update();
	virtual void start();
};