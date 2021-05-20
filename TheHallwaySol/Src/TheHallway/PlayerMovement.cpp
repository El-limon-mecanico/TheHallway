#include "PlayerMovement.h"
#include "InputManager.h"
#include "Transform.h"
#include "Rigidbody.h"
#include "QuackEntity.h"
#include "QuackEnginePro.h"
#include <iostream>

bool PlayerMovement::init(luabridge::LuaRef parameterTable)
{
    walkingSpeed_ = readVariable<LuaRef>(parameterTable, "WalkingSpeed");
    runningSpeed_ = readVariable<LuaRef>(parameterTable, "RunningSpeed");
    cameraXSpeed_ = readVariable<LuaRef>(parameterTable, "cameraXSpeed");
    cameraYSpeed_ = readVariable<LuaRef>(parameterTable, "cameraYSpeed");

    rb_ = entity_->getComponent<Rigidbody>();

    InputManager::Instance()->captureMouse();

    return true;
}

void PlayerMovement::rotate()
{
    mouseDeltaX_ =  InputManager::Instance()->getMousePositionRelative().x - 0.5;
    mouseDeltaY_ = InputManager::Instance()->getMousePositionRelative().y - 0.5;

    transform->Rotate(Vector3D(mouseDeltaY_ * 0.0 * cameraYSpeed_, -mouseDeltaX_ * 1 * cameraXSpeed_, 0));

    //if (transform->rotation().x > 70) transform->setLocalRotation(Vector3D(70, transform->rotation().y, 0));
    //if (transform->rotation().x < -80) transform->setLocalRotation(Vector3D(-80, transform->rotation().y, 0));

    std::cout << "Rotation: " << transform->rotation() << "\n";
}

void PlayerMovement::move() {

    float speed_;

    if (InputManager::Instance()->getKey(SDL_SCANCODE_LSHIFT)) speed_ = runningSpeed_ * QuackEnginePro::Instance()->time()->deltaTime();
    else speed_ = walkingSpeed_ * QuackEnginePro::Instance()->time()->deltaTime();


    if (InputManager::Instance()->getKey(SDL_SCANCODE_A)) rb_->setVelocity(Vector3D(transform->right.x * speed_, 0, transform->right.z * speed_));

    if (InputManager::Instance()->getKey(SDL_SCANCODE_D)) rb_->setVelocity(Vector3D(transform->right.x * -speed_, 0, transform->right.z * -speed_));

    if (InputManager::Instance()->getKey(SDL_SCANCODE_S)) rb_->setVelocity(Vector3D(transform->forward.x * -speed_, 0, transform->forward.z * -speed_));

    if (InputManager::Instance()->getKey(SDL_SCANCODE_W)) rb_->setVelocity(Vector3D(transform->forward.x * speed_, 0, transform->forward.z * speed_));
}

void PlayerMovement::update() {
    rotate();
    move();
}