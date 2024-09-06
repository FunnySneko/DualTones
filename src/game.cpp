#include "game.h"

void Game::Update()
{
    textAnimated.position = {float(GetScreenWidth())/2,float(GetScreenHeight())/2};
    float currentTime = GetTime();
    if(currentTime - lastTimeUpdated >= 0.1)
    {
        textAnimated.displayedLine += newLine[index];
        textAnimated.PushCharacter(std::string(1, newLine[index]));
        index++;
        lastTimeUpdated = currentTime;
    }
    textAnimated.Draw();
}