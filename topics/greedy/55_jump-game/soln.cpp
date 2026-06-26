
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool canJump(vector<int>& nums) {

        int farthest = 0;

        for(int i = 0; i < nums.size(); i++) {

            if(i > farthest)
                return false;

            farthest = max(farthest, i + nums[i]);
        }

        return true;
    }
};

void runTest(int testNo, vector<int> nums, bool expected) {

    Solution sol;
    bool ans = sol.canJump(nums);

    if(ans == expected)
        cout << "Test " << testNo << " Passed\n";
    else
        cout << "Test " << testNo << " Failed\n"
             << "Expected: " << expected
             << " Got: " << ans << "\n";
}

int main() {

    runTest(1, {2,3,1,1,4}, true);

    runTest(2, {3,2,1,0,4}, false);

    runTest(3, {0}, true);

    runTest(4, {2,0,0}, true);

    runTest(5, {1,0,1,0}, false);

    return 0;
}