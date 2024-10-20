#pragma once
#include <string>
#include <vector>
#include "raylib/raylib.h"

enum class PIVOT_ALIGMENT
{
    CENTER,
    LEFT_TOP,
    RIGHT_TOP,
    LEFT_BOTTOM,
    RIGHT_BOTTOM
};

class Object2D
{
public:
    Object2D(PIVOT_ALIGMENT pivotAligment = PIVOT_ALIGMENT::CENTER);
    virtual void Draw(Vector2 absPosition, float absScale) = 0;
    void SetPosition(Vector2 position);
    void SetScale(float scale);
    virtual void CalculateDimensions() = 0;
    Vector2 GetPosition();
    float GetScale();
    Vector2 GetDimensions();
    PIVOT_ALIGMENT GetPivotAligment();
protected:
    float scale;
    Vector2 dimensions;
private:
    PIVOT_ALIGMENT pivotAligment;
    Vector2 position;
};

class Sprite : public Object2D
{
public:
    void Draw(Vector2 absPosition, float absScale) override;
    void CalculateDimensions() override;
protected:
    Texture2D image;
};

class SpriteAnimated : public Sprite
{
public:
    void SetFrame();
private:
    float speed;
    std::vector<Texture2D> images;
};

class Text : public Object2D
{
public:
    void SetText();
private:
    std::string text;
};
