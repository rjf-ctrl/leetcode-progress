#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

class Solution {
public:

    int minimumTotal(vector<vector<int>>& triangle) {

        int n = triangle.size();

        if(n == 1)
            return triangle[0][0];

        vector<vector<int>> dp(n, vector<int>(n));

        dp[0][0] = triangle[0][0];

        for(int i = 1; i < n; i++) {

            for(int j = 0; j <= i; j++) {

                int left = INT_MAX;
                int right = INT_MAX;

                if(j > 0)
                    left = dp[i - 1][j - 1];

                if(j < i)
                    right = dp[i - 1][j];

                dp[i][j] = triangle[i][j] + min(left, right);
            }
        }

        int mn = *min_element(dp[n - 1].begin(), dp[n - 1].end());

        return mn;
    }
};

void runTest(vector<vector<int>> triangle, int expected, int testNo) {

    Solution sol;

    int result = sol.minimumTotal(triangle);

    cout << "Test Case " << testNo << ": ";

    if(result == expected)
        cout << "PASS";
    else
        cout << "FAIL";

    cout << "\nExpected: " << expected;
    cout << "\nGot: " << result << "\n\n";
}

int main() {

    // Test Case 1
    vector<vector<int>> triangle1 = {
        {2},
        {3,4},
        {6,5,7},
        {4,1,8,3}
    };

    runTest(triangle1, 11, 1);

    // Test Case 2
    vector<vector<int>> triangle2 = {
        {-10}
    };

    runTest(triangle2, -10, 2);

    // Test Case 3
    vector<vector<int>> triangle3 = {
        {1},
        {2,3},
        {3,6,7},
        {8,9,6,1}
    };

    runTest(triangle3, 12, 3);

    // Test Case 4
    vector<vector<int>> triangle4 = {
        {5},
        {9,6},
        {4,6,8},
        {0,7,1,5}
    };

    runTest(triangle4, 18, 4);

    // Test Case 5
    vector<vector<int>> triangle5 = {
        {1},
        {1,1},
        {1,1,1}
    };

    runTest(triangle5, 3, 5);

    return 0;
}