#include "Lighter.h"

void Lighter::init(){
    if(entity_->hasComponent("Transform"))
        entity_->getComponent("Transform");
}

void Lighter::charge(){

}

void Lighter::update(){
    move();
}