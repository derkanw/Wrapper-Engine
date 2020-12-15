#include "Wrapper.h"

std::vector<int> Wrapper::ExtractArgs(const std::map<std::string, int>& args)
{
    std::vector<int> extractArgs;
    for (auto i = regArgs.begin(); i != regArgs.end(); ++i)
        extractArgs.push_back(args.at(i->first));
    return extractArgs;
}