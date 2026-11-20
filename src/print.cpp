#include <iostream>
#include "../include/print.h"

using namespace std;

void printStepTable(const Result& result)
{
    cout << "Page | Frames | Result | Victim" << endl;

    for (size_t i = 0; i < result.steps.size(); i++)
    {
        const Step& s = result.steps[i];

        cout << s.page << " | ";
        for (size_t j = 0; j < s.frames.size(); j++)
        {
            cout << s.frames[j] << " ";
        }
        cout << "| " << (s.hit ? "HIT" : "FAULT") << " | ";

        if (s.victim == -1)
            cout << "-";
        else
            cout << s.victim;
        cout << endl;
    }

    double total = (double)result.steps.size();
    cout << "Total faults: " << result.faults << endl;
    cout << "Total hits: " << result.hits << endl;
    cout << "Hit ratio: " << result.hits / total << endl;
    cout << "Fault ratio: " << result.faults / total << endl;
}
