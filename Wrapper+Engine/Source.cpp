#include <iostream>
#include "Engine.h"
#include "Subjects.h"

int main(void)
{
    try
    {
        Engine engine;

        Subject1 subject1;
        Wrapper wrapper1(&subject1, &Subject1::f1, { { "x", 0 }, { "y", 0} });

        Subject2 subject2;
        Wrapper wrapper2(&subject2, &Subject2::f2, { { "z", 9 } });

        engine.RegisterCommand(&wrapper1, "command1");
        engine.RegisterCommand(&wrapper2, "command2");

        std::cout << "Command1: " << engine.Execute("command1", { { "x", 1 }, { "y", 2} }) << std::endl;
        std::cout << "Empty args in command1: " << engine.Execute("command1", { }) << std::endl;
        std::cout << "Invalid args in command2: " << engine.Execute("command2", { { "x", 1 } }) << std::endl;
    }
    catch (std::out_of_range error)
    {
        std::cout << "Error! Invalid function arguments" << std::endl;
    }
    return 0;
}