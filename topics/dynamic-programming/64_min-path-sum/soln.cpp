#include <iostream>
#include <vector>
#include <climits>

using namespace std;

class Solution {
public:

    int dfs(int m, int n, vector<vector<int>> &grid, vector<vector<int>> &dp){
        if(m<0 || n<0) return -1;

        if(m==0 && n==0) return grid[0][0];

        if(dp[m][n]!=-1) return dp[m][n];

        int u=-1, l=-1;

        if(m>0) u=dfs(m-1, n, grid, dp);
        if(n>0) l=dfs(m, n-1, grid, dp);

        if(u==-1) return dp[m][n]= l + grid[m][n];
        if(l==-1) return dp[m][n]= u + grid[m][n];

        return dp[m][n]= min(u, l) + grid[m][n];
    }

    int minPathSum(vector<vector<int>>& grid) {
        int m= grid.size();
        int n= grid[0].size();

        if(m==1 && n==1) return grid[0][0];
        if(n==0) return 0;

        vector <vector<int>> dp(m, vector<int> (n, -1));

        return dfs(m-1, n-1, grid, dp);

        
    }
};


void runTest(vector<vector<int>> grid, int expected, int testNo) {

    Solution sol;
    int result = sol.minPathSum(grid);

    cout << "Test Case " << testNo << ": ";

    if(result == expected)
        cout << "PASS";
    else
        cout << "FAIL";

    cout << "\nExpected: " << expected;
    cout << "\nGot: " << result << "\n\n";
}

int main() {

    vector<vector<int>> grid1 = {
        {1,3,1},
        {1,5,1},
        {4,2,1}
    };
    runTest(grid1, 7, 1);

    vector<vector<int>> grid2 = {
        {1,2,3},
        {4,5,6}
    };
    runTest(grid2, 12, 2);

    vector<vector<int>> grid3 = {
        {5}
    };
    runTest(grid3, 5, 3);

    vector<vector<int>> grid4 = {
        {1,2},
        {1,1}
    };
    runTest(grid4, 3, 4);

    return 0;
}