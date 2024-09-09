#include "game.h"

void Game::Update()
{
    uiManager.Update(GAMESTATE);
    uiManager.Draw();
}