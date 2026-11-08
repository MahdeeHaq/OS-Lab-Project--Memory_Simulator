#include <iostream>
#include <sstream>
#include <string>
#include "../include/input.h"

bool readFrameCount(int& frames)
{
    std::cout << "Enter number of frames: ";
    std::string line;
    if (!std::getline(std::cin, line))
        return false;

    std::istringstream in(line);
    int value;
    char extra;

    if (!(in >> value) || (in >> extra))
    {
        std::cout << "Error: please enter one whole number.\n";
        return false;
    }
    if (value < 1)
    {
        std::cout << "Error: frames must be at least 1.\n";
        return false;
    }

    frames = value;
    return true;
}
