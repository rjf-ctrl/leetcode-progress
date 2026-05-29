#include <iostream>
#include <vector>
#include <string>
using namespace std;

// ---------------------------------------------------
// LeetCode 494 - Target Sum
// Function to implement:
// int findTargetSumWays(vector<int>& nums, int target)
// ---------------------------------------------------

class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int n= nums.size();
        int total =0;
        for(int x: nums) total+=x;

        if(total+target<0||(total+target)%2!=0) return 0;

        int p=(total+target)/2;

        vector<int> dp(p+1, 0);  //dp[i] = number of ways to get sum i
        dp[0]=1; //only one way to get sum 0 : {}

        for(int x: nums){
            for(int i=p; i>=x; i--){
                dp[i]+=dp[i-x];   //for every x : nums, the number of ways it is possible to get i = n. of ways to get i=x;
            }
        }
        return dp[p];
    }
};

struct TestCase {
    vector<int> nums;
    int target;
    int expected;
};

void runTest(int testNum, vector<int> nums, int target, int expected) {
    Solution sol;
    int result = sol.findTargetSumWays(nums, target);

    cout << "Test Case " << testNum << ": ";

    if(result == expected) {
        cout << "PASSED";
    } else {
        cout << "FAILED";
    }

    cout << "\n";
    cout << "Expected: " << expected << "\n";
    cout << "Got: " << result << "\n";
    cout << "--------------------------\n";
}

int main() {

    vector<TestCase> tests = {

        // Example 1
        {{1,1,1,1,1}, 3, 5},

        // Example 2
        {{1}, 1, 1},

        // Additional Test Cases
        {{1,2,1}, 0, 2},

        {{2,3,5,6,8,10}, 10, 1},

        {{0,0,0,0,0,0,0,0,1}, 1, 256},

        {{100}, -100, 1},

        {{1,2,7,9,981}, 1000000000, 0}
    };

    for(int i = 0; i < tests.size(); i++) {
        runTest(
            i + 1,
            tests[i].nums,
            tests[i].target,
            tests[i].expected
        );
    }

    return 0;
}