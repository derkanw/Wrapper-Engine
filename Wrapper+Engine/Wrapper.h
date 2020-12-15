#pragma once
#include <functional>
#include <vector>
#include <map>
#include <string>

class Wrapper
{
private:
    std::map<std::string, int> regArgs;
    std::function<int(const std::vector<int>&)> function;

    std::vector<int> ExtractArgs(const std::map<std::string, int>& args);

    template<typename Subject, typename Function, size_t... Indexes>
    static int CallFunction(Subject* subject, Function someFunction, const std::vector<int>& extractArgs, std::index_sequence<Indexes...>)
    {
        return ((subject->*someFunction)(extractArgs[Indexes]...));
    }

public:
    template<typename Subject, typename... Args>
    Wrapper(Subject* subject, int (Subject::* someFunction)(Args...), const std::map<std::string, int>& args)
    {
        if (subject == nullptr || someFunction == nullptr || args.size() != sizeof...(Args))
            return;
        regArgs = args;

        function = [subject, someFunction](const std::vector<int>& extractArgs)
        {
            return CallFunction(subject, someFunction, extractArgs, std::make_index_sequence<sizeof...(Args)>{});
        };
    }

    int operator() (const std::map<std::string, int>& args)
    {
        if (args.empty())
            return function(ExtractArgs(regArgs));
        return function(ExtractArgs(args));
    }
};