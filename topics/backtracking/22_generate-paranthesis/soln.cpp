#include <bits/stdc++.h>
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector <string> ans;
    void dfs(int open, int close, string &s, int n)
{
    if (s.size() == 2*n)
    {
        ans.push_back(s);
        return;
    }

    if (open < n)
    {
        s.push_back('(');
        dfs(open+1, close, s, n);
        s.pop_back();
    }

    if (close < open)
    {
        s.push_back(')');
        dfs(open, close+1, s, n);
        s.pop_back();
    }
}
    vector<string> generateParenthesis(int n) {
        int balance=0;
        string s;
        dfs(0, 0, s, n);
        return ans;
    }
};

bool equal(vector<string> a, vector<string> b) {
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    return a == b;
}

void runTest(int n, vector<string> expected) {
    Solution sol;
    auto ans = sol.generateParenthesis(n);

    if (equal(ans, expected))
        cout << "PASS\n";
    else {
        cout << "FAIL\n";

        cout << "Expected:\n";
        for (auto &s : expected)
            cout << s << "\n";

        cout << "Got:\n";
        for (auto &s : ans)
            cout << s << "\n";
    }
}

int main() {

    runTest(
        1,
        {
            "()"
        }
    );

    runTest(
        2,
        {
            "(())",
            "()()"
        }
    );

    runTest(
        3,
        {
            "((()))",
            "(()())",
            "(())()",
            "()(())",
            "()()()"
        }
    );

    return 0;
}
