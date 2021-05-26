#include <vector>
#include "Component.h"
#include "Vector3D.h"
class Rigidbody;

class ChasePlayer : public Component {
protected:

private:
	Transform* playerTr_ = nullptr;
	Rigidbody* rb_ = nullptr;

	float speed_ = 10;
	float maxDistance_ = 25;
	Vector3D direction_ = Vector3D({ 0,0,0 });
public:
	ChasePlayer(float speed = 0): speed_(speed) {}
	~ChasePlayer() {}
	void setTriggerDistance(float d) { maxDistance_ = d; }
	void getPlayer();
	virtual bool init(luabridge::LuaRef parameterTable = { nullptr }) override;
	void start() override;
	void update() override;
	virtual void onTriggerEnter(QuackEntity* other, Vector3D point);
	virtual void onDisable();

	static std::string GetName() { return "ChasePlayer"; }
};