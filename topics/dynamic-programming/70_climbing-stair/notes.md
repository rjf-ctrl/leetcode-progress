# 70. Climbing Stairs
You are climbing a staircase. It takes n steps to reach the top.
Each time you can either climb 1 or 2 steps. In how many distinct ways can you climb to the top?
Example 1:

Input: n = 2
Output: 2
Explanation: There are two ways to climb to the top.
1. 1 step + 1 step
2. 2 steps

Example 2:

Input: n = 3
Output: 3
Explanation: There are three ways to climb to the top.
1. 1 step + 1 step + 1 step
2. 1 step + 2 steps
3. 2 steps + 1 step

---

## SOLN

For every stair you can get to it by taking one step from the previous stair or two steps from the stir before that. So, to get to any given stair there are no. of ways to get to stair one before that + number of ways to get to the stair two before that. So, it can basically be reduced to the fibonacci problem. 
All orders will be included in that (just write it out).