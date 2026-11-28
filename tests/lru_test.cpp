
#include <iostream>
#include <vector>
#include "../include/lru.h"
#include "../include/result.h"

using namespace std;

bool checkLRUTest(
    const vector<int>& pages,
    int frameCount,
    int expectedFaults,
    int expectedHits,
    int testNumber)
{
    Result result = runLRU(pages, frameCount);

    bool passed =
        (result.faults == expectedFaults) &&
        (result.hits == expectedHits);

    cout << "Test " << testNumber << ": "
         << (passed ? "PASS" : "FAIL") << endl;

    return passed;
}

int main()
{
    int passed = 0;

    if (checkLRUTest({1, 2, 3, 1, 4}, 3, 4, 1, 1))
        passed++;

    if (checkLRUTest({1, 2, 1, 2}, 2, 2, 2, 2))
        passed++;

    if (checkLRUTest(
        {1, 2, 3, 1, 2, 4, 1, 2, 3, 4},
        3, 6, 4, 3))
        passed++;

    cout << "\nPassed: " << passed << "/3" << endl;

    return 0;
}
