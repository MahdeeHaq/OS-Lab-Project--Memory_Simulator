
#include <iostream>
#include <vector>
#include "../include/optimal.h"
#include "../include/result.h"

using namespace std;

bool checkOptimalTest(
    const vector<int>& pages,
    int frameCount,
    int expectedFaults,
    int expectedHits,
    int testNumber)
{
    cout << "\n========== Test " << testNumber << " ==========\n";

    Result result = runOptimal(pages, frameCount);

    bool passed =
        (result.faults == expectedFaults) &&
        (result.hits == expectedHits);

    cout << "Expected Faults: " << expectedFaults << endl;
    cout << "Actual Faults: " << result.faults << endl;

    cout << "Expected Hits: " << expectedHits << endl;
    cout << "Actual Hits: " << result.hits << endl;

    cout << "Test " << testNumber << ": "
         << (passed ? "PASS" : "FAIL") << endl;

    return passed;
}

int main()
{
    int passedTests = 0;
    int totalTests = 3;

    // Test 1
    if (checkOptimalTest({1, 2, 3, 4, 1, 2, 5}, 3, 5, 2, 1))
        passedTests++;

    // Test 2
    if (checkOptimalTest({1, 2, 1, 2}, 2, 2, 2, 2))
        passedTests++;

    // Test 3
    if (checkOptimalTest(
        {1, 2, 3, 4, 1, 2, 5, 1, 2, 3, 4, 5},
        3, 7, 5, 3))
        passedTests++;

    cout << "\n========== FINAL RESULT ==========\n";

    cout << "Optimal Test: "
         << (passedTests == totalTests ? "PASS" : "FAIL")
         << endl;

    cout << "Passed: " << passedTests
         << "/" << totalTests << endl;

    return (passedTests == totalTests) ? 0 : 1;
}
