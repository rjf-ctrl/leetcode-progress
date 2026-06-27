# 39 - Combination Sum

Given an array of distinct integers candidates and a target integer target, return all unique combinations where the chosen numbers sum to target.

A candidate may be chosen unlimited times.
The same combination in a different order is not considered unique.
---

## Approach - Backtracking (Take / Skip)

### Key Observation

At every candidate, we have only two choices:

Take the current candidate.
Skip the current candidate.

Unlike subsets, this is not a loop-based backtracking problem.

The Important Insight

The problem allows reusing the same number multiple times.

Therefore,

If we TAKE a number

We remain at the same index.

Take 2
↓

2 3 6 7
^

We stay on 2 because we are allowed to use it again.

Recursive call:

dfs(i, target - nums[i]);
If we SKIP a number

We move to the next index.

Skip 2
↓

2 3 6 7
  ^

Once skipped, that candidate is never considered again.

Recursive call:

dfs(i + 1, target);
Why don't we "Take and Move"?

Suppose

[2,3,6,7]
target = 7

If after taking 2 we move to index 1,

Take 2

3 6 7
^

we can never pick another 2.

We would miss the valid answer

[2,2,3]

### Hence:

Take → stay
Skip → move
Base Cases
Found a combination
if(target == 0)

Current combination sums to target.

Store it.

Invalid path
if(i == nums.size() || target < 0)
    return;

Either:

no candidates remain
target became negative

This path cannot produce a valid answer.

### Why duplicates are not generated

After skipping a candidate,

dfs(i+1,...)

we never return to it.

Therefore combinations are always built in non-decreasing index order.

Example:

Allowed

[2,2,3]

Impossible

[3,2,2]

Hence no duplicate permutations are generated.

### Recursion Tree
                target=7
                   |
                candidate=2
               /           \
         Take 2            Skip 2
      (stay at i)        (i+1)
           |
      target=5
           |
      candidate=2

Notice the Take branch remains on the same candidate until we eventually choose to skip it.

### Complexity

Worst case:

Time:

O(2^T) (or exponential depending on target and candidate values)

Space:

Recursion stack: O(target / smallest_candidate)
Output excluded.

### Pattern Recognition

Whenever a problem says:

"Unlimited reuse"
"Can choose an element multiple times"

Think:

Take  -> stay at same index

Skip  -> move to next index

If the problem instead says

Each element may be used at most once

then the Take branch also moves forward.