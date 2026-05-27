# 1463. Cherry Pickup II
You are given a rows x cols matrix grid representing a field of cherries where grid[i][j] represents the number of cherries that you can collect from the (i, j) cell.

You have two robots that can collect cherries for you:

    Robot #1 is located at the top-left corner (0, 0), and
    Robot #2 is located at the top-right corner (0, cols - 1).

Return the maximum number of cherries collection using both robots by following the rules below:

    From a cell (i, j), robots can move to cell (i + 1, j - 1), (i + 1, j), or (i + 1, j + 1).
    When any robot passes through a cell, It picks up all cherries, and the cell becomes an empty cell.
    When both robots stay in the same cell, only one takes the cherries.
    Both robots cannot move outside of the grid at any moment.
    Both robots should reach the bottom row in grid.

Example 1:

Input: grid = [[3,1,1],[2,5,1],[1,5,5],[2,1,1]]
Output: 24
Explanation: Path of robot #1 and #2 are described in color green and blue respectively.
Cherries taken by Robot #1, (3 + 2 + 5 + 2) = 12.
Cherries taken by Robot #2, (1 + 5 + 5 + 1) = 12.
Total of cherries: 12 + 12 = 24.

Example 2:

Input: grid = [[1,0,0,0,0,0,1],[2,0,0,0,0,3,0],[2,0,9,0,0,0,0],[0,3,0,5,4,0,0],[1,0,2,3,0,0,6]]
Output: 28
Explanation: Path of robot #1 and #2 are described in color green and blue respectively.
Cherries taken by Robot #1, (1 + 9 + 5 + 2) = 17.
Cherries taken by Robot #2, (1 + 3 + 4 + 3) = 11.
Total of cherries: 17 + 11 = 28.

---

## SOLN

 **Key Points**: Each robot has three choices in the next row. both robots must make the coice simultaneuosly. S0, there are 9 different combinations for the move to the next row. At any point, positions of the robots can be represented by ((row, column of robot 1, and column of robot 2)). We cant be greedy here. So, a form of dfs is required, calculating the max_cherries path. Both robots landing on the same sauare at any point would never result in max_cherries. 

 ```
 class Solution {
public:
    int delta[3] = {-1, 0, 1};
    
    int dfs(int r,int c1,int c2, vector<vector<int>> &grid){
        int m=grid.size();
        int n=grid[0].size();

        if(c1 == c2 || min(c1, c2)<0 || max(c1, c2)>=n) return 0; 
        if(r==m-1) return grid[r][c1]+grid[r][c2];
    
        int result=0;
        for(int c1_d : delta){
            for (int c2_d : delta){
                result = max(
                    result, 
                    dfs(r+1, c1+c1_d, c2+c2_d, grid)
                    );
            }
        }
        result = result + grid[r][c1] + grid[r][c2];

        return result;


    }

    int cherryPickup(vector<vector<int>>& grid) {
    int n=grid[0].size();
    return dfs(0, 0, n-1, grid);
    }
};
 ```

 Adding memoization

 ```
 class Solution {
public:
    int delta[3] = {-1, 0, 1};

    unordered_map <string, int> dp;   // keep track of every r, c1, c2, combo

    int dfs(int r,int c1,int c2, vector<vector<int>> &grid){
        int m=grid.size();
        int n=grid[0].size();

        if(c1 == c2 || min(c1, c2)<0 || max(c1, c2)>=n) return 0; 
        if(r==m-1) return grid[r][c1]+grid[r][c2];
        
        string key = to_string(r)+ "," + to_string(c1) + "," + to_string(c2);        
        if(dp.find(key)!=dp.end()) return dp[key];  //don't recalculate if value already available

        int result=0;
        for(int c1_d : delta){
            for (int c2_d : delta){
                result = max(                            //find the max out of the nine options
                    result, 
                    dfs(r+1, c1+c1_d, c2+c2_d, grid)
                    );
            }
        }
        dp[key] = result + grid[r][c1] + grid[r][c2];    //add it to cherries from current postion in the grid
 
        return dp[key];


    }

    int cherryPickup(vector<vector<int>>& grid) {
    int n=grid[0].size();
    return dfs(0, 0, n-1, grid);
    }
};

```

here, our map stores, a value of (r, c1, c2) this is basically a 3d array.
But we notice that for calculating each row, we only need to know the values for c1, c2 from the previos row.
So, we can basiclly make this a 2d tabulation of column*column size. and only preserving values of the previous row.

```
class Solution {
public:
    int cherryPickup(vector<vector<int>>& grid) {

        int m=grid.size();
        int n= grid[0].size();

        int delta[3]={-1, 0, 1};

        vector <vector<int>> dp(n, vector<int>(n, 0));  

        for(int r=m-1; r>=0; r--){   //start from the bottom row (this keeps logic nearly the same as that of recursion)

            vector <vector<int>> cur_dp(n, vector<int>(n, 0));

            for(int c1=0; c1<n-1; c1++){  // here, we know that the robots will never need to cross each other 
                for(int c2=c1+1; c2<n; c2++){    // we keep bound so that the robots always stick to their own side and also never land on same block

                    int max_cherries=0;
                    int cherries = grid[r][c1] + grid[r][c2];

                    //our dp here maintains an array of every c1, c2 combo of robots from the last row.
                    // for the next row, for each c1, c2 combo we will calculate new vlues using nine choices they have accessed from the dp
                    for(int c1_d: delta){
                        for(int c2_d: delta){

                            int nc1=c1+c1_d, nc2=c2+c2_d;
                            if (nc1<0 || nc2==n) continue;

                            max_cherries = max( max_cherries, cherries + dp[nc1][nc2]);    // max of nin choices + add it cherries in current grid
                        }
                    } 
                    cur_dp[c1][c2] = max_cherries;   //update the new dp
                }
            }   
            dp=cur_dp;  //only preserve dpof one row before
        }

        return dp[0][n-1];   // this is the starting combo (r=0, c1=0, c2=n-1);
    }
};

```