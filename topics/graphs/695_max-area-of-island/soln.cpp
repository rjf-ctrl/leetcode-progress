#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int dfs(int i, int j, vector <vector<int>>&grid){
        if(i<0 || j<0|| i==grid.size() || j==grid[0].size()) return 0;
        if(grid[i][j]==0) return 0;
        grid[i][j]=0;
        int area=1;
        area+=dfs(i+1, j, grid);        
        area+=dfs(i-1, j, grid);        
        area+=dfs(i, j+1, grid);        
        area+=dfs(i, j-1, grid);  

        return area;   
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        int max_area=0;
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(grid[i][j]==1){
                    max_area=max(max_area, dfs(i, j, grid));
                }
            }
        }

        return max_area;
    }
};

int main() {

    Solution sol;

    // PASS 1
    {
        vector<vector<int>> grid = {
            {0,0,1,0,0},
            {0,1,1,1,0},
            {0,0,1,0,0},
            {0,0,0,0,0}
        };

        int expected = 5;

        cout << "PASS 1\n";
        cout << "Expected: 5\n";
        cout << "Actual  : " << sol.maxAreaOfIsland(grid) << "\n\n";
    }

    // PASS 2
    {
        vector<vector<int>> grid = {
            {1,1,0,0},
            {1,1,0,1},
            {0,0,0,1},
            {1,1,1,1}
        };

        int expected = 6;

        cout << "PASS 2\n";
        cout << "Expected: 6\n";
        cout << "Actual  : " << sol.maxAreaOfIsland(grid) << "\n\n";
    }

    // PASS 3
    {
        vector<vector<int>> grid = {
            {1}
        };

        int expected = 1;

        cout << "PASS 3\n";
        cout << "Expected: 1\n";
        cout << "Actual  : " << sol.maxAreaOfIsland(grid) << "\n\n";
    }

    // PASS 4
    {
        vector<vector<int>> grid = {
            {0}
        };

        int expected = 0;

        cout << "PASS 4\n";
        cout << "Expected: 0\n";
        cout << "Actual  : " << sol.maxAreaOfIsland(grid) << "\n\n";
    }

    // PASS 5
    {
        vector<vector<int>> grid = {
            {1,1,1},
            {1,1,1},
            {1,1,1}
        };

        int expected = 9;

        cout << "PASS 5\n";
        cout << "Expected: 9\n";
        cout << "Actual  : " << sol.maxAreaOfIsland(grid) << "\n\n";
    }

    // PASS 6
    {
        vector<vector<int>> grid = {
            {1,0,1,0},
            {0,1,0,1},
            {1,0,1,0}
        };

        int expected = 1;

        cout << "PASS 6\n";
        cout << "Expected: 1\n";
        cout << "Actual  : " << sol.maxAreaOfIsland(grid) << "\n\n";
    }

    /*
    FAIL CASES (Common Mistakes)

    1. Forgetting to mark a cell visited

       Example:
       1 1
       1 1

       Causes infinite recursion or repeated counting.



    2. Using diagonal directions

       Example:
       1 0
       0 1

       Expected: 1

       If diagonals are considered:
       Wrong Answer: 2



    3. Boundary check after accessing grid[nr][nc]

       Wrong:

           if(grid[nr][nc] == 1 && nr >= 0 ...)

       May cause out-of-bounds access.



    4. Not resetting island area for each DFS

       Example:
       1 0 1

       Expected: 1

       Global area accumulation may return 2.



    5. Returning number of islands instead of maximum area

       Example:
       1 0 1

       Expected: 1

       Number of islands = 2
       Wrong Answer = 2



    6. Forgetting to update max_area

       Example:
       1 1 1

       Expected: 3

       Wrong Answer: 0
    */

    return 0;
}