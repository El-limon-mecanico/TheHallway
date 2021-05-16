#include "LoopMovement.h"
#include "Transform.h"


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

     update = objectives_[actualObjective_].x-transform->position().x >= -speed_ && objectives_[actualObjective_].x- transform->position().x <= speed_;
     update = update && objectives_[actualObjective_].y-transform->position().y >= -speed_ && objectives_[actualObjective_].y- transform->position().y <= speed_;
     update = update && objectives_[actualObjective_].z- transform->position().z >= -speed_ &&  objectives_[actualObjective_].z- transform->position().z <= speed_;

    if (update) {
        actualObjective_ = (actualObjective_ + 1) % (objectives_.size());
    }
}

void LoopMovement::move(){
    Vector3D v = objectives_[actualObjective_] - transform->position();
    v = v.normalize()*speed_;
    transform->Translate(v, true);
}

void LoopMovement::update(){
    move();
    updateObjective();
}