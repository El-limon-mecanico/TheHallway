#pragma once
#include "Component.h"

class MazeManager;

class Lever : public Component
{
private:
    float total_ = 10;
    float progress_ = 0;
    float chargingVel_ = 1;
    float unchargingVel_ = 1;

    bool player_ = false;
    bool charged_ = false;

    MazeManager* mazeMng_ = nullptr;

public:
    Lever() {}
    ~Lever() {}

    void setTotal(float t) { total_ = t; }
    float getProgress() const { return progress_; }
    void setChargingVel(float v) { chargingVel_ = v; }
    void setUnchargingVel(float v) { unchargingVel_ = v; }
    void setMazeMng(MazeManager* mng) { mazeMng_ = mng; }

    virtual bool init(luabridge::LuaRef parameterTable = { nullptr }) { return true; }
    virtual void update();
    virtual void onTriggerEnter(QuackEntity* other, Vector3D point);
    virtual void onTriggerExit(QuackEntity* other, Vector3D point);
    virtual void onDisable();

    static std::string GetName() { return "Lever"; }
};

