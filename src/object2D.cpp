#include "object2D.h"

SingleCharacter::SingleCharacter(std::string character)
{
    this->character = character;
}

void SingleCharacter::Draw()
{
    DrawTextEx(GetFontDefault(),character.c_str(),position,14,0,WHITE);
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
    float textWidth = MeasureTextEx(GetFontDefault(),displayedLine.c_str(),14,4).x;
    float textHeight = MeasureTextEx(GetFontDefault(),displayedLine.c_str(),14,4).y;
    space = 0;

    for(auto& character : characters)
    {
        character.position.x = position.x + space - textWidth/2;
        character.position.y = position.y + textHeight / 2;
        space += MeasureTextEx(GetFontDefault(),character.character.c_str(),14,0).x + 4;
    }

    textBoundaries = {position.x-textWidth/2,position.y+textHeight/2,textWidth,textHeight};
}

void TextAnimated::FlushLine()
{
    characters.clear();
    displayedLine.clear();
}