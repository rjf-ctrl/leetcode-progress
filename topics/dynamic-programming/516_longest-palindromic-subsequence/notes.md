# 516. Longest Palindromic Subsequence
Given a string s, find the length of the longest palindromic subsequence in s.

A subsequence is a sequence that can be derived from another sequence by deleting some or no characters without changing the order of the remaining characters.

A palindrome is a string that reads the same forward and backward.

Return the length of the longest palindromic subsequence.

Example 1:
Input: s = "bbbab"
Output: 4
Explanation:
One possible longest palindromic subsequence is "bbbb".

Example 2:
Input: s = "cbbd"
Output: 2
Explanation:
One possible longest palindromic subsequence is "bb".

Constraints:
1 <= s.length <= 1000
s consists only of lowercase English letters.

---

There's a recursive way to go about it.. stan from the (i,j) = (0, n-1). Then work your way inwards via dfs. Use memoization. At each point, if letters match, include them in palindroem, if not try max of skip left, skpi right.

````
class Solution {
public:
    int dfs(int i, int j, const string& s, vector<vector<int>>& dp) {
        if (i > j) return 0;
        if (i == j) return 1;

        if (dp[i][j] != -1) return dp[i][j];

        if (s[i] == s[j]) {
            dp[i][j] = 2 + dfs(i + 1, j - 1, s, dp);
        } else {
            dp[i][j] = max(
                dfs(i + 1, j, s, dp),
                dfs(i, j - 1, s, dp)
            );
        }

        return dp[i][j];
    }

    int longestPalindromeSubseq(string s) {
        int n = s.size();
        vector<vector<int>> dp(n, vector<int>(n, -1));

        return dfs(0, n - 1, s, dp);
    }
};
````

But the clever soln:
Reverse the string and find the longest common subsequence. That would be the longest common palindromic subsequence too.

