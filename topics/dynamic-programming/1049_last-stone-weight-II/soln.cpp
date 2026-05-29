#include <iostream>
#include <vector>
using namespace std;

// ---------------------------------------------------
// LeetCode 1049 - Last Stone Weight II
//
// Implement:
// int lastStoneWeightII(vector<int>& stones)
// ---------------------------------------------------

class Solution {
public:
    int lastStoneWeightII(vector<int>& stones) {
        int n= stones.size();
        int sum = 0;
        for(int stone: stones){
            sum+=stone;
        }
        int target = sum/2;

        vector<bool> dp(target+1, 0);
        dp[0]=true;

        for(int stone: stones){
            for(int i=target; i>=stone; i--){
                dp[i]=dp[i]||dp[i-stone];
            }
        }
        int res=0;
        for(int i=target; i>=0; i--){
            if(dp[i]){
                res=i;
                break;
            }
        }
        return sum-(2*res);
    }
};

struct TestCase {
    vector<int> stones;
    int expected;
};

void runTest(int testNum, vector<int> stones, int expected) {
    Solution sol;
    int result = sol.lastStoneWeightII(stones);

    cout << "Test Case " << testNum << ": ";

    if(result == expected) {
        cout << "PASSED";
    } else {
        cout << "FAILED";
    }

    cout << "\nExpected: " << expected;
    cout << "\nGot:      " << result;
    cout << "\n-----------------------------\n";
}

int main() {

    vector<TestCase> tests = {

        // Example 1
        {{2,7,4,1,8,1}, 1},

        // Example 2
        {{31,26,33,21,40}, 5},

        // Single stone
        {{5}, 5},

        // Perfect partition
        {{1,1}, 0},

        // Equal stones
        {{10,10,10,10}, 0},

        // Small case
        {{1,2,3}, 0},

        // Another partition case
        {{1,2,4,8,16}, 1},

        // Repeated values
        {{1000,1000,1000,1000,1000,1000}, 0},

        // Larger case
        {{9,3,2,10,7,8,6,5,4,1}, 1},

        // Stress-ish case
        {{1,2,3,4,5,6,7,8,9,10,
          11,12,13,14,15,16,17,18,19,20}, 0}
    };

    for(int i = 0; i < tests.size(); i++) {
        runTest(
            i + 1,
            tests[i].stones,
            tests[i].expected
        );
    }

    return 0;
}