#include <iostream>
#include <vector>
#include "../include/fifo.h"

using namespace std;

int main()
{
    vector<int> pages = {1, 2, 3, 4, 1, 2, 5, 1, 2, 3, 4, 5};
    int frameCount = 4;

    runFIFO(pages, frameCount);

    return 0;
}
