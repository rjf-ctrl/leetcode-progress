#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n=nums.size();
        vector <int> dp(n, 0);

        for(int i=n-1; i>=0; i--){
            dp[i]=1;
            for(int j=n-1; j>i; j--){
                if(nums[i]<nums[j])dp[i]=max(dp[i], 1+dp[j]);
            }
        
        }
        return *max_element(dp.begin(), dp.end());
    }
};
struct TestCase {
    vector<int> nums;
    int expected;
};

int main() {
    Solution sol;

    vector<TestCase> tests = {
        {{10,9,2,5,3,7,101,18}, 4},
        {{0,1,0,3,2,3}, 4},
        {{7,7,7,7,7,7,7}, 1},
        {{1}, 1},
        {{1,2,3,4,5}, 5},
        {{5,4,3,2,1}, 1},
        {{4,10,4,3,8,9}, 3},
        {{2,2,2,2}, 1},
        {{1,3,6,7,9,4,10,5,6}, 6},
        {{3,1,2}, 2}
    };

    int passed = 0;

    for (int i = 0; i < tests.size(); i++) {
        int result = sol.lengthOfLIS(tests[i].nums);

        if (result == tests[i].expected) {
            cout << "Test " << i + 1 << ": PASS\n";
            passed++;
        } else {
            cout << "Test " << i + 1 << ": FAIL\n";
            cout << "Expected: " << tests[i].expected
                 << ", Got: " << result << "\n";
        }
    }

    cout << "\nPassed " << passed << "/" << tests.size() << " test cases.\n";

    return 0;
}