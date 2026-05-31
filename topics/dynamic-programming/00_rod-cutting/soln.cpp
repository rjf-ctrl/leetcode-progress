#include <iostream>
#include <vector>

using namespace std;

/*
TUF / GFG Rod Cutting Problem

Given a rod of length N and an array price[],
where price[i] denotes the value of a rod piece of length (i + 1).

Implement:

class Solution {
public:
    int cutRod(vector<int>& price, int n);
};

Return the maximum obtainable value by cutting up the rod.
*/

class Solution{
  public:
    int cutRod(vector<int> price, int n) {
        vector <int> dp(n+1, 0);

         for(int i=1; i<=n; i++){
            for(int j=1; j<=i; j++){
                if(i-j>=0) dp[i]=max(dp[i], price[j-1]+dp[i-j]);
            }
         }

         return dp[n];
    }
};


struct TestCase {
    vector<int> price;
    int n;
    int expected;
};

void runTests() {
    vector<TestCase> tests = {
        {{1, 5, 8, 9, 10, 17, 17, 20}, 8, 22},
        {{3, 5, 8, 9, 10, 17, 17, 20}, 8, 24},
        {{2, 5, 7, 8}, 4, 10},
        {{1}, 1, 1},
        {{2, 5}, 2, 5},
        {{1, 3, 4, 5, 7, 9, 10, 11}, 8, 12},
        {{5, 10, 15, 20}, 4, 20},
        {{2, 6, 7, 10}, 4, 12},
        {{2, 3, 7, 8, 9}, 5, 11},
        {{2, 5, 9, 10, 12, 17, 20, 24}, 8, 24}
    };

    Solution sol;

    int passed = 0;

    for (int i = 0; i < tests.size(); i++) {
        int result = sol.cutRod(tests[i].price, tests[i].n);

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