# 62. Unique Paths
There is a robot on an m x n grid. The robot is initially located at the top-left corner (i.e., grid[0][0]). The robot tries to move to the bottom-right corner (i.e., grid[m - 1][n - 1]). The robot can only move either down or right at any point in time.
Given the two integers m and n, return the number of possible unique paths that the robot can take to reach the bottom-right corner.
The test cases are generated so that the answer will be less than or equal to 2 * 109.

Example 1:

Input: m = 3, n = 7
Output: 28

Example 2:

Input: m = 3, n = 2
Output: 3
Explanation: From the top-left corner, there are a total of 3 ways to reach the bottom-right corner:
1. Right -> Down -> Down
2. Down -> Down -> Right
3. Down -> Right -> Down

---

## SOLN

recursive solution:
```
class Solution {
public: 
    int up = 0;
    void path_checker(int m, int n){
        if(m==0&&n==0) {
            up++; 
            return;
        }
        
        if (m<0 || n<0) return;
        
        //left retrace
        path_checker(m, n-1);
        //up_retrace
        path_checker(m-1, n);

    }
    int uniquePaths(int m, int n) {
        path_checker(m-1,n-1);
        return up;
    }
};
```

But this is very slow, so we employ memoization.

I built a solution with top down memoization using a matrix. But my solution, tho working still TLE'd
```
class Solution {
public: 

    void solve(int x, int y, int m, int n, vector<vector<int>> &matrix){
        if(x>=m || y>=n) return;
        int up=0, left=0;
        if(x>=0 && y-1>=0)left=matrix[x][y-1];
        if(x-1>=0 && y>=0)up=matrix[x-1][y];
        matrix[x][y]=up + left;
        solve(x, y+1, m, n, matrix);
        solve(x+1, y, m, n, matrix);
        return;
    }

    int uniquePaths(int m, int n) {
        vector<vector<int>> matrix(m, vector<int>(n));

        matrix[0][0] = 1;

        solve(0, 1, m, n, matrix);
        solve(1, 0, m, n, matrix);

        return matrix[m-1][n-1];

    }
};
```
even though i was using a matrix to store values, i was recomputing values.. for example, i can reach (2, 2) from (2, 1) and (1, 2).. both of them would reach (2,2) and redo the calcuation for it. effectively doing the same as the recursion. So, i have to add a check. If a cell has been computed, skip it;

so I added 
```
if(matrix[x][y]!=0) return;
```

But this messed up the entire calculation. Bcuz now, i would stop calclating prematurely... my earlier apprach ensured that two previous cells needed to calculate the cyrent cell were filled up to 0 bcuz i reiterated. But now, if it has been filled once ven incmpletely it wont recompute. 
DP works when all the dependencies are guaranteed. 

So, a way to ensure that all dependencies are ready is to go row by row. Since only left and up are needed for every cell. 
Since we are building from a smaller subproblem towards the final solution. We call this bottom up DP.

```
class Solution {
public: 

    
    int uniquePaths(int m, int n) {
        vector<vector<int>> matrix(m, vector<int>(n, 0));

        matrix[0][0] = 1;

        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(i==0 && j==0) continue;
                int left=0, up=0;
                if(i>0) up = matrix[i-1][j];
                if(j>0) left = matrix[i][j-1];

                matrix[i][j]=up +left;
            }
        }
        return matrix[m-1][n-1];

    }
};
```

But you will notice that every cell only needs, the cell right before it in the same row and the value of that cell in the previous row. So, instead of using a matrix, one row is suficient.

```
class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<int> dp(n, 1);
        for(int i = 1; i < m; i++)
            for(int j = 1; j < n; j++)
                dp[j] += dp[j-1];   
        return dp[n-1];
    }
};
```

this is the space optimised version

