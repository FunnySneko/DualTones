#include "uiManager.h"

DialogueManager::DialogueManager(float defaultTextSpeed, int TEXT_ALIGMENT, Font defaultFont, Font alternativeFont)
{
    this->defaultTextSpeed = defaultTextSpeed;
    this->TEXT_ALIGMENT = TEXT_ALIGMENT;
    this->defaultFont = defaultFont;
    this->alternativeFont = alternativeFont;
}

void DialogueManager::Update()
{
    dialogueText.Update();
}

void DialogueManager::Draw()
{
    dialogueText.Draw();
}

void UIManager::Update(int GAMESTATE)
{
    this->GAMESTATE = GAMESTATE;
    
    for(auto& uiObjectArray : uiObjects)
    {
        for(auto& uiObject : uiObjectArray)
        {
            uiObject.Update();
        }
    }
}

void UIManager::Draw()
{
    for(auto& uiObjectArray : uiObjects)
    {
        for(auto& uiObject : uiObjectArray)
        {
            uiObject.Draw();
        }
    }
}