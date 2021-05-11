#include "LoopMovement.h"
#include "Transform.h"


bool LoopMovement::init(luabridge::LuaRef parameterTable)
{
    return true;
}
void LoopMovement::updateObjective() {
    actualObjective = (actualObjective + 1) % (objectives.size());
}
void LoopMovement::moveWithPhysics(){

}
void LoopMovement::moveWithoutPhysics(){
    transform->Translate(objectives[actualObjective],false);
}
void LoopMovement::move(bool p){
   /* if(hayTeclaBajada){
        switch(teclaBajada){
            case W:{
                tr_->setPos(tr->getPos()+Vector3D(0,speed_,0));
            }
            break;
            case S:{
                tr_->setPos(tr->getPos()+Vector3D(0,-speed_,0));
            }
            break;
            case A:{
                tr_->setPos(tr->getPos()+Vector3D(speed_,0,0));
            }
            break;
            case D:{
                tr_->setPos(tr->getPos()+Vector3D(-speed_,0,0));
            }
            break;
            default:
            break;
        }
    }*/
    if (p) 
        moveWithPhysics();
    else
    moveWithoutPhysics();
}

void LoopMovement::update(){
    move(false);
    if (transform->position().x == objectives[actualObjective].x&& transform->position().y == objectives[actualObjective].y&& transform->position().z == objectives[actualObjective].z)
        updateObjective();
}