# 55. Jump Game

You are given an integer array nums, where each element represents your maximum jump length from that position.

Starting at index 0, determine whether you can reach the last index.

Return true if the last index is reachable, otherwise return false.

---

## Solution 

### Approach: Track the Farthest Reachable Index
Key Observation
We do not need to know whether every index is reachable individually.
The only useful information is the farthest index reachable so far.

### Greedy Idea
Maintain a variable farthest.
Iterate from left to right.
If the current index is greater than farthest, this index cannot be reached, so reaching the end is impossible.
Otherwise, greedily extend the farthest reachable position:
farthest = max(farthest, i + nums[i])

### Why is it Greedy?
At every step, we keep only the maximum reachable position.
Any smaller reachable position is completely dominated by a larger one and can never provide a better future reach.
Therefore, we permanently discard inferior states without ever reconsidering them.

### Why It Works
Maintain the invariant:
Before processing index i, farthest stores the farthest index reachable using any jump from indices before i.
If i > farthest, then no previous jump can reach i, so the answer is immediately false.
Otherwise, i is reachable, and we update the farthest reachable index.

### Complexity
Time: O(n)
Space: O(1)