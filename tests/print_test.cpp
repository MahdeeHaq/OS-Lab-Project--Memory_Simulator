#include "../include/print.h"

int main()
{
    Result r;
    r.steps.push_back({7, {7}, false, -1});
    r.steps.push_back({0, {7, 0}, false, -1});
    r.steps.push_back({7, {7, 0}, true, -1});
    r.faults = 2;
    r.hits = 1;

    printStepTable(r);
    return 0;
}
