#include "object2D.h"

SingleCharacter::SingleCharacter(std::string character)
{
    this->character = character;
}

void SingleCharacter::Draw()
{
    DrawTextEx(GetFontDefault(),character.c_str(),position,14,0,WHITE);
}

TextAnimated::TextAnimated()
{
    typing = LoadSound("../assets/switch.mp3");
}

void TextAnimated::Draw()
{
    for(auto& character : characters)
    {
        character.Draw();
    }
}

void TextAnimated::PushCharacter(std::string character)
{
    if(character == ".")
    {
        FlushLine();
    }
    else
    {
        PlaySound(typing);
        characters.push_back(SingleCharacter(character));
        UpdateCharacterPositions();
    }
}

void TextAnimated::UpdateCharacterPositions()
{
    float textWidth = MeasureTextEx(GetFontDefault(),displayedLine.c_str(),14,2).x;
    space = 0;

    for(auto& character : characters)
    {
        shakeDirection = {float(GetRandomValue(-1,1)),float(GetRandomValue(-1,1))};
        character.position.x = position.x + space + shakeDirection.x - textWidth/2;
        character.position.y = position.y + shakeDirection.y;
        space += MeasureTextEx(GetFontDefault(),character.character.c_str(),GetFontDefault().baseSize,0).x + 6; 
    }
}

void TextAnimated::FlushLine()
{
    characters.clear();
    displayedLine = "";
}