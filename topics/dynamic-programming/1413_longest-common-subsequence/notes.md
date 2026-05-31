# LeetCode 1143 - Longest Common Subsequence

Given two strings text1 and text2, return the length
of their longest common subsequence.

A subsequence of a string is a new string generated from
the original string with some characters (can be none)
deleted without changing the relative order of the
remaining characters.

For example, "ace" is a subsequence of "abcde".

A common subsequence of two strings is a subsequence
that is common to both strings.

If there is no common subsequence, return 0.

Example 1:
Input: text1 = "abcde", text2 = "ace"
Output: 3
Explanation:
The longest common subsequence is "ace".

Example 2:
Input: text1 = "abc", text2 = "abc"
Output: 3

Example 3:
Input: text1 = "abc", text2 = "def"
Output: 0

Constraints:
1 <= text1.length, text2.length <= 1000
text1 and text2 consist of lowercase English letters.

---

## SOLN

Very standard procedure.
Take ABCDE and ACE. here both have A as starting. so we know there is a common subsqnc of size 1. so now our problem is to **return 1 + maxcommonsubsequence(BCDE , CE)**.
What if it was BCDE and ACE... here both dont start with the same letter. So, we find **maxsubsqnc(maxsbsqnc(BCDE,CE), max(CDE, ACE));**

So those are our subproblems. In this matrix.
![matrix](<Screenshot From 2026-05-31 18-18-34.png>)  
At any position (i,j). if(text1[i]==text2[j]) return 1 + matrix[i+1][j+1]. else return max(matrix[i+1][j], matrix[i][j+1]);
So we would need to move in the revers order for these values to be available.
Space optimizng that logic.

```
class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int m= text1.length();
        int n= text2.length();

        vector <int> dp(n+1, 0);

        for(int i=m-1; i>=0; i--){
            vector <int> current(n+1, 0);
            for(int j=n-1; j>=0; j--){
                if(text1[i]==text2[j]) current[j]=1+dp[j+1];
                else current[j]=max(current[j+1], dp[j]);
            }
            dp=current;
        }  
        return dp[0];
    }
};
```
you can do this same with just one vector too.