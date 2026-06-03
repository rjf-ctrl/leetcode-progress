# 1048. Longest String Chain

Description:
You are given an array of words where each word consists of lowercase English letters.

A word A is a predecessor of word B if and only if we can insert exactly one letter
anywhere in A without changing the order of the other characters to make it equal to B.

For example:
"abc" is a predecessor of "abac"
"ace" is a predecessor of "acbe"

A word chain is a sequence of words [word1, word2, ..., wordk] such that
word1 is a predecessor of word2,
word2 is a predecessor of word3,
...
word(k-1) is a predecessor of wordk.

Return the length of the longest possible word chain.

Examples:

Input: words = ["a","b","ba","bca","bda","bdca"]
Output: 4
Explanation:
One longest chain is:
"a" -> "ba" -> "bda" -> "bdca"

Input: words = ["xbc","pcxbcf","xb","cxbc","pcxbc"]
Output: 5

Input: words = ["abcd","dbqca"]
Output: 1

Constraints:
1 <= words.length <= 1000
1 <= words[i].length <= 16
words[i] consists of lowercase English letters.

---

Standard LIS soln. Jus figure out deciding if a predecessor of b or not.

I've used a seperate function for predecessor, but you can do it without that too.