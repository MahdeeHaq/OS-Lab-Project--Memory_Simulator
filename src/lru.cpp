
#include <iostream>
#include <vector>
#include <algorithm>
#include <cstddef>
#include "../include/lru.h"

using namespace std;

void runLRU(const vector<int>& pages, int frameCount)
{
    if (frameCount <= 0)
    {
        cout << "Invalid frame count!" << endl;
        return;
    }

    if (pages.empty())
    {
        cout << "No page references provided!" << endl;
        return;
    }

    vector<int> frames;
    vector<size_t> lastUsed;

    int pageFaults = 0, pageHits = 0;

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

        cout << "Page " << currentPage << " | Frames: ";

        for (int page : frames)
        {
            cout << page << " ";
        }

        if (hit)
        {
            cout << "| HIT";
        }
        else
        {
            cout << "| FAULT";

            if (victim != -1)
                cout << " | Victim: " << victim;
        }

        cout << endl;
    }

    cout << "\nTotal Page Faults: " << pageFaults << endl;
    cout << "Total Page Hits: " << pageHits << endl;

    size_t totalReferences = pages.size();

    double hitRatio = static_cast<double>(pageHits) / totalReferences;
    double faultRatio = static_cast<double>(pageFaults) / totalReferences;

    cout << "Hit Ratio: " << hitRatio << endl;
    cout << "Fault Ratio: " << faultRatio << endl;
}
