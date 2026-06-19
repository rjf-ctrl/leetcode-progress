#include <bits/stdc++.h>
using namespace std;
class Solution {
public:

    void dfs(int r,
             int c,
             vector<vector<char>>& grid) {

        int m = grid.size();
        int n = grid[0].size();

        if(r < 0 || r >= m ||
           c < 0 || c >= n ||
           grid[r][c] == '0')
            return;

        grid[r][c] = '0';

        dfs(r + 1, c, grid);
        dfs(r - 1, c, grid);
        dfs(r, c + 1, grid);
        dfs(r, c - 1, grid);
    }

    int numIslands(vector<vector<char>>& grid) {

        int m = grid.size();
        if(m == 0) return 0;

        int n = grid[0].size();

        int islands = 0;

        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {

                if(grid[i][j] == '1') {

                    dfs(i, j, grid);
                    islands++;
                }
            }
        }

        return islands;
    }
};

void runTest(
    int testNum,
    vector<vector<char>> grid,
    int expected
) {
    Solution sol;

    int result = sol.numIslands(grid);

    cout << "Test " << testNum << ": ";

    if(result == expected) {
        cout << "PASS";
    } else {
        cout << "FAIL";
    }

    cout << "\nExpected: " << expected
         << "\nGot:      " << result
         << "\n\n";
}

int main() {

    runTest(
        1,
        {
            {'1','1','1','1','0'},
            {'1','1','0','1','0'},
            {'1','1','0','0','0'},
            {'0','0','0','0','0'}
        },
        1
    );

    runTest(
        2,
        {
            {'1','1','0','0','0'},
            {'1','1','0','0','0'},
            {'0','0','1','0','0'},
            {'0','0','0','1','1'}
        },
        3
    );

    runTest(
        3,
        {
            {'0'}
        },
        0
    );

    runTest(
        4,
        {
            {'1'}
        },
        1
    );

    runTest(
        5,
        {
            {'1','0','1','0','1'}
        },
        3
    );

    runTest(
        6,
        {
            {'1'},
            {'0'},
            {'1'},
            {'0'},
            {'1'}
        },
        3
    );

    runTest(
        7,
        {
            {'1','1'},
            {'1','1'}
        },
        1
    );

    runTest(
        8,
        {
            {'1','0'},
            {'0','1'}
        },
        2
    );

    return 0;
}