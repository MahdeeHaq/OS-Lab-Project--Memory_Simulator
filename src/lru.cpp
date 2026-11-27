
#include <vector>
#include <algorithm>
#include <cstddef>
#include "../include/lru.h"
#include "../include/result.h"

using namespace std;

Result runLRU(const vector<int>& pages, int frameCount)
{
    Result result;

    if (frameCount <= 0 || pages.empty())
    {
        return result;
    }

    vector<int> frames;
    vector<size_t> lastUsed;

    int pageFaults = 0;
    int pageHits = 0;

    for (size_t i = 0; i < pages.size(); i++)
    {
        int currentPage = pages[i];
        bool hit = false;
        int victim = -1;

        auto it = find(frames.begin(), frames.end(), currentPage);

        if (it != frames.end())
        {
            hit = true;
            pageHits++;

            size_t index = static_cast<size_t>(it - frames.begin());
            lastUsed[index] = i;
        }
        else
        {
            pageFaults++;

            if (frames.size() < static_cast<size_t>(frameCount))
            {
                frames.push_back(currentPage);
                lastUsed.push_back(i);
            }
            else
            {
                size_t lruIndex = 0;

                for (size_t j = 1; j < lastUsed.size(); j++)
                {
                    if (lastUsed[j] < lastUsed[lruIndex])
                    {
                        lruIndex = j;
                    }
                }

                victim = frames[lruIndex];

                frames[lruIndex] = currentPage;
                lastUsed[lruIndex] = i;
            }
        }

        result.steps.push_back({currentPage, frames, hit, victim});
    }

    result.faults = pageFaults;
    result.hits = pageHits;

    return result;
}
