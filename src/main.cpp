// File: src/main.cpp
// Purpose: read input, run the algorithms, print the step tables
// Author: Mahdee Haque
// AI-assisted: yes (see docs/AI_USAGE_LOG.md)
// OS concept: page replacement

#include <iostream>
#include <string>
#include <vector>
#include "../include/input.h"
#include "../include/result.h"
#include "../include/print.h"
#include "../include/fifo.h"
#include "../include/lru.h"
#include "../include/optimal.h"

using namespace std;

static void showAlgorithm(const string& name, const Result& result)
{
    cout << "=== " << name << " ===" << endl;
    printStepTable(result);
    cout << endl;
}

int main(int argc, char* argv[])
{
    vector<int> pages;
    int frameCount = 0;

    // Pages come from a file if one is given, otherwise from the keyboard
    if (argc > 1)
    {
        if (!readPagesFromFile(argv[1], pages))
            return 1;
    }
    else
    {
        if (!readPagesFromKeyboard(pages))
            return 1;
    }

    if (!readFrameCount(frameCount))
        return 1;

    // Every algorithm gets the same input and starts fresh
    showAlgorithm("FIFO", runFIFO(pages, frameCount));
    showAlgorithm("LRU", runLRU(pages, frameCount));
    showAlgorithm("Optimal", runOptimal(pages, frameCount));

    return 0;
}
