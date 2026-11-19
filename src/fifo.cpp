#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include "../include/fifo.h"

using namespace std;

void runFIFO(const vector<int>& pages, int frameCount)
{
    if (frameCount <= 0 || pages.empty())
    {
        cout << "Error: need at least 1 frame and 1 page." << endl;
        return;
    }
    vector<int> frames;   // the shelf: pages currently in memory
    queue<int> order;     // the line: front = oldest page
    int faults = 0;
    int hits = 0;
    for (size_t i = 0; i < pages.size(); i++)
    {
        int page = pages[i];

        auto it = find(frames.begin(), frames.end(), page);

        if (it != frames.end())
        {
            hits++;
            cout << "Page " << page << ": HIT" << endl;
            continue;
        }
        faults++;

        if (frames.size() < (size_t)frameCount)
        {
            frames.push_back(page);
            order.push(page);
            cout << "Page " << page << ": FAULT" << endl;
        }
        else
        {
            int victim = order.front();
            order.pop();

            auto slot = find(frames.begin(), frames.end(), victim);
            *slot = page;
            order.push(page);

            cout << "Page " << page << ": FAULT, victim = " << victim << endl;
        }
    }
    cout << "Total faults: " << faults << endl;
    cout << "Total hits: " << hits << endl;
    cout << "Hit ratio: " << (double)hits / pages.size() << endl;
    cout << "Fault ratio: " << (double)faults / pages.size() << endl;
}
