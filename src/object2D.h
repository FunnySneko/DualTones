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
    RIGHT_BOTTOM,
    LEFT,
    RIGHT,
    TOP,
    BOTTOM
};

class IObject2D
{
public:

protected:
    Vector2 position;
    float scale;
};

class Object2D : public IObject2D
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
    Vector2 dimensions;
private:
    PIVOT_ALIGMENT pivotAligment;
};

class Object2DContainer : public IObject2D
{
public:
    std::vector<IObject2D> GetObjects();
    void AddObject(IObject2D object);
private:
    std::vector<IObject2D> objects;
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

private:
    float speed;
    std::vector<Texture2D> images;
};

class TextObject : public Object2D
{
public:
    TextObject(std::string text);
    void Draw(Vector2 absPosition, float absScale) override;
    void CalculateDimensions() override;
    void SetText(std::string text);
private:
    std::string text;
    Font font;
    float fontSize;
    float spacing;
};