#include <vector>
#include <queue>
#include <algorithm>
#include "../include/fifo.h"

using namespace std;

Result runFIFO(const vector<int>& pages, int frameCount)
{
    Result result;

    // Bad input: return an empty result (input is also checked in input.cpp)
    if (frameCount <= 0 || pages.empty())
    {
        return result;
    }

    vector<int> frames;   // the shelf: pages currently in memory
    queue<int> order;     // the line: front = oldest page

    for (size_t i = 0; i < pages.size(); i++)
    {
        int page = pages[i];
        auto it = find(frames.begin(), frames.end(), page);

        // HIT: nothing changes in FIFO
        if (it != frames.end())
        {
            result.hits++;
            result.steps.push_back({page, frames, true, -1});
            continue;
        }

        // FAULT
        result.faults++;
        int victim = -1;

        if (frames.size() < (size_t)frameCount)
        {
            frames.push_back(page);
            order.push(page);
        }
        else
        {
            victim = order.front();   // oldest page
            order.pop();

            auto slot = find(frames.begin(), frames.end(), victim);
            *slot = page;
            order.push(page);
        }

        result.steps.push_back({page, frames, false, victim});
    }

    return result;
}
