# 63. Unique Paths II
You are given an m x n integer array grid. There is a robot initially located at the top-left corner (i.e., grid[0][0]). The robot tries to move to the bottom-right corner (i.e., grid[m - 1][n - 1]). The robot can only move either down or right at any point in time.

An obstacle and space are marked as 1 or 0 respectively in grid. A path that the robot takes cannot include any square that is an obstacle.

Return the number of possible unique paths that the robot can take to reach the bottom-right corner.

---

## SOLN

Can be done using same logic as unique paths problem. except. for ebstacles.. dont calculate a res[i][j] and dont use it in any paths calculation. 
Dont forget edge cases. Always try adn think of them first. Make it a habit. If first tile is blocked, or last tile is blocked there are 0 ways to reach the end.  
**------------------------------------**
There is an alternte equally efficient soln using DFS.

````
class Solution {
public:

    int dfs(int i, int j,
            vector<vector<int>>& dp,
            vector<vector<int>>& obstacleGrid) {

        // Out of bounds
        if(i < 0 || j < 0)
            return 0;

        // Obstacle
        if(obstacleGrid[i][j] == 1)
            return 0;

        // Reached start
        if(i == 0 && j == 0)
            return 1;

        // Already computed
        if(dp[i][j] != -1)
            return dp[i][j];

        int up = dfs(i - 1, j, dp, obstacleGrid);
        int left = dfs(i, j - 1, dp, obstacleGrid);

        return dp[i][j] = up + left;
    }

    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {

        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();

        vector<vector<int>> dp(m, vector<int>(n, -1));

        return dfs(m - 1, n - 1, dp, obstacleGrid);
    }
};

```

Although, this is kinda like my unique paths wo=rong l=solution, here they make sure all the dependencies are available by using the recursion, function only returns after the calculation of all the dependencies... it is dfs since you go from dfs (2, 2), to dfs(1, 2) to dfs(0, 2) to dfs (-1, 2) for it to return (ie, deep it inot one path).




