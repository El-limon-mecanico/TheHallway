#pragma once
#include "Component.h"
#include "InputManager.h"

class Lever : public Component
{
private:
    float total_ = 10;
    float progress_ = 0;
    bool player_ = true;
    bool charged_ = true;
    SDL_Scancode chargingButton_ = SDL_SCANCODE_SPACE;


public:
    Lever() {}
    ~Lever() {}

    void setButton(SDL_Scancode b) { chargingButton_ = b; }
    void setTotal(float t) { total_ = t; }
    float getProgress() const { return progress_; }

    virtual bool init(luabridge::LuaRef parameterTable = { nullptr }) { return true; }
    virtual void update();
    virtual void onCollisionEnter(QuackEntity* other, Vector3D point);
    virtual void onCollisionExit(QuackEntity* other, Vector3D point);

    static std::string GetName() { return "Lever"; }
};

