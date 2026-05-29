#include <iostream>
#include <vector>
using namespace std;

// ---------------------------------------------------
// LeetCode 322 - Coin Change
//
// Implement:
// int coinChange(vector<int>& coins, int amount)
// ---------------------------------------------------

class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        if(amount==0) return 0;
        int n = coins.size();
       
        vector <int> dp(amount+1, amount+1);
        dp[0]=0;
        for(int i=0; i<=amount; i++){
            for(int x:coins){
                if(i-x>=0)
                dp[i]=min(dp[i], 1+dp[i-x]);    
            }
        }
     return dp[amount]!=amount+1? dp[amount]:-1;   
    }
};

struct TestCase {
    vector<int> coins;
    int amount;
    int expected;
};

void runTest(int testNum,
             vector<int> coins,
             int amount,
             int expected)
{
    Solution sol;
    int result = sol.coinChange(coins, amount);

    cout << "Test Case " << testNum << ": ";

    if(result == expected)
        cout << "PASSED";
    else
        cout << "FAILED";

    cout << "\nExpected: " << expected;
    cout << "\nGot:      " << result;
    cout << "\n-----------------------------\n";
}

int main() {

    vector<TestCase> tests = {

        // Example 1
        {{1,2,5}, 11, 3},

        // Example 2
        {{2}, 3, -1},

        // Example 3
        {{1}, 0, 0},

        // Single coin
        {{1}, 5, 5},

        // Exact match
        {{7}, 7, 1},

        // Impossible
        {{4,6}, 5, -1},

        // Multiple choices
        {{1,3,4}, 6, 2},

        // Greedy would fail
        {{1,3,4}, 10, 3},

        // Larger amount
        {{1,2,5}, 100, 20},

        // Common test
        {{2,5,10,1}, 27, 4}
    };

    for(int i = 0; i < tests.size(); i++) {
        runTest(
            i + 1,
            tests[i].coins,
            tests[i].amount,
            tests[i].expected
        );
    }

    return 0;
}