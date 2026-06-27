#include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <set>
using namespace std;
class Solution {
public:
    unordered_set<int> col, negd, posd;
    vector<vector<string>> result;
    void dfs(int r, int n, vector<string >&s){
        if(r==n){
            result.push_back(s);
            return;
        }
        string temp(n, '.');
        for(int c=0; c<n; c++){
            if(!col.count(c)&&!negd.count(r-c)&&!posd.count(r+c)){
                col.insert(c);
                negd.insert(r-c);
                posd.insert(r+c);
                temp[c]='Q';
                s.push_back(temp);
                dfs(r+1, n, s);
                temp[c] = '.';
                s.pop_back();
                col.erase(c);
                negd.erase(r-c);
                posd.erase(r+c);
            }
        }
        return;
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<string> s;
        dfs(0, n, s);
        return result;
    }
};
bool equal(vector<vector<string>> a, vector<vector<string>> b) {
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    return a == b;
}

void runTest(int n, vector<vector<string>> expected) {
    Solution sol;
    auto ans = sol.solveNQueens(n);

    if (equal(ans, expected))
        cout << "PASS\n";
    else {
        cout << "FAIL\n";

        cout << "Expected:\n";
        for (auto &board : expected) {
            for (auto &row : board)
                cout << row << "\n";
            cout << "\n";
        }

        cout << "Got:\n";
        for (auto &board : ans) {
            for (auto &row : board)
                cout << row << "\n";
            cout << "\n";
        }
    }
}

int main() {

    runTest(
        1,
        {
            {
                "Q"
            }
        }
    );

    runTest(
        4,
        {
            {
                ".Q..",
                "...Q",
                "Q...",
                "..Q."
            },
            {
                "..Q.",
                "Q...",
                "...Q",
                ".Q.."
            }
        }
    );

    return 0;
}
