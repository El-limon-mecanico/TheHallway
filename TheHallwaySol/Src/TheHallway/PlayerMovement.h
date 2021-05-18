#include "Component.h"



class PlayerMovement : public Component {
protected:

private:
	float walkingSpeed_, runningSpeed_, cameraXSpeed_, cameraYSpeed_, mousePosX_, mousePosY_, mouseDeltaX_ = 0, mouseDeltaY_ = 0;

public:
	PlayerMovement() {}
	~PlayerMovement() {}

	virtual bool init(luabridge::LuaRef parameterTable = { nullptr }) override;

	static std::string GetName() { return "PlayerMovement"; }

	void rotate();
	void move();
	void update() override;
};