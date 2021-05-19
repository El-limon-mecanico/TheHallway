#include "LoopMovement.h"
#include "Transform.h"
#include "QuackEntity.h"
#include "Rigidbody.h"
bool LoopMovement::init(luabridge::LuaRef parameterTable)
{
	LuaRef speed = readVariable<LuaRef>(parameterTable, "Speed");
	speed_ = speed;
	LuaRef ob = readVariable<LuaRef>(parameterTable, "Objectives");
	std::cout << ob.length() << "\n";
	for (size_t i = 1; i <= ob.length(); i++)
	{
		Vector3D v;
		v.x = ob[i][1];
		v.y = ob[i][2];
		v.z = ob[i][3];
		objectives_.push_back(v);
	}
	return true;
}

void LoopMovement::updateObjective() {
	bool update = false;

	Vector3D distance = objectives_[actualObjective_] - transform->position();
	update = (distance.magnitude() <= 1);

	if (update) {
		actualObjective_ = (actualObjective_ + 1) % (objectives_.size());
		transform->lookAt(objectives_[actualObjective_]);
		updateVelocity();
	}
}

void LoopMovement::updateVelocity()
{
	assert(rb_);
	rb_->setVelocity(transform->forward * speed_);
}
void LoopMovement::start()
{
	assert(entity_->hasComponent<Rigidbody>());
	rb_ = entity_->getComponent<Rigidbody>();
	rb_->setGravity({ 0,0,0 });
	transform->lookAt(objectives_[actualObjective_]);
	updateVelocity();
}
void LoopMovement::update() {
	updateObjective();
}