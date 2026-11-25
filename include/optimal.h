#ifndef OPTIMAL_H
#define OPTIMAL_H

#include <vector>

struct OptimalResult
{
    int pageFaults;
    int pageHits;
};

OptimalResult runOptimal(const std::vector<int>& pages, int frameCount);

#endif