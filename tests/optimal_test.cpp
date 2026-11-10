
#include <iostream>
#include "../include/optimal.h"

using namespace std;

int main()
{
    vector<int> pages = {1, 2, 3, 4, 1, 2, 5};

    int frameCount = 3;

    runOptimal(pages, frameCount);

    return 0;
}
