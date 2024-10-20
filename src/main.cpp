#include "raylib/raylib.h"
#include "engine.h"
#include <iostream>

int main()
{

    SetConfigFlags(FLAG_WINDOW_RESIZABLE);
    InitAudioDevice();
    InitWindow(1280,720,"NICEGG");
    SetTargetFPS(60);
    //ToggleFullscreen();
    Engine engine;
    while(!WindowShouldClose())
    {
        BeginDrawing();
        ClearBackground(BLACK);

        engine.Update();

        EndDrawing();
    }
}