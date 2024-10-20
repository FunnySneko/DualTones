#include "displayManager.h"

DisplayManager::DisplayManager(Vector2 referenceResolution, Vector2 relativeCoordinates)
{
    this->referenceResolution = referenceResolution;
    this->relativeCoordinates = relativeCoordinates;
}

void DisplayManager::Update()
{
    GetResolution();
}

void DisplayManager::GetResolution()
{
    Vector2 newResolution;
    newResolution.x = GetScreenWidth();
    newResolution.y = GetRenderHeight();
    if(!Vector2Equals(newResolution, resolution))
    {
        resolution = newResolution;
        halfResolution.x = resolution.x / 2;
        halfResolution.y = resolution.y / 2;
        CalculateScale();
    }
}

void DisplayManager::CalculateScale()
{
    relativeScaleX = resolution.x / relativeCoordinates.x;
    relativeScaleY = resolution.y / relativeCoordinates.y;
    scale = std::min(resolution.x/referenceResolution.x,resolution.y/referenceResolution.y);
}

float DisplayManager::GetScale()
{
    return scale;
}

Vector2 DisplayManager::GetCoordinates(Vector2 position)
{
    return {(position.x * relativeScaleX) + halfResolution.x, (position.y * relativeScaleY) + halfResolution.y};
}