Rod cutting problem
Given a rod of length N inches and an array price[] where price[i] denotes the value of a piece of rod of length i inches (1-based indexing). Determine the maximum value obtainable by cutting up the rod and selling the pieces. Make any number of cuts, or none at all, and sell the resulting pieces.

Example 1

Input: price = [1, 6, 8, 9, 10, 19, 7, 20], N = 8

Output: 25

Explanation: Cut the rod into lengths of 2 and 6 for a total price of 6 + 19= 25.

Example 2

Input: price = [1, 5, 8, 9], N = 4

Output: 10

Explanation: Cut the rod into lengths of 2 and 2 for a total price of 5 + 5 = 10.

---

## SOLN

Classic unbounded knapsack. (used forward loop bcus repition allowed).
