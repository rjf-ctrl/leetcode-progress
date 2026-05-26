# 64. Minimum Path Sum
Given a m x n grid filled with non-negative numbers, find a path from top left to bottom right, which minimizes the sum of all numbers along its path.
Note: You can only move either down or right at any point in time.

Example 1:

Input: grid = [[1,3,1],[1,5,1],[4,2,1]]
Output: 7
Explanation: Because the path 1 → 3 → 1 → 1 → 1 minimizes the sum.

Example 2:

Input: grid = [[1,2,3],[4,5,6]]
Output: 12

---

## SOLN

Can be done with a dfs using djikstar logic.
```
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

```

In qns like these don't forget **memoization**, otherwise its not DP at all.

you can also use

```
class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        
        for (int i = 1; i < m; i++) {
            grid[i][0] += grid[i-1][0];
        }
        
        for (int j = 1; j < n; j++) {
            grid[0][j] += grid[0][j-1];
        }
        
        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                grid[i][j] += min(grid[i-1][j], grid[i][j-1]);
            }
        }
        
        return grid[m-1][n-1];
    }
};
````

here, there is a trick of all the column 1 cells, can only be accessed from top and all row one cells from the left.

