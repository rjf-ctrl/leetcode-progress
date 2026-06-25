#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void dfs(int i, int j, vector<vector<int>>&image, int og, int color){
        int m=image.size();
        int n=image[0].size();
        if(i==m || j==n||i<0||j<0) return;
        image[i][j]=color;
        if(i+1<m && image[i+1][j]==og) dfs(i+1, j, image, og, color);
        if(i-1>=0 && image[i-1][j]==og) dfs(i-1, j, image, og, color);
        if(j+1<n && image[i][j+1]==og) dfs(i, j+1, image, og, color);
        if(j-1>=0 && image[i][j-1]==og) dfs(i, j-1, image, og, color);
        return;
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int m=image.size();
        int n= image[0].size();

        int og=image[sr][sc];
        if(og==color) return image;

        dfs(sr, sc, image, og, color);
        return image;
    }
};

bool equalMatrix(const vector<vector<int>>& a,
                 const vector<vector<int>>& b) {
    return a == b;
}

void printMatrix(const vector<vector<int>>& mat) {
    cout << "[\n";
    for (const auto& row : mat) {
        cout << "  [ ";
        for (int x : row) cout << x << " ";
        cout << "]\n";
    }
    cout << "]\n";
}

void runTest(int testNo,
             vector<vector<int>> image,
             int sr,
             int sc,
             int color,
             vector<vector<int>> expected) {

    Solution sol;
    auto ans = sol.floodFill(image, sr, sc, color);

    if (equalMatrix(ans, expected)) {
        cout << "Test " << testNo << " PASSED\n";
    } else {
        cout << "Test " << testNo << " FAILED\n";
        cout << "Expected:\n";
        printMatrix(expected);
        cout << "Got:\n";
        printMatrix(ans);
    }
}

int main() {

    runTest(
        1,
        {{1,1,1},
         {1,1,0},
         {1,0,1}},
        1,1,2,
        {{2,2,2},
         {2,2,0},
         {2,0,1}}
    );

    runTest(
        2,
        {{0,0,0},
         {0,0,0}},
        0,0,2,
        {{2,2,2},
         {2,2,2}}
    );

    runTest(
        3,
        {{0,0,0},
         {0,1,1}},
        1,1,1,
        {{0,0,0},
         {0,1,1}}
    );

    runTest(
        4,
        {{1}},
        0,0,2,
        {{2}}
    );

    runTest(
        5,
        {{1,2,3},
         {4,5,6},
         {7,8,9}},
        1,1,0,
        {{1,2,3},
         {4,0,6},
         {7,8,9}}
    );

    runTest(
        6,
        {{1,1,2},
         {1,2,2},
         {2,2,1}},
        0,0,3,
        {{3,3,2},
         {3,2,2},
         {2,2,1}}
    );

    return 0;
}