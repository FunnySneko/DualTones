#include "object2D.h"

SingleCharacter::SingleCharacter(std::string character)
{
    this->character = character;
}

void SingleCharacter::Draw()
{
    DrawTextEx(GetFontDefault(),character.c_str(),position,GetFontDefault().baseSize,0,WHITE);
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
        characters.push_back(SingleCharacter(character));
        UpdateCharacterPositions();
    }
}

void TextAnimated::UpdateCharacterPositions()
{
    float textWidth = MeasureTextEx(GetFontDefault(),displayedLine.c_str(),GetFontDefault().baseSize,2).x;
    float space = 0;
    shakeDirection = {float(GetRandomValue(-1,1)),float(GetRandomValue(-1,1))};

    for(auto& character : characters)
    {
        character.position.x = position.x + space + shakeDirection.x;
        character.position.y = position.y + shakeDirection.y;
        space += MeasureTextEx(GetFontDefault(),character.character.c_str(),GetFontDefault().baseSize,0).x + 2; 
    }
}

void TextAnimated::FlushLine()
{
    characters.clear();
}