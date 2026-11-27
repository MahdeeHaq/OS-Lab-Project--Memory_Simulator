#include <vector>
#include "../include/framesize.h"
#include "../include/fifo.h"

int main()
{
    std::vector<int> pages = {1, 2, 3, 4, 1, 2, 5, 1, 2, 3, 4, 5};

    printFrameSizeTable("FIFO", runFIFO, pages, 6);
    return 0;
}
