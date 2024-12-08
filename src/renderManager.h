#pragma once
#include "raylib/raylib.h"
#include "object2D.h"
#include "displayManager.h"

class RenderManager
{
public:
    void Update();
    void RenderObject2D(Object2D& object);
private:
    DisplayManager* displayManager;
};