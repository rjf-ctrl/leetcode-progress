# LC 78 - Subsets

### Problem

Given an integer array `nums` containing unique elements, return all possible subsets (the power set).

The solution set must not contain duplicate subsets.

---

## Approach - Backtracking (Loop-based DFS)

### Key Observation

Each recursive call represents **one unique subset**.

Instead of waiting until we reach the end of the array, we immediately add the current subset to the answer.

Think of recursion as standing at a node in the recursion tree:

* The current path (`temp`) is already a valid subset.
* From here, we decide which element to include next.
* Each recursive call extends the current subset by choosing one new element.

---

### Recursion Logic

1. Add the current subset to the answer.
2. Iterate through every possible next element starting from `start`.
3. Choose the current element.
4. Recurse starting from the next index.
5. Backtrack by removing the chosen element.

The `start` index ensures:

* Elements are never revisited.
* Subsets remain in sorted order.
* No duplicates are generated.

---

### Important Insight

This problem has **two valid backtracking styles**.

#### 1. Loop-based DFS (used here)

```
Save current subset

for every possible next element:
    Choose
    Recurse
    Undo choice
```

Each recursive call corresponds to **one subset**, so we save it immediately.

---

#### 2. Include / Exclude DFS

```
Take current element
Recurse

Don't take current element
Recurse
```

This also generates exactly `2^n` subsets.

---

### Common Mistake

Do **not** combine both approaches.

Incorrect:

```
for (...)
{
    Include
    Recurse

    Exclude
    Recurse
}
```

This explores many states multiple times, generating duplicate subsets and often requiring a `set` to remove duplicates.

Choose **either**

* Loop-based DFS
* Include/Exclude DFS

—not both.

---

### Complexity

Time: **O(n × 2ⁿ)**

* There are `2ⁿ` subsets.
* Copying each subset into the answer costs up to `O(n)`.

Space:

* Recursive stack: **O(n)**
* Output: **O(n × 2ⁿ)**

---

### Intuition

Think of walking through a decision tree.

Every node is already a valid subset.

The recursive call simply asks:

> "What if I include one more element from the remaining choices?"




