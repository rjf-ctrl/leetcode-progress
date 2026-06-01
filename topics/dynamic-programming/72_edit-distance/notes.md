# 72. Edit Distance

Given two strings word1 and word2, return the minimum number of operations
required to convert word1 to word2.

You have the following 3 operations:
1. Insert a character
2. Delete a character
3. Replace a character

Example:
Input: word1 = "horse", word2 = "ros"
Output: 3

Constraints:
0 <= word1.length, word2.length <= 500
word1 and word2 consist of lowercase English letters.

---

## SOLN

Map this to LCS. At every point. Check if word1[i]==word[j] then go to i+1, j+1 no opration needed. else we're gonna see min operations needed for rest of the word, right or down. But at each point, you can choose to replace.. ie move i+1, j+1.. insert move i[j+1] or delete.. [i][j+1]. Use LCS alg
except for base case: at evry point, consider number operations needed with 0 length and i length.

Use neetcode io video for this
