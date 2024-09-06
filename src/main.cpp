#include "game.h"
#include "object2D.h"

Game game;

int main()
{
    SetTargetFPS(60);

    InitWindow(1280,720,"NICEGG");
    InitAudioDevice();
    while(!WindowShouldClose())
    {
        BeginDrawing();
        ClearBackground(BLACK);

        game.Update();
        std::cout << GetApplicationDirectory() << std::endl;

        EndDrawing();
    }
}