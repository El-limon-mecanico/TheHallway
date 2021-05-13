#include "LoopMovement.h"
#include "Transform.h"


bool LoopMovement::init(luabridge::LuaRef parameterTable)
{
    return true;
}
void LoopMovement::updateObjective() {
    bool update = false;

     update = objectives_[actualObjective_].x-transform->position().x >= -1 && objectives_[actualObjective_].x- transform->position().x <= 1;
     update = update && objectives_[actualObjective_].y-transform->position().y >= -1 && objectives_[actualObjective_].y- transform->position().y <= 1;
   update = update && objectives_[actualObjective_].z- transform->position().z >= -1 &&  objectives_[actualObjective_].z- transform->position().z <= 1;

    if (update) {
        actualObjective_ = (actualObjective_ + 1) % (objectives_.size());
        std::cout << "UPDATE" << std::endl;
    std::cout << "(" << transform->position().x << "," << transform->position().y << "," << transform->position().z << ")" << std::endl;
    }
}
void LoopMovement::moveWithPhysics(){

}
void LoopMovement::moveWithoutPhysics(){
    Vector3D v = objectives_[actualObjective_] - transform->position();
    v.z = objectives_[actualObjective_].z- transform->position().z;//Cuando se corriga el operator - se puede quitar esta linea
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
        std::cout << "(" << transform->position().x << "," << transform->position().y << "," << transform->position().z << ")" << std::endl;
}