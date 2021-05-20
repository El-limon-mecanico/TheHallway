#include "PlayerMovement.h"
#include "InputManager.h"
#include "Transform.h"
#include "QuackEntity.h"
#include "Rigidbody.h"

bool PlayerMovement::init(luabridge::LuaRef parameterTable)
{
    return true;
}

void PlayerMovement::move() {
    entity_->getComponent<Rigidbody>()->setVelocity(Vector3D(InputManager::Instance()->getAxis(Horizontal) * 50, 0, InputManager::Instance()->getAxis(Vertical)*50));
}

void PlayerMovement::update(){
    move();
}
