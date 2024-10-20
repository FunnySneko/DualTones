#pragma once
#include "raylib/raylib.h"
#include "raylib/raymath.h"
#include <algorithm>

class DisplayManager
{
public:
    DisplayManager(Vector2 referenceResolution, Vector2 relativeCoordinates);
    void Update();
    void GetResolution();
    void CalculateScale();
    float GetScale();
    Vector2 GetCoordinates(Vector2 position);
private:
    Vector2 referenceResolution;
    Vector2 resolution;
    Vector2 halfResolution;
    Vector2 relativeCoordinates;
    float relativeScaleX;
    float relativeScaleY;
    float scale;
};