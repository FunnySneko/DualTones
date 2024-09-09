#include "game.h"
#include "object2D.h"


int main()
{

    SetConfigFlags(FLAG_WINDOW_RESIZABLE);
    InitAudioDevice();
    InitWindow(1280,720,"NICEGG");
    SetTargetFPS(60);
    //ToggleFullscreen();
    Game game;
    while(!WindowShouldClose())
    {
        BeginDrawing();
        ClearBackground(WHITE);

        game.Update();

        EndDrawing();
    }
}