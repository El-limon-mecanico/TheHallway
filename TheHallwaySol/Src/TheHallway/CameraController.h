#include "Component.h"


class CameraController : public Component {
protected:

private:
	Vector3D deltaPos;
	float wheelPos = 0;

public:
	CameraController() {}
	~CameraController() {}

	virtual bool init(luabridge::LuaRef parameterTable = { nullptr })override;

	static std::string GetName() { return "CameraController"; }

	void start() override;
	void updateLookAt();
	void update() override;
};