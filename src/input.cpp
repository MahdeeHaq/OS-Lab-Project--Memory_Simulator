#include <fstream>
#include <cctype>
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

// Helper: turns text like "7 0 1 2" into a list of numbers.
// Only used inside this file (that is what "static" means).
static bool parsePages(const std::string& text, std::vector<int>& pages)
{
    std::istringstream in(text);
    std::string token;
    std::vector<int> result;

    while (in >> token)
    {
        if (token.size() > 9)
        {
            std::cout << "Error: '" << token << "' is too long.\n";
            return false;
        }
        for (char c : token)
        {
            if (!std::isdigit(static_cast<unsigned char>(c)))
            {
                std::cout << "Error: '" << token << "' is not a valid page number.\n";
                return false;
            }
        }
        result.push_back(std::stoi(token));
    }

    if (result.empty())
    {
        std::cout << "Error: no page numbers entered.\n";
        return false;
    }

    pages = result;
    return true;
}

bool readPagesFromKeyboard(std::vector<int>& pages)
{
    std::cout << "Enter page reference string (numbers separated by spaces): ";
    std::string line;
    if (!std::getline(std::cin, line))
        return false;
    return parsePages(line, pages);
}

bool readPagesFromFile(const std::string& filename, std::vector<int>& pages)
{
    std::ifstream file(filename);
    if (!file)
    {
        std::cout << "Error: cannot open file '" << filename << "'.\n";
        return false;
    }

    std::stringstream buffer;
    buffer << file.rdbuf();
    return parsePages(buffer.str(), pages);
}
