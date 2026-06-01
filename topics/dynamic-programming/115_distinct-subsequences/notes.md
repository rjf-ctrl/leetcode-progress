# 115. Distinct Subsequences

Description:
Given two strings s and t, return the number of distinct subsequencesof s which equals t.

A subsequence of a string is a new string generated from the original string with some characters (possibly none) deleted without changing the relative order of the remaining characters.

Examples:

Example 1:
Input:
s = "rabbbit"
t = "rabbit"

Output:
3

Explanation:
There are 3 ways to delete one of the three 'b' characters from "rabbbit" to form "rabbit".

Example 2:
Input:
s = "babgbag"
t = "bag"

Output:
5

---

## SOLN

Logic is very straight forward. traverse s[i] and t[j]. when s[i]==t[j] you can chose to either include this in the subsequence ->[i+1][j+1] OR skip this letter and see if the same letter comes again ->[i+1][j](we're still looking for a match for j); when s[i]!=t[j], ->[i+1][j] still looking for a match for j

Use LCS logic to implement this
