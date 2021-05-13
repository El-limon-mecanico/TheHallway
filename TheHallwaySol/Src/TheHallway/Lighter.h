#include "Component.h"


class Lighter : public Component {
protected:

private:
	float actualCharge_;

public:
	Lighter() {}
	~Lighter() {}

	virtual bool init(luabridge::LuaRef parameterTable = { nullptr })override;
	static std::string GetName() { return "Lighter"; }
	void charge();
	void update() override;
};