#include "Component.h"


class MinimapController : public Component {
protected:

private:

	bool active_ = false;
	Transform* player_ = nullptr;

public:
	MinimapController() {}
	~MinimapController() {}

	virtual bool init(luabridge::LuaRef parameterTable = { nullptr })override;

	static std::string GetName() { return "MinimapController"; }

	void start() override;
	void update() override;
};