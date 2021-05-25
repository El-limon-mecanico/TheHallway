#pragma once
#include "Component.h"
class ProgressBar;
class MazeManager;

class Lever : public Component
{
private:
    float total_;
    float progress_ = 0;
    float chargingVel_;
    float unchargingVel_;

    bool player_ = false;
    bool charged_ = false;

    MazeManager* mazeMng_ = nullptr;
    ProgressBar* pb_ = nullptr;
public:
    Lever() {}
    ~Lever() {}

    void setTotal(float t) { total_ = t; }
    float getProgress() const { return progress_; }
    void setChargingVel(float v) { chargingVel_ = v; }
    void setUnchargingVel(float v) { unchargingVel_ = v; }
    void setMazeMng(MazeManager* mng) { mazeMng_ = mng; }

    virtual bool init(luabridge::LuaRef parameterTable = { nullptr });
    virtual void update();
    virtual void onTriggerEnter(QuackEntity* other, Vector3D point);
    virtual void onTriggerExit(QuackEntity* other, Vector3D point);
    virtual void onDisable();
    virtual void start() override;
    static std::string GetName() { return "Lever"; }
};

