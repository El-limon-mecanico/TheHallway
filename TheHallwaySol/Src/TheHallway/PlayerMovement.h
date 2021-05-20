#include "Component.h"

class Rigidbody;

class PlayerMovement : public Component {
protected:

private:
	float walkingSpeed_, runningSpeed_, cameraXSpeed_, cameraYSpeed_, mouseDeltaX_ = 0, mouseDeltaY_ = 0;
	Rigidbody* rb_;
	bool moving_ = false;

public:
	PlayerMovement() {}
	~PlayerMovement() {}

	virtual bool init(luabridge::LuaRef parameterTable = { nullptr }) override;

	static std::string GetName() { return "PlayerMovement"; }

	void start() override;
	void rotate();
	void move();
	void update() override;
};