#pragma once
#include <string>
#include <vector>
#include <unordered_map>

enum class ACTION_TYPE
{
    DIALOGUE_LINE,
};

class Scenario
{
public:

private:
    std::unordered_map<std::string, Script> scripts;
};

class Script
{
public:

private:
    std::vector<Action> actions;
};

class Action
{
public:
    ACTION_TYPE GetType();
    void Execute();
private:
    ACTION_TYPE type;
};

class ActionDialogueLine : public Action
{
    ActionDialogueLine(std::string dialogueLine);
};