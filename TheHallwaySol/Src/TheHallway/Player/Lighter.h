#include "Component.h"


class Lighter : public Component {
protected:

private:
	float actualCharge_;

public:
	Lighter() {}
	~Lighter() {}

	virtual bool init(luabridge::LuaRef parameterTable = { nullptr })override;
	void charge();
	void update() override;
};