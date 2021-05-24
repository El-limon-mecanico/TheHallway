#include "Component.h"


class CameraController : public Component {
protected:

private:
	float cameraSpeed_, yAngle_ = 0;

public:
	CameraController() {}
	~CameraController() {}

	virtual bool init(luabridge::LuaRef parameterTable = { nullptr })override;

	static std::string GetName() { return "CameraController"; }

	void start() override;
	void update() override;
	void setCameraSpeed(float speed);
};