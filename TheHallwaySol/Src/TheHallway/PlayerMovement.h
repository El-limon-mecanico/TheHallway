#include "Component.h"



class PlayerMovement : public Component {
protected:

private:
	float speed_;

public:
	PlayerMovement() {}
	~PlayerMovement() {}

	virtual bool init(luabridge::LuaRef parameterTable = { nullptr }) override;

	static std::string GetName() { return "PlaterMovement"; }

	void move();
	void update() override;
};