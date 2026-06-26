#include <bits/stdc++.h>
using namespace std;


class Solution {
public:
    int jump(vector<int>& nums) {

        int jumps = 0;
        int currentEnd = 0;
        int currentFarthest = 0;

        for (int i = 0; i < nums.size() - 1; i++) {

            currentFarthest = max(currentFarthest, i + nums[i]);

            if (i == currentEnd) {
                jumps++;
                currentEnd = currentFarthest;
            }
        }

        return jumps;
    }
};

void runTest(int testNo, vector<int> nums, int expected) {

    Solution sol;
    int ans = sol.jump(nums);

    if(ans == expected)
        cout << "Test " << testNo << " Passed\n";
    else
        cout << "Test " << testNo << " Failed\n"
             << "Expected: " << expected
             << " Got: " << ans << "\n";
}

int main() {

    runTest(1, {2,3,1,1,4}, 2);

    runTest(2, {2,3,0,1,4}, 2);

    runTest(3, {1}, 0);

    runTest(4, {1,2}, 1);

    runTest(5, {3,4,2,1,2,1}, 2);

    return 0;
}
