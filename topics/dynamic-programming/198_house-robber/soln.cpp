#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n==1) return nums[0];
        if(n==2) return nums[0]>nums[1]? nums[0]:nums[1];

        int rob1 = 0, rob2 = 0;

        for(int i=0; i<n; i++){
            int current = max(nums[i]+rob1, rob2);
            rob1=rob2;
            rob2 = current;
        }

        return rob2;
    }
};

int main() {
    Solution sol;

    vector<pair<vector<int>, int>> testCases = {
        {{1, 2, 3, 1}, 4},
        {{2, 7, 9, 3, 1}, 12},
        {{2, 1, 1, 2}, 4}
    };

    for (int i = 0; i < testCases.size(); i++) {
        vector<int> nums = testCases[i].first;
        int expected = testCases[i].second;

        int result = sol.rob(nums);

        cout << "Test Case " << i + 1 << ": ";

        if (result == expected) {
            cout << "Passed";
        } else {
            cout << "Failed";
        }

        cout << " | Expected: " << expected
             << " | Got: " << result << endl;
    }

    return 0;
}
