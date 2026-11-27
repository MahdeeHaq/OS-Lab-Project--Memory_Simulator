#include <iostream>
#include <vector>
#include "../include/input.h"

int main(int argc, char* argv[]) {
    std::cout << "Memory Management Simulator\n";
    std::vector<int> pages;
    bool ok;
    if (argc > 1)
        ok = readPagesFromFile(argv[1], pages);
    else
        ok = readPagesFromKeyboard(pages);

    if (ok)
        std::cout << "Read " << pages.size() << " pages.\n";
    return 0;
}
