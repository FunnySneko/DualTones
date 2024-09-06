#pragma once
#include <vector>
#include "object2D.h"
#include <iostream>

class Game
{
public:
    void HandleInput();
    void Update();
    TextAnimated textAnimated;
    std::string newLine = "I'm walking through the empty streets. The sky is gray. The wind whispers softly. I hear my footsteps echo. The world feels distant. Like a dream, almost. Everything seems slower today. People pass by, but they're like shadows. I feel detached. I wonder if they feel the same. Do they notice me? Probably not. I'm just another face. Another figure in the crowd. But that's okay. I like it this way. Being invisible has its perks. No one expects anything. No one asks questions. It's peaceful. Almost serene. But deep down, there's a storm. A quiet one. It stirs, slowly. But it never breaks. Maybe someday it will. Maybe then things will change. But for now, I'll keep walking. I'll keep fading into the background. Until I reach the end of the street. Then, maybe I'll wake up.";
    int index = 0;
    float lastTimeUpdated = 0;
};