#include "Component.h"
#include <vector>
#include "Vector3D.h"
class LoopMovement : public Component {
protected:

private:
	float speed_;
	std::vector<Vector3D> objectives_;
	int actualObjective_;
	void updateObjective();
	void moveWithPhysics();
	void moveWithoutPhysics();
public:
	LoopMovement(float speed=0,std::vector<Vector3D>objectives=std::vector<Vector3D>(),int next=0):speed_(speed),objectives_(objectives),actualObjective_(next) {}
	~LoopMovement() {}

	virtual bool init(luabridge::LuaRef parameterTable = { nullptr }) override;

	void move(bool physics);
	void update() override;
	static std::string GetName() { return "LoopMovement"; }
};