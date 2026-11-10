
#include <iostream>
#include "../include/lru.h"

using namespace std;

int main()
{
    vector<int> pages = {1,2,3,1,4};
    int frameCount = 3;

    runLRU(pages, frameCount);

    return 0;
}
