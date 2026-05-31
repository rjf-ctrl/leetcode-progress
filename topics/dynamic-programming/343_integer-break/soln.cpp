#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int integerBreak(int n) {
        vector <int> dp(n+1, 0);
        dp[1]=1;
        for(int i=1; i<=n; i++){
            for(int j=1; j<=i; j++){
                if(i-j>=0) dp[i]=max(dp[i], j*max((i-j),dp[i-j]));
            }
        }

        return dp[n];
    }
};
struct TestCase {
    int n;
    int expected;
};

void runTests() {
    vector<TestCase> tests = {
        {2, 1},
        {3, 2},
        {4, 4},
        {5, 6},
        {6, 9},
        {7, 12},
        {8, 18},
        {9, 27},
        {10, 36},
        {15, 243},
        {20, 1458}
    };

    Solution sol;

    int passed = 0;

    for (int i = 0; i < tests.size(); i++) {
        int result = sol.integerBreak(tests[i].n);

        if (result == tests[i].expected) {
            cout << "Test Case " << i + 1 << ": PASS\n";
            passed++;
        } else {
            cout << "Test Case " << i + 1 << ": FAIL\n";
            cout << "Expected: " << tests[i].expected << "\n";
            cout << "Got: " << result << "\n";
        }
    }

    cout << "\nPassed " << passed << "/" << tests.size() << " test cases.\n";
}

int main() {
    runTests();
    return 0;
}