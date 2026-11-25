#ifndef LRU_H
#define LRU_H

#include <vector>

struct LRUResult
{
    int pageFaults;
    int pageHits;
};

LRUResult runLRU(const std::vector<int>& pages, int frameCount);

#endif