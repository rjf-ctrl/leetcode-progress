# 1092. Shortest Common Supersequence
Given two strings str1 and str2, return the shortest string that has both str1 and str2 as subsequences. If there are multiple valid strings, return any of them.

A string s is a subsequence of string t if deleting some number of characters from t (possibly 0) results in the string s.

Example 1:

Input: str1 = "abac", str2 = "cab"
Output: "cabac"
Explanation: 
str1 = "abac" is a subsequence of "cabac" because we can delete the first "c".
str2 = "cab" is a subsequence of "cabac" because we can delete the last "ac".
The answer provided is the shortest such string that satisfies these properties.

Example 2:

Input: str1 = "aaaaaaaa", str2 = "aaaaaaaa"
Output: "aaaaaaaa"

---

## SOLN
Don't limit ur thining to exsct patteern copying. yhere are qns like this too.

Okay, first build the longest common subsequence matrix.
We know that final answer will have all lretters from both words.
no, go throght the strings
when str1[i]==str2[j] i++, j++ and add the current letter to the result string
when theyre not equal, both will be in the result, but which one first, for that, check.. which one will reduce the length of reuslting string.. ie adding which one first will leave behind the lcs at that point
so if dp[i+1][j]> dp[i][j+1] it means that str1[i+1:] and str2[j] have the lcs now, which means least amt of extra letters added and vice cersa if otherwise


