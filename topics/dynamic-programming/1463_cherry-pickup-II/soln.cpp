#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int cherryPickup(vector<vector<int>>& grid) {

        int m=grid.size();
        int n= grid[0].size();

        int delta[3]={-1, 0, 1};

        vector <vector<int>> dp(n, vector<int>(n, 0));

        for(int r=m-1; r>=0; r--){
            vector <vector<int>> cur_dp(n, vector<int>(n, 0));

            for(int c1=0; c1<n-1; c1++){
                for(int c2=c1+1; c2<n; c2++){
                    int max_cherries=0;
                    int cherries = grid[r][c1] + grid[r][c2];
                    for(int c1_d: delta){
                        for(int c2_d: delta){
                            int nc1=c1+c1_d, nc2=c2+c2_d;
                            if (nc1<0 || nc2==n) continue;
                            max_cherries = max( max_cherries, cherries + dp[nc1][nc2]);
                        }
                    }
                    cur_dp[c1][c2] = max_cherries;
                }
            }   
            dp=cur_dp;
        }

        return dp[0][n-1];
    }
};

void runTest(vector<vector<int>> grid, int expected, int testNo) {

    Solution sol;

    int result = sol.cherryPickup(grid);

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
    vector<vector<int>> grid1 = {
        {3,1,1},
        {2,5,1},
        {1,5,5},
        {2,1,1}
    };

    runTest(grid1, 24, 1);

    // Test Case 2
    vector<vector<int>> grid2 = {
        {1,0,0,0,0,0,1},
        {2,0,0,0,0,3,0},
        {2,0,9,0,0,0,0},
        {0,3,0,5,4,0,0},
        {1,0,2,3,0,0,6}
    };

    runTest(grid2, 28, 2);

    // Test Case 3
    vector<vector<int>> grid3 = {
        {1,1},
        {1,1}
    };

    runTest(grid3, 4, 3);

    

    // Test Case 5
    vector<vector<int>> grid5 = {
        {1,2,3},
        {0,0,0},
        {7,8,9}
    };

    runTest(grid5, 21, 5);

    return 0;
}