#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    
    int dfs(int r, int i, vector <vector<int>> & grid, vector <vector<int>> & dp){
        int m= grid.size();

        if(r==m-1) return grid[r][i];
        if(dp[r][i]!=-1) return dp[r][i];

        int max_merit=0;
        for(int x=(i+1)%3; x!=i; x=(x+1)%3){
            max_merit = max(max_merit, grid[r][i] + dfs(r+1, x, grid, dp));
        }

        return dp[r][i]=max_merit;

    }

    int ninjaTraining(vector<vector<int>>& matrix) {
        int m= matrix.size();
        int n= matrix[0].size();

        vector <vector<int>> dp(m, vector<int> (n, -1));
        int max_merit=0;
        for(int i=0; i<3; i++){
            max_merit=max(max_merit, dfs(0, i, matrix, dp));
        }
    
        return max_merit;
    }
};

void runTest(vector<vector<int>> matrix, int expected, int testNo) {

    Solution sol;

    int result = sol.ninjaTraining(matrix);

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
    vector<vector<int>> matrix1 = {
        {10, 40, 70},
        {20, 50, 80},
        {30, 60, 90}
    };

    runTest(matrix1, 210, 1);

    // Test Case 2
    vector<vector<int>> matrix2 = {
        {1, 2, 5},
        {3, 1, 1},
        {3, 3, 3}
    };

    runTest(matrix2, 11, 2);

    // Test Case 3
    vector<vector<int>> matrix3 = {
        {18, 11, 19},
        {4, 13, 7},
        {1, 8, 13}
    };

    runTest(matrix3, 45, 3);

    // Test Case 4
    vector<vector<int>> matrix4 = {
        {5, 1, 2}
    };

    runTest(matrix4, 5, 4);

    // Test Case 5
    vector<vector<int>> matrix5 = {
        {8, 2, 5},
        {6, 7, 1},
        {2, 9, 4},
        {10, 1, 3}
    };

    runTest(matrix5, 30, 5);

    return 0;
}