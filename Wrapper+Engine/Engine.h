#pragma once
#include <map>
#include <string>
#include "Wrapper.h"

class Engine
{
private:
    std::map<std::string, Wrapper*> regMap;

public:
    Engine(void) = default;

    void RegisterCommand(Wrapper* wrapper, const std::string& commandName);
    int Execute(const std::string& commandName, const std::map<std::string, int>& args);
};