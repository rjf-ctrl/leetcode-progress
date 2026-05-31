#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int change(int amount, vector<int>& coins) {
        vector<unsigned long long> dp(amount + 1, 0);
        dp[0] = 1;

        for (int coin : coins) {
            for (int j = coin; j <= amount; j++) {
                dp[j] += dp[j - coin];
            }
        }

        return dp[amount];
    }
};



struct TestCase {
    int amount;
    vector<int> coins;
    int expected;
};

void runTests() {
    vector<TestCase> tests = {
        {5, {1, 2, 5}, 4},
        {3, {2}, 0},
        {10, {10}, 1},
        {0, {1, 2, 3}, 1},
        {4, {1, 2, 3}, 4},
        {7, {2, 3, 6, 7}, 2},
        {500, {3, 5, 7, 8, 9, 10, 11}, 35502874}
    };

    Solution sol;

    int passed = 0;

    for (int i = 0; i < tests.size(); i++) {
        int result = sol.change(tests[i].amount, tests[i].coins);

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