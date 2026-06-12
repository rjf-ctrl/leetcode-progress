#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int maxCoins(vector<int>& nums) {

        int n = nums.size();

        vector<int> arr(n + 2, 1);

        for(int i = 0; i < n; i++) {
            arr[i + 1] = nums[i];
        }

        vector<vector<int>> dp(
            n + 2,
            vector<int>(n + 2, 0)
        );

        for(int len = 1; len <= n; len++) {

            for(int L = 1; L + len - 1 <= n; L++) {

                int R = L + len - 1;

                for(int i = L; i <= R; i++) {

                    dp[L][R] = max(
                        dp[L][R],
                        dp[L][i - 1]
                        + arr[L - 1] * arr[i] * arr[R + 1]
                        + dp[i + 1][R]
                    );
                }
            }
        }

        return dp[1][n];
    }
};

struct TestCase {
    vector<int> nums;
    int expected;
};

int main() {

    vector<TestCase> tests = {

        // LeetCode examples
        {{3,1,5,8}, 167},
        {{1,5}, 10},

        // Single balloon
        {{1}, 1},
        {{5}, 5},
        {{9}, 9},

        // Two balloons
        {{1,2}, 4},
        {{2,3}, 9},

        // All ones
        {{1,1,1,1}, 4},

        // Increasing
        {{1,2,3,4}, 40},

        // Decreasing
        {{4,3,2,1}, 40},

        // Contains zero
        {{0,1,5}, 10},
        {{5,0,1}, 10},

        // Larger cases
        {{7,9,8,0,7,1,3,5,5,2,3}, 1654},
        {{8,2,6,8,1,5}, 888}
    };

    

    int passed = 0;

    for(int i = 0; i < tests.size(); i++) {

        
        int actual = Solution().maxCoins(tests[i].nums);

        if(actual == tests[i].expected) {
            cout << "[PASS] Test " << i + 1 << '\n';
            passed++;
        }
        else {
            cout << "[FAIL] Test " << i + 1
                 << " Expected = " << tests[i].expected
                 << " Got = " << actual << '\n';
        }
       
    }


    return 0;
}