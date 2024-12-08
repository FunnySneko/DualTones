#include "object2D.h"

Object2D::Object2D(PIVOT_ALIGMENT pivotAligment)
{
    
}

void Object2D::SetPosition(Vector2 position)
{
    this->position = position;
}

void Object2D::SetScale(float scale)
{
    this->scale = scale;
}

Vector2 Object2D::GetPosition()
{
    return position;
}

float Object2D::GetScale()
{
    return scale;
}

Vector2 Object2D::GetDimensions()
{
    return dimensions;
}

PIVOT_ALIGMENT Object2D::GetPivotAligment()
{
    return pivotAligment;
}

void Sprite::Draw(Vector2 absPosition, float absScale)
{
    DrawTextureEx(image,absPosition,0,absScale,WHITE);
}

void Sprite::CalculateDimensions()
{
    dimensions = {image.width * scale, image.height * scale};
}

void TextObject::Draw(Vector2 absPosition, float absScale)
{
    
}

void TextObject::CalculateDimensions()
{
    dimensions = {MeasureTextEx(font,text.c_str(),fontSize,spacing)};
}

void TextObject::SetText(std::string text)
{
    this->text = text;
}

std::vector<IObject2D> Object2DContainer::GetObjects()
{
    return objects;
}

void Object2DContainer::AddObject(IObject2D object)
{
    objects.push_back(object);
}

TextObject::TextObject(std::string text)
{
    this->text = text;
}
