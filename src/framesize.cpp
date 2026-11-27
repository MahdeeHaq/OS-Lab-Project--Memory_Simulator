// File: src/framesize.cpp
// Purpose: run one algorithm with 1..maxFrames frames and show faults
// Author: Mahdee Haque
// OS concept: effect of memory size on page faults, Belady's anomaly

#include <iostream>
#include "../include/framesize.h"

using namespace std;

void printFrameSizeTable(const string& name, Algorithm algo,
                         const vector<int>& pages, int maxFrames)
{
    if (maxFrames <= 0 || pages.empty())
    {
        cout << "Error: need at least 1 frame and 1 page." << endl;
        return;
    }

    cout << "=== Frame-size comparison: " << name << " ===" << endl;
    cout << "Frames | Faults | Chart" << endl;

    int previousFaults = 0;

    for (int frames = 1; frames <= maxFrames; frames++)
    {
        Result r = algo(pages, frames);   // fresh run for every size

        cout << frames << " | " << r.faults << " | ";
        for (int i = 0; i < r.faults; i++)
        {
            cout << '#';
        }

        // More memory but more faults = Belady's anomaly
        if (frames > 1 && r.faults > previousFaults)
        {
            cout << "  <-- anomaly: more faults than with " << frames - 1
                 << " frames";
        }
        cout << endl;

        previousFaults = r.faults;
    }
    cout << endl;
}
