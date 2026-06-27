## Copy-pastable 1: Question Description + Solution Logic

### LC 40 - Combination Sum II

### Problem

Given a collection of candidate numbers (which **may contain duplicates**) and a target number, return all **unique** combinations where the chosen numbers sum to the target.

* Each number may be **used at most once**.
* The solution set must not contain duplicate combinations.

---

## Approach - Backtracking (Loop-based DFS)

### Key Observation

Unlike Combination Sum I:

* We **cannot reuse** an element.
* Therefore, after choosing an element, we always move to the next index.

Recursive call:

```cpp
dfs(i + 1, ...)
```

---

## Why sort the array?

Sorting places duplicates together.

Example:

```text
[10,1,2,7,6,1,5]

↓

[1,1,2,5,6,7,10]
```

Now duplicate values become adjacent, allowing us to skip repeated branches.

---

## Recursion Logic

At every recursion level:

1. Iterate through every possible next element.
2. Skip duplicate values **at the same recursion level**.
3. Choose the current element.
4. Recurse from the next index (`i + 1`).
5. Backtrack.

---

## The Duplicate Skip Rule

```cpp
if (i > start && nums[i] == nums[i - 1])
    continue;
```

This is the key line.

It means:

> Skip duplicate values **only if they would start another branch at the same recursion depth.**

---

## Why `i > start`?

Suppose

```text
1 1 2
^ ^
0 1
```

At the root (`start = 0`):

```
i = 0 → Use first 1 ✅

i = 1 → Skip second 1 ❌
```

Why?

Starting with the second `1` produces exactly the same subtree as starting with the first.

---

Now suppose we've already chosen the first `1`.

Current recursion:

```text
[1]

1 1 2
  ^
start = 1
```

Now

```
i == start
```

so the condition

```cpp
i > start
```

is **false**.

Therefore we are allowed to take the second `1`.

This correctly generates

```text
[1,1]
```

---

### Important Insight

The duplicate check **does NOT** prevent taking duplicate values.

It only prevents **starting identical branches**.

Allowed:

```text
[1,1,6]
```

Not allowed:

Two different recursion branches both beginning with

```text
1 ...
```

---

## Difference from Combination Sum I

### Combination Sum I

Unlimited reuse.

Take:

```cpp
dfs(i, ...)
```

Stay on the same index.

---

### Combination Sum II

Each element may be used only once.

Take:

```cpp
dfs(i + 1, ...)
```

Move to the next index.

---

## Base Cases

Found target

```cpp
if(target == 0)
```

Store current combination.

---

Invalid path

```cpp
if(target < 0)
    return;
```

No solution possible.

---

## Why no set is needed

Without duplicate skipping:

```
Take first 1

Take second 1
```

and

```
Take second 1
```

generate identical combinations.

Many duplicate recursion branches are explored.

Using

```cpp
if(i > start && nums[i]==nums[i-1])
```

prevents these branches entirely.

No `set` is required.

---

## Complexity

Worst case:

Time:

Exponential (backtracking)

Sorting:

```
O(n log n)
```

Backtracking dominates.

Space:

```
O(n)
```

Recursion stack (excluding output).

---

## Pattern Recognition

If the problem says

> Each element can be used **only once**

Think:

```cpp
dfs(i + 1)
```

If the array contains duplicates:

1. Sort.
2. Skip duplicate values **at the same recursion level**.

This is the standard pattern for Combination Sum II and Subsets II.

