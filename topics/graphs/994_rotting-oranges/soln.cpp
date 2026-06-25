

#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        vector <vector<int>> dist(m, vector<int>(n, 0));
        queue<pair<int, int>> q;
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(grid[i][j]==2){
                    q.push({i, j});
                    grid[i][j]=2;
                }
            }
        }
        int minutes=0;
        while(!q.empty()){
            auto [i, j]=q.front();
            q.pop();
                        
            if(i+1<m&&grid[i+1][j]==1){
                q.push({i+1, j});
                grid[i+1][j]=2;
                dist[i+1][j]=dist[i][j]+1;
            }
            if(i-1>=0&&grid[i-1][j]==1){
                q.push({i-1, j});
                grid[i-1][j]=2;
                dist[i-1][j]=dist[i][j]+1;

            }
            if(j+1<n&&grid[i][j+1]==1){
                q.push({i, j+1});
                grid[i][j+1]=2;
                dist[i][j+1]=dist[i][j]+1;
            }
            if(j-1>=0&&grid[i][j-1]==1){
                q.push({i, j-1});
                grid[i][j-1]=2;
                dist[i][j-1]=dist[i][j]+1;
            }
            
        }
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(grid[i][j]==1){
                    return -1;
                }
            }
        }
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                minutes=max(minutes, dist[i][j]);
            }
        }

        return minutes;
    }
};

void runTest(int testNo,
             vector<vector<int>> grid,
             int expected) {

    Solution sol;
    int ans = sol.orangesRotting(grid);

    if (ans == expected) {
        cout << "Test " << testNo << " PASSED\n";
    } else {
        cout << "Test " << testNo
             << " FAILED | Expected: "
             << expected
             << " Got: "
             << ans << "\n";
    }
}

int main() {

    runTest(
        1,
        {
            {2,1,1},
            {1,1,0},
            {0,1,1}
        },
        4
    );

    runTest(
        2,
        {
            {2,1,1},
            {0,1,1},
            {1,0,1}
        },
        -1
    );

    runTest(
        3,
        {
            {0,2}
        },
        0
    );

    runTest(
        4,
        {
            {1}
        },
        -1
    );

    runTest(
        5,
        {
            {2}
        },
        0
    );

    runTest(
        6,
        {
            {2,2,2},
            {2,1,2},
            {2,2,2}
        },
        1
    );

    runTest(
        7,
        {
            {0,0,0},
            {0,0,0}
        },
        0
    );

    runTest(
        8,
        {
            {2,1,0,2},
            {1,1,1,0},
            {0,1,2,1}
        },
        2
    );

    return 0;
}
