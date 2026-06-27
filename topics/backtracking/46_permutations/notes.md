## Copy-pastable 1: Question Description + Solution Logic

### LC 46 - Permutations

### Problem

Given an array `nums` of distinct integers, return all possible permutations.

A permutation is an arrangement of all elements where **order matters**.

---

## Approach - Backtracking (Used Array)

### Key Observation

Unlike subsets or combinations:

* We are **not** choosing a subset.
* We must use **every element exactly once**.
* **Order matters.**

At every position in the permutation, we can choose **any element that hasn't already been used.**

---

## Why can't we use a `start` index?

Suppose

```text
nums = [1,2,3]
```

After choosing

```text
2
```

the next element can still be

```text
1
```

even though its index is smaller.

Therefore, a `start` index is not sufficient.

Instead, we need to know:

> Which elements have already been used?

---

## The Used Array

Maintain

```cpp
vector<bool> used(n, false);
```

where

```text
used[i] = true
```

means

```text
nums[i]
```

is already part of the current permutation.

---

## Recursion Logic

At every recursive call:

1. If the permutation is complete, save it.
2. Iterate through every element.
3. Skip elements already used.
4. Choose the current element.
5. Mark it as used.
6. Recurse.
7. Backtrack by removing it and marking it unused.

---

## Recursion Tree

For

```text
[1,2,3]
```

```
            []
        /     |     \
      1       2       3
    /   \    /  \    /  \
   2     3  1    3  1    2
   |     |  |    |  |    |
 123   132 213 231 312 321
```

Each level fills one position in the permutation.

---

## Base Case

```cpp
if(curr.size() == nums.size())
```

All numbers have been used.

Store the permutation.

---

## Backtracking

Choose

```cpp
curr.push_back(nums[i]);
used[i] = true;
```

Undo

```cpp
curr.pop_back();
used[i] = false;
```

Backtracking restores the state so the next branch can try a different choice.

---

## Complexity

There are

```text
n!
```

possible permutations.

Each permutation takes

```text
O(n)
```

to copy into the answer.

Time:

**O(n × n!)**

Space:

* Recursion stack: **O(n)**
* Used array: **O(n)**

(Output excluded.)

---

## Pattern Recognition

Permutations use a different backtracking pattern from subsets.

### Subsets / Combination Problems

Choice:

> Which element should I consider next?

Use:

```cpp
start
```

---

### Permutations

Choice:

> Which unused element should I place in the current position?

Use:

```cpp
used[]
```

---

### Key Idea

Whenever the problem says

* Arrange elements
* Order matters
* Use every element exactly once

Think:

> **Loop through all unused elements and place one in the current position.**


