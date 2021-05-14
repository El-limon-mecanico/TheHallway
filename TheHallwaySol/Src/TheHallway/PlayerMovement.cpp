#include "PlayerMovement.h"



bool PlayerMovement::init(luabridge::LuaRef parameterTable)
{
    return true;
}

void PlayerMovement::move(){
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
}

void PlayerMovement::update(){
    move();
}