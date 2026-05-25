#include <bits/stdc++.h>
using namespace std;

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

void runTest(int m, int n, int expected) {
    Solution sol;
    
    int got = sol.uniquePaths(m, n);

    cout << "Input: m = " << m << ", n = " << n << endl;
    cout << "Expected: " << expected << endl;
    cout << "Got: " << got << endl;

    if(got == expected)
        cout << "PASS\n";
    else
        cout << "FAIL\n";

    cout << "--------------------------\n";
}

int main() {

    // LeetCode 62 Test Cases

    runTest(3, 7, 28);

    runTest(3, 2, 3);

    runTest(7, 3, 28);

    runTest(3, 3, 6);

    runTest(1, 1, 1);

    runTest(1, 10, 1);

    runTest(10, 1, 1);

    runTest(10, 10, 48620);

    return 0;
}