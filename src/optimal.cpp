
#include <vector>
#include <algorithm>
#include "../include/optimal.h"
#include "../include/result.h"

using namespace std;

Result runOptimal(const vector<int>& pages, int frameCount)
{
    Result result;

    if (frameCount <= 0 || pages.empty())
    {
        return result;
    }

    vector<int> frames;

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
        }
        else
        {
            pageFaults++;

            if (frames.size() < static_cast<size_t>(frameCount))
            {
                frames.push_back(currentPage);
            }
            else
            {
                size_t victimIndex = 0;

                for (size_t j = 0; j < frames.size(); j++)
                {
                    auto nextUse = find(
                        pages.begin() + i + 1,
                        pages.end(),
                        frames[j]
                    );

                    if (nextUse == pages.end())
                    {
                        victimIndex = j;
                        break;
                    }

                    size_t nextIndex =
                        static_cast<size_t>(nextUse - pages.begin());

                    auto currentNextUse = find(
                        pages.begin() + i + 1,
                        pages.end(),
                        frames[victimIndex]
                    );

                    if (currentNextUse != pages.end())
                    {
                        size_t currentIndex =
                            static_cast<size_t>(
                                currentNextUse - pages.begin()
                            );

                        if (nextIndex > currentIndex)
                        {
                            victimIndex = j;
                        }
                    }
                }

                victim = frames[victimIndex];
                frames[victimIndex] = currentPage;
            }
        }

        result.steps.push_back({currentPage, frames, hit, victim});
    }

    result.faults = pageFaults;
    result.hits = pageHits;

    return result;
}
