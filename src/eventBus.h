#pragma once
#include <string>
#include <unordered_map>
#include <vector>
#include <functional>

class Event
{
    std::string type;
    std::string data;

    Event(const std::string& type, const std::string& data);
};

class EventBus
{
private:
    
public:
    
};