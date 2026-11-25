#include <iostream>
#include <vector>
#include "../include/lru.h"

using namespace std;

bool checkLRUTest(
    const vector<int>& pages,
    int frameCount,
    int expectedFaults,
    int expectedHits,
    int testNumber)
{
    cout << "\n========== Test " << testNumber << " ==========\n";

    LRUResult result = runLRU(pages, frameCount);

    bool passed =
        (result.pageFaults == expectedFaults) &&
        (result.pageHits == expectedHits);

    cout << "Expected Faults: " << expectedFaults << endl;
    cout << "Actual Faults: " << result.pageFaults << endl;

    cout << "Expected Hits: " << expectedHits << endl;
    cout << "Actual Hits: " << result.pageHits << endl;

    cout << "Test " << testNumber << ": "
         << (passed ? "PASS" : "FAIL") << endl;

    return passed;
}

int main()
{
    int passedTests = 0;
    int totalTests = 3;

    // Test 1
    if (checkLRUTest({1, 2, 3, 1, 4}, 3, 4, 1, 1))
        passedTests++;

    // Test 2
    if (checkLRUTest({1, 2, 1, 2}, 2, 2, 2, 2))
        passedTests++;

    // Test 3
    if (checkLRUTest({1, 2, 3, 1, 2, 4, 1, 2, 3, 4},
                     3, 6, 4, 3))
        passedTests++;

    cout << "\n========== FINAL RESULT ==========\n";

    cout << "LRU Test: "
         << (passedTests == totalTests ? "PASS" : "FAIL")
         << endl;

    cout << "Passed: " << passedTests
         << "/" << totalTests << endl;

    return (passedTests == totalTests) ? 0 : 1;
}