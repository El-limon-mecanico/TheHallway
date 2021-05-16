#include "LoopMovement.h"
#include "Transform.h"


bool LoopMovement::init(luabridge::LuaRef parameterTable)
{
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
void LoopMovement::moveWithPhysics(){

}
void LoopMovement::moveWithoutPhysics(){
    Vector3D v = objectives_[actualObjective_] - transform->position();
    v = v.normalize()*speed_;
    transform->Translate(v,false);
}
void LoopMovement::move(bool p){
    if (p) 
        moveWithPhysics();
    else
    moveWithoutPhysics();
}

void LoopMovement::update(){
    move(false);
        updateObjective();
}