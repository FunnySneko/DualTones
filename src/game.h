#pragma once
#include <vector>
#include <iostream>
#include "soundManager.h"
#include "uiManager.h"

const int PAUSED = 0;
const int WAITING_FOR_INTERACTION = 1;
const int DISPLAYING_TEXT = 2;
const int UPDATING_TEXT = 3;

class Game
{
public:
    void HandleInput();
    void Update();
    SoundManager soundManager;
    UIManager uiManager;
private:
    int GAMESTATE;
};