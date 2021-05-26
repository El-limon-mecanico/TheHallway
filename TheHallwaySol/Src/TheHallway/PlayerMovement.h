#include "Component.h"

class Rigidbody;
class AudioSource;
class PlayerMovement : public Component {
protected:

private:
	float walkingSpeed_;
	float runningSpeed_;
	float cameraSpeed_;
	Rigidbody* rb_;
	bool moving_ = true;
	bool running = false;
	AudioSource* walkSound_ = nullptr;
	AudioSource* runningSound_ = nullptr;
public:
	PlayerMovement() {}
	~PlayerMovement() {}

	virtual bool init(luabridge::LuaRef parameterTable = { nullptr }) override;

	static std::string GetName() { return "PlayerMovement"; }
	virtual void onEnable() override;
	void start() override;
	void rotate();
	void move();
	void update() override;
	void setMoving(bool m) { moving_ = m; };
	bool getMoving() { return moving_; };
};