#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m= obstacleGrid.size();
        int n = obstacleGrid[0].size();

        if(obstacleGrid[m-1][n-1]==1 || obstacleGrid[0][0]==1) return 0;

        obstacleGrid[0][0]=1;

        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(i==0 && j==0) continue;

                if(obstacleGrid[i][j]==1) {
                    obstacleGrid[i][j] = -1;
                    continue;
                }

                int left=0, up=0;
                if(i>0) up = obstacleGrid[i-1][j]>0? obstacleGrid[i-1][j]:0;
                if(j>0) left = obstacleGrid[i][j-1]>0? obstacleGrid[i][j-1]:0;

                obstacleGrid[i][j] = left + up;
            }
        }
        
        return obstacleGrid[m-1][n-1];
    }
};
void runTest(vector<vector<int>> grid, int expected, int testNo) {
    Solution sol;
    int result = sol.uniquePathsWithObstacles(grid);

    cout << "Test Case " << testNo << ": ";

    if(result == expected) {
        cout << "PASS";
    } else {
        cout << "FAIL";
    }

    cout << "\nExpected: " << expected;
    cout << "\nGot: " << result << "\n\n";
}

int main() {

    // Test Case 1
    vector<vector<int>> grid1 = {
        {0,0,0},
        {0,1,0},
        {0,0,0}
    };
    runTest(grid1, 2, 1);

    // Test Case 2
    vector<vector<int>> grid2 = {
        {0,1},
        {0,0}
    };
    runTest(grid2, 1, 2);

    // Test Case 3
    vector<vector<int>> grid3 = {
        {1}
    };
    runTest(grid3, 0, 3);

    // Test Case 4
    vector<vector<int>> grid4 = {
        {0}
    };
    runTest(grid4, 1, 4);

    // Test Case 5
    vector<vector<int>> grid5 = {
        {0,0},
        {1,1},
        {0,0}
    };
    runTest(grid5, 0, 5);

    return 0;
}