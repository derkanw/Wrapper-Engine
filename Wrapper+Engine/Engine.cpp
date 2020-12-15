#include "Engine.h"

void Engine::RegisterCommand(Wrapper* wrapper, const std::string& commandName)
{
    if (wrapper == nullptr)
        return;
    regMap.insert(std::pair<std::string, Wrapper*>(commandName, wrapper));
}

int Engine::Execute(const std::string& commandName, const std::map<std::string, int>& args)
{
    Wrapper* wrapper = regMap.at(commandName);
    return (*wrapper)(args);
}