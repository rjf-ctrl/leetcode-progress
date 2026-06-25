#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void bfs(vector<vector<int>>&grid, vector<vector<int>>&reachable, queue<pair<int, int>>&q){
        int m=grid.size();
        int n=grid[0].size();

        while(!q.empty()){
            auto[i, j]=q.front();
            q.pop();

            if(i+1<m && grid[i][j]<=grid[i+1][j] &&reachable[i+1][j]==-1){
                q.push({i+1, j});
                reachable[i+1][j]=1;
            }
            
            if(i-1>=0 && grid[i][j]<=grid[i-1][j]&&reachable[i-1][j]==-1){
                q.push({i-1, j});
                reachable[i-1][j]=1;
            }
            
            if(j+1<n && grid[i][j]<=grid[i][j+1]&&reachable[i][j+1]==-1){
                q.push({i, j+1});
                reachable[i][j+1]=1;
            }
            
            if(j-1>=0 && grid[i][j]<=grid[i][j-1]&&reachable[i][j-1]==-1){
                q.push({i, j-1});
                reachable[i][j-1]=1;
            }  
               
        }
        return;
        
    }
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int m=heights.size();
        int n=heights[0].size();
        queue<pair<int,int>>q;
        vector<vector<int>> result;
        vector<vector<int>>pacific(m, vector<int>(n, -1));
        for(int i=0; i<m; i++){
            q.push({i, 0});
            pacific[i][0]=1;
        }
        for(int i=0; i<n; i++){
            q.push({0, i});
            pacific[0][i]=1;
        }
        bfs(heights, pacific, q);

        vector<vector<int>>atlantic(m, vector<int>(n, -1));
        for(int i=0; i<m; i++){
            q.push({i, n-1});
            atlantic[i][n-1]=1;
        }
        for(int i=0; i<n; i++){
            q.push({m-1, i});
            atlantic[m-1][i]=1;
        }
        bfs(heights, atlantic, q);

        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(atlantic[i][j]==1&&pacific[i][j]==1)
                    result.push_back({i, j});
            }
        }
        return result;
    }
};

bool equalAns(vector<vector<int>> a, vector<vector<int>> b) {
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    return a == b;
}

void printAns(const vector<vector<int>>& ans) {
    cout << "[";
    for (const auto& cell : ans) {
        cout << "[" << cell[0] << "," << cell[1] << "]";
    }
    cout << "]\n";
}

void runTest(int testNo,
             vector<vector<int>> heights,
             vector<vector<int>> expected) {

    Solution sol;
    auto ans = sol.pacificAtlantic(heights);

    if (equalAns(ans, expected)) {
        cout << "Test " << testNo << " PASSED\n";
    } else {
        cout << "Test " << testNo << " FAILED\n";
        cout << "Expected: ";
        printAns(expected);
        cout << "Got: ";
        printAns(ans);
    }
}

int main() {

    runTest(
        1,
        {
            {1,2,2,3,5},
            {3,2,3,4,4},
            {2,4,5,3,1},
            {6,7,1,4,5},
            {5,1,1,2,4}
        },
        {
            {0,4},
            {1,3},
            {1,4},
            {2,2},
            {3,0},
            {3,1},
            {4,0}
        }
    );

    runTest(
        2,
        {
            {1}
        },
        {
            {0,0}
        }
    );

    runTest(
        3,
        {
            {1,2},
            {4,3}
        },
        {
            {0,1},
            {1,0},
            {1,1}
        }
    );

    runTest(
        4,
        {
            {10,10,10},
            {10,10,10},
            {10,10,10}
        },
        {
            {0,0},{0,1},{0,2},
            {1,0},{1,1},{1,2},
            {2,0},{2,1},{2,2}
        }
    );

    return 0;
}