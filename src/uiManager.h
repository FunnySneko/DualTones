#pragma once
#include <vector>
#include <string>
#include "raylib/raylib.h"
#include "object2D.h"

const int DIALOGUE_MANAGER = 0;
const int DECORATIVE_TEXT = 1;
const int DECORATIVE_TEXTURE = 2;

const int GAME_PAUSED = 0;
const int GAME_WAITING_FOR_INTERACTION = 1;
const int GAME_DISPLAYING_TEXT = 2;
const int GAME_UPDATING_TEXT = 3;

class UIObject
{
public:
    virtual void Update() = 0;
    virtual void Draw() = 0;
    virtual ~UIObject() = default;
};

class DialogueManager : public UIObject
{
public:
    DialogueManager(float defaultTextSpeed, int TEXT_ALIGMENT, Font defaultFont, Font alternativeFont);
    void Update();
    void Draw();
private:
    TextAnimated dialogueText;
    std::string displayedText;
    std::string newText;
    float defaultTextSpeed;
    int TEXT_ALIGMENT;
    Font defaultFont;
    Font alternativeFont;
    float fontSize;
    float fontSpacing;
};

class DecorativeText : public UIObject
{
public:
    void Update();
    void Draw();
private:
    std::string text;
    int TEXT_ALIGMENT;
};

class UIManager
{
public:
    void Update(int GAMESTATE);
    void Draw();
    void UpdateDialogueText(std::string text, int dialogueManagerID, float speed = 1.0);
    void ShakeUI();
private:
    std::vector<UIObject> uiObjects[3];
    int GAMESTATE;
};
