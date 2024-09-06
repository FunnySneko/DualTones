#pragma once
#include "raylib/raylib.h"
#include <string>
#include <vector>
#include <iostream>

class Object2D
{
public:
    Vector2 position;
    float scale = 1.0;
};

class SingleCharacter : public Object2D
{
public:
    SingleCharacter(std::string character);
    void Draw();
    std::string character;
};

class TextAnimated : public Object2D
{
public:
    void Draw();
    void PushCharacter(std::string character);
    void UpdateCharacterPositions();
    void FlushLine();
    std::vector<SingleCharacter> characters;
    std::string displayedLine;
    Font fontRegular;
    Font fontAlternative;
    std::vector<Font> additionalFonts;
    Vector2 shakeDirection;
};