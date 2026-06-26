### LeetCode 45. Jump Game II

## Question Description

You are given a 0-indexed array `nums` where each element represents the maximum jump length from that position.

Starting from the first index, return the **minimum number of jumps** required to reach the last index.

It is guaranteed that you can always reach the last index.

---

## Solution: Greedy (Optimal)

**Approach:** Greedy + BFS Level Traversal

### Key Observation

* Think of the array as levels in a BFS.
* All indices reachable using the same number of jumps belong to the same level.
* Instead of deciding which index to jump to, compute how far the current level can collectively reach.
* Once the current level has been fully explored, one jump is necessary, and the next level begins.

### Variables

* `currentEnd` : Right boundary of the current level (indices reachable using the current number of jumps).
* `currentFarthest` : Farthest index reachable from any index within the current level.
* `jumps` : Number of jumps taken.

### Algorithm

* Initialize `currentEnd = 0`, `currentFarthest = 0`, `jumps = 0`.
* Traverse the array from left to right (excluding the last index).
* Continuously update:

```
currentFarthest = max(currentFarthest, i + nums[i])
```

* When `i == currentEnd`:

  * The current level has been completely explored.
  * Increment the jump count.
  * Extend the level by setting:

```
currentEnd = currentFarthest
```

### Why is it Greedy?

* At every jump, we greedily choose the **largest range** reachable with one additional jump.
* Among all indices in the current level, only the maximum reachable position matters.
* Smaller reaches are completely dominated by the farthest reach and can never produce a better answer.

### Why It Works

Maintain the invariant:

> Every index up to `currentEnd` is reachable using exactly `jumps` jumps.

While scanning this range, compute how far one more jump can reach (`currentFarthest`).

Once the entire range has been processed, another jump becomes unavoidable, so extend the reachable boundary to `currentFarthest`.

Each index is processed exactly once.

### Complexity

* **Time:** `O(n)`
* **Space:** `O(1)`
