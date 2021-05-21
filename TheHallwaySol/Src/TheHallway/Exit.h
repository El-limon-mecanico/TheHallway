#pragma once
#include "Component.h"
#include "InputManager.h"

//class QuackEntity;

class Exit : public Component
{
private:
    bool finish_ = false;

public:
    Exit() {}
    ~Exit() {}

    virtual bool init(luabridge::LuaRef parameterTable = { nullptr }) { return true; }
    virtual void onTriggerEnter(QuackEntity* other, Vector3D point);
    static std::string GetName() { return "Exit"; }
};

