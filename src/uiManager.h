#pragma once
#include <vector>
#include "object2D.h"

class UIManager
{
public:

private:
    std::vector<IObject2D> uiObjects;
};

class DialogueManager
{
public:
    void PushCharacter();
private:
    Object2DContainer text;
};