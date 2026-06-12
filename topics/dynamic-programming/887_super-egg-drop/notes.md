# 887. Super Egg Drop
You are given k identical eggs and you have access to a building with n floors labeled from 1 to n.

You know that there exists a floor f where 0 <= f <= n such that any egg dropped at a floor higher than f will break, and any egg dropped at or below floor f will not break.

Each move, you may take an unbroken egg and drop it from any floor x (where 1 <= x <= n). If the egg breaks, you can no longer use it. However, if the egg does not break, you may reuse it in future moves.

Return the minimum number of moves that you need to determine with certainty what the value of f is.

Example 1:

Input: k = 1, n = 2
Output: 2
Explanation: 
Drop the egg from floor 1. If it breaks, we know that f = 0.
Otherwise, drop the egg from floor 2. If it breaks, we know that f = 1.
If it does not break, then we know f = 2.
Hence, we need at minimum 2 moves to determine with certainty what the value of f is.

---
## SOLN

1. Start with recursion

trial(floors, eggs)

For each floor x:
    Breaks   -> trial(x-1, eggs-1)
    Survives -> trial(floors-x, eggs)

Answer:
    min_x(
        1 + max(breaks, survives)
    )

Key idea:
Choose the floor that minimizes the worst-case outcome.


2. Add Memoization

State:
dp[floors][eggs]

Stores:
Minimum moves needed.

Complexity:
O(eggs * floors²)


3. DP Table / Tabulation

dp[e][f]

For each egg count:
    For each floor count:
        Try every possible first drop floor.

Transition:
dp[e][f] =
min_x(
    1 + max(
        dp[e-1][x-1],
        dp[e][f-x]
    )
)


4. Optimization Insight

For a chosen floor x:

breaks   = dp[e-1][x-1]  ↑ increasing
survives = dp[e][f-x]    ↓ decreasing

The curves cross once.

Therefore:
Use Binary Search instead of trying all floors.

Complexity:
O(eggs * floors * log(floors))


5. Standard Accepted Solution

Change state.

dp[moves][eggs]
=
maximum floors testable

Recurrence:

dp[m][e]
=
dp[m-1][e-1]
+
dp[m-1][e]
+
1

Complexity:
O(eggs * answer)
≈ O(eggs * log(floors))


--------------------------------

CHEATSHEET

State 1:
dp[e][f]
= minimum moves needed

State 2 (optimal):
dp[m][e]
= maximum floors testable

Egg breaks:
    eggs-1
    lower floors

Egg survives:
    same eggs
    upper floors

Egg Drop is a MINIMAX DP:
    choose best floor
    prepare for worst outcome

Pattern:
min(
    max(
        break_case,
        survive_case
    )
)
