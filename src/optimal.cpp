
#include <iostream>
#include <vector>
#include <algorithm>
#include "../include/optimal.h"

using namespace std;

void runOptimal(const vector<int>& pages, int frameCount)
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
                size_t farthestNextUse = 0;

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

                    if (nextIndex > farthestNextUse)
                    {
                        farthestNextUse = nextIndex;
                        victimIndex = j;
                    }
                }

                victim = frames[victimIndex];
                frames[victimIndex] = currentPage;
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
            {
                cout << " | Victim: " << victim;
            }
        }

        cout << endl;
    }

    int totalReferences = static_cast<int>(pages.size());

    double hitRatio =
        static_cast<double>(pageHits) / totalReferences;

    double faultRatio =
        static_cast<double>(pageFaults) / totalReferences;

    cout << "\nTotal Page Faults: " << pageFaults << endl;
    cout << "Total Page Hits: " << pageHits << endl;
    cout << "Hit Ratio: " << hitRatio << endl;
    cout << "Fault Ratio: " << faultRatio << endl;
}
