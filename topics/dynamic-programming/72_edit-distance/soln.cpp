#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    int minDistance(string word1, string word2) {

        int m = word1.size();
        int n = word2.size();

        if(m == 0) return n;
        if(n == 0) return m;

        vector<vector<int>> dp(m+1, vector<int> (n+1, 0));

        for(int i = 0; i <= m; i++) {
            dp[i][0] = i;
        }

        for(int j = 0; j <= n; j++) {
            dp[0][j] = j;
        }

        for(int i = 1; i <= m; i++) {
            for(int j = 1; j <= n; j++) {
                if(word1[i-1] == word2[j-1]) {
                    dp[i][j] = dp[i-1][j-1];
                } else {
                    // Insert, Delete, or replace.
                    int insert = dp[i][j-1];
                    int del = dp[i-1][j];
                    int replace = dp[i-1][j-1];

                    dp[i][j] = 1 + min(insert, min(del, replace));
                }
            }
        }

        return dp[m][n];
    }
};

// ---------------- TESTING ----------------

void runTest(string word1, string word2, int expected) {
    Solution sol;
    int result = sol.minDistance(word1, word2);

    if (result == expected) {
        cout << "[PASS] ";
    } else {
        cout << "[FAIL] ";
    }

    cout << "word1 = \"" << word1
         << "\", word2 = \"" << word2
         << "\" | Expected = " << expected
         << ", Got = " << result << '\n';
}

int main() {

    // Sample tests
    runTest("horse", "ros", 3);
    runTest("intention", "execution", 5);

    // Edge cases
    runTest("", "", 0);
    runTest("", "abc", 3);
    runTest("abc", "", 3);

    // Same strings
    runTest("abc", "abc", 0);
    runTest("leetcode", "leetcode", 0);

    // Single character
    runTest("a", "b", 1);
    runTest("a", "ab", 1);
    runTest("ab", "a", 1);

    // General cases
    runTest("kitten", "sitting", 3);
    runTest("sunday", "saturday", 3);
    runTest("abcdef", "azced", 3);
    runTest("food", "money", 4);

    return 0;
}