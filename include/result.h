#ifndef RESULT_H
#define RESULT_H

#include <vector>

// One row of the step table: what happened for one page reference.
struct Step
{
    int page;
    std::vector<int> frames;  // frames after this step
    bool hit;                 // true = HIT, false = FAULT
    int victim;               // -1 means no page was evicted
};

// What every algorithm returns.
struct Result
{
    int faults = 0;
    int hits = 0;
    std::vector<Step> steps;
};

#endif
