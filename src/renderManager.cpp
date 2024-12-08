#include "renderManager.h"

void RenderManager::Update()
{

}

void RenderManager::RenderObject2D(Object2D& object)
{
    Vector2 dimensions = Vector2Scale(object.GetDimensions(), displayManager->GetScale());
    Vector2 pivotOffset;
    switch(object.GetPivotAligment())
    {
        case PIVOT_ALIGMENT::CENTER:
            pivotOffset = {dimensions.x / 2 * (-1), dimensions.y / 2 * (-1)};
            break; 
    }
    Vector2 absPosition = Vector2Add(displayManager->GetCoordinates(object.GetPosition()), pivotOffset);
    float absScale = displayManager->GetScale() * object.GetScale();
    object.Draw(absPosition, absScale);
}