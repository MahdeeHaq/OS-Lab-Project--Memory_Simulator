#include <iostream>
#include <string>
#include <vector>
#include "../include/fifo.h"
#include "../include/print.h"

using namespace std;

static int failures = 0;

static void check(const string& name, const vector<int>& pages, int frames,
                  int expectedFaults, int expectedHits)
{
    Result r = runFIFO(pages, frames);
    bool ok = (r.faults == expectedFaults && r.hits == expectedHits);
    cout << (ok ? "PASS" : "FAIL") << ": " << name
         << " (faults " << r.faults << ", hits " << r.hits << ")" << endl;
    if (!ok)
        failures++;
}

int main()
{
    // Show the step table once, so we can read it
    printStepTable(runFIFO({7, 0, 1, 2, 0, 3}, 3));
    cout << endl;

    check("small string, 3 frames", {7, 0, 1, 2, 0, 3}, 3, 5, 1);
    check("20-page string, 3 frames", {7,0,1,2,0,3,0,4,2,3,0,3,2,1,2,0,1,7,0,1}, 3, 15, 5);
    check("Belady string, 3 frames", {1,2,3,4,1,2,5,1,2,3,4,5}, 3, 9, 3);
    check("Belady string, 4 frames", {1,2,3,4,1,2,5,1,2,3,4,5}, 4, 10, 2);
    check("one frame, 1 1 2", {1, 1, 2}, 1, 2, 1);
    check("empty pages", {}, 3, 0, 0);
    check("zero frames", {1, 2, 3}, 0, 0, 0);

    if (failures == 0)
        cout << "All tests passed." << endl;
    else
        cout << failures << " test(s) FAILED." << endl;

    return failures == 0 ? 0 : 1;
}
