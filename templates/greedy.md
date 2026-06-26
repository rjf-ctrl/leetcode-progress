# Greedy Problems Cheat Sheet

## 1. What is Greedy?

A greedy algorithm makes the **best local decision** at every step and never revisits previous choices.

Greedy works only when a locally optimal choice always leads to a globally optimal solution.

---

# 2. How to Recognize a Greedy Problem

Ask yourself these questions:

### ✅ Can I make a decision now that I'll never regret later?

If yes, it's likely greedy.

Example:

* Jump Game
* Gas Station

---

### ✅ Does one state completely dominate another?

If one state is always better than another, discard the worse one.

Examples:

Jump Game

```text
Reach = 10

is always better than

Reach = 7
```

Median Finder

```text
Only largest of left half
Only smallest of right half
```

---

### ✅ Am I maintaining only a "best-so-far"?

Instead of DP over every possibility, greedy often keeps only one variable.

Examples

```text
Jump Game

farthestReach
```

```text
Partition Labels

currentEnd
```

```text
Gas Station

currentTank
```

---

### ✅ Does a failed choice eliminate many future choices?

Classic greedy property.

Example

Gas Station

If starting at station A fails at station B,

then every station between A and B also fails.

---

### ✅ Does the operation only move in one direction?

Monotonic operations are excellent greedy candidates.

Examples

Merge Triplets

```text
max()
```

Coordinates only increase.

Partition Labels

Boundary only moves right.

Jump Game

Reach only increases.

---

### ✅ Can I process left to right exactly once?

Many greedy problems become

```text
One pass

Maintain invariant
```

instead of

```text
DP
```

---

# 3. Common Greedy Patterns

---

## Pattern 1 — Maintain the Farthest Boundary

Maintain

```text
boundary = farthest possible
```

Update

```text
boundary = max(boundary, something)
```

Examples

* Jump Game
* Jump Game II
* Partition Labels

---

## Pattern 2 — Maintain a Range

Instead of one value,

maintain

```text
[min,max]
```

Examples

Valid Parenthesis String

```text
low

high
```

---

## Pattern 3 — Smallest Remaining Element

Repeatedly choose

```text
smallest remaining
```

because it is forced.

Examples

Hand of Straights

Minimum Interval

Interval Scheduling

---

## Pattern 4 — Sort Then Scan

Sort once.

Make greedy decisions.

Examples

Merge Intervals

Meeting Rooms

Erase Overlap Intervals

Minimum Arrows

---

## Pattern 5 — Greedy Expansion

Current segment expands while scanning.

Examples

Partition Labels

Jump Game II

---

## Pattern 6 — Local Replacement

Whenever a better option appears,

replace the previous one.

Examples

Task Scheduler

Maximum Subsequence

Monotonic Stack problems

---

# 4. Typical Invariants

Every greedy solution usually maintains ONE invariant.

Examples

Jump Game

```text
farthest

=

farthest reachable index so far
```

---

Jump Game II

```text
currentEnd

=

indices reachable

using current jumps
```

---

Partition Labels

```text
end

=

farthest last occurrence

seen so far
```

---

Gas Station

```text
tank

=

remaining fuel

from current candidate start
```

---

Valid Parenthesis String

```text
Every possible balance

lies inside

[low,high]
```

---

Median Finder

```text
Left heap

<=

Right heap

Size difference ≤ 1
```

---

# 5. How to Derive a Greedy Solution

Whenever you have a DP or brute-force solution, ask:

### Step 1

What information am I storing?

Example

```text
dp[i]

reachable?
```

---

### Step 2

Is all that information necessary?

Can several states be summarized?

Example

Instead of

```text
reachable indices
```

keep

```text
farthest reachable index
```

---

### Step 3

Can one state completely dominate another?

Example

Reach 10

dominates

Reach 7

Discard 7.

---

### Step 4

Can I prove a local decision is always safe?

If yes,

you have greedy.

---

# 6. Common Proof Techniques

## A.

Exchange Argument

Replace an optimal solution's first decision with the greedy one.

Nothing becomes worse.

Examples

Activity Selection

Interval Scheduling

---

## B.

Dominance

One state is never worse.

Discard weaker states.

Examples

Jump Game

Median Finder

---

## C.

Contradiction

Assume greedy is wrong.

Show contradiction.

Examples

Gas Station

Hand of Straights

---

## D.

Monotonicity

Operation only moves one direction.

Examples

Merge Triplets

Partition Labels

---

# 7. Analogy Between Common Problems

Jump Game

```text
farthest
```

↓

Partition Labels

```text
end
```

Both expand a boundary.

---

Jump Game II

```text
currentEnd

currentFarthest
```

↓

BFS Levels

Same algorithm.

---

Gas Station

```text
current candidate
```

↓

Kadane

Discard impossible prefixes.

---

Valid Parenthesis

```text
balance
```

↓

Valid Parenthesis String

```text
balance interval

[low,high]
```

---

Median Finder

```text
Two Heaps
```

↓

Partition Array

Maintain two balanced halves.

---

# 8. Interview Checklist

Whenever you think a problem may be greedy, ask:

□ Can I process left → right once?

□ Can I maintain one invariant?

□ Does one state dominate another?

□ Can failures eliminate many future choices?

□ Is there a monotonic property?

□ Is my decision irreversible?

□ Can I prove my local decision is always safe?

If you answer "Yes" to several of these, it's very likely a greedy problem.

---

# 9. Must-Know Greedy Problems

### Boundary Expansion

* Jump Game
* Jump Game II
* Partition Labels

### Candidate Elimination

* Gas Station
* Merge Triplets

### Sorting Greedy

* Merge Intervals
* Non-overlapping Intervals
* Minimum Number of Arrows
* Meeting Rooms

### Frequency Greedy

* Task Scheduler
* Hand of Straights

### Interval Greedy

* Insert Interval
* Interval List Intersections

### Range Greedy

* Valid Parenthesis String

### Heap Greedy

* IPO
* Course Schedule III
* Reorganize String
