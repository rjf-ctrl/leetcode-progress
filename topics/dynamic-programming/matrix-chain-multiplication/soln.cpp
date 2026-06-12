#include <bits/stdc++.h>
using namespace std;

class Solution{
	public:

        int solve (int i, int j, vector<int> &arr, vector <vector<int>> &dp){
            if(i==j) return 0;
            if(dp[i][j]!=-1) return dp[i][j];
            int ans=1e9; //initailising to a large value

            for(int k=i; k<j; k++){
                ans = min(ans, solve(i, k, arr, dp)+solve(k+1, j, arr, dp)+ arr[i-1]*arr[k]*arr[j]);
            }
            return dp[i][j]=ans;
        }

		int matrixMultiplication(vector<int>& nums){
            vector <vector<int>> dp(nums.size(), vector<int>(nums.size(), -1));
            return solve(1, nums.size()-1, nums, dp);
    	}
};

struct TestCase {
    vector<int> arr;
    int expected;
};

int main() {
    Solution sol;

    vector<TestCase> tests = {
        {{10, 20}, 0},
        {{10, 20, 30}, 6000},
        {{10, 20, 30, 40}, 18000},
        {{40, 20, 30, 10, 30}, 26000},
        {{10, 20, 30, 40, 30}, 30000},
        {{1, 2, 3, 4, 3}, 30},
        {{5, 4, 6, 2, 7}, 158},
        {{2, 3, 6, 4, 5}, 124},
        {{3, 5, 2, 6}, 66},
        {{1, 2, 3, 5, 2}, 31}
    };

    int passed = 0;

    for (int i = 0; i < tests.size(); i++) {
        int result = sol.matrixMultiplication(tests[i].arr);

        if (result == tests[i].expected) {
            cout << "Test " << i + 1 << " PASSED\n";
            passed++;
        } else {
            cout << "Test " << i + 1 << " FAILED\n";
            cout << "Expected: " << tests[i].expected << "\n";
            cout << "Got:      " << result << "\n\n";
        }
    }

    cout << "\nSummary: "
         << passed << "/" << tests.size()
         << " tests passed.\n";

    return 0;
}