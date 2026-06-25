### Copy-Pastable 1 — Question Description & Solution Notes

# LC 994 - Rotting Oranges

## Problem

You are given an `m x n` grid where:

* `0` → Empty cell
* `1` → Fresh orange
* `2` → Rotten orange

Every minute, every rotten orange rots its **4-directionally adjacent fresh oranges**.

Return:

* Minimum minutes required until no fresh oranges remain.
* `-1` if it is impossible.

---

## Approach (Multi-Source BFS)

This is a shortest-time spread problem.

Instead of running BFS from every rotten orange separately:

* Push **all initially rotten oranges** into the queue.
* Count total fresh oranges.
* Perform BFS level-by-level.
* Each BFS level represents **one minute**.
* Every rotten orange simultaneously infects its neighbours.

This models the real spreading process exactly.

---

## Logic

1. Traverse the grid.
2. Add every rotten orange to the queue.
3. Count fresh oranges.
4. If there are no fresh oranges, return `0`.
5. Perform BFS:

   * Process one queue level at a time.
   * Rot all adjacent fresh oranges.
   * Decrease fresh count.
   * Push newly rotten oranges into queue.
   * Increment minutes after each level.
6. If fresh oranges remain after BFS, return `-1`.
7. Otherwise return total minutes.

---

## Why Multi-Source BFS?

All rotten oranges spread **simultaneously**.

Starting BFS from every rotten orange together naturally computes the earliest time each fresh orange becomes rotten.

---

## Complexity

* **Time:** `O(m × n)`
* **Space:** `O(m × n)` (queue)

---

## Pseudocode

```text
Queue q
fresh = 0

Traverse grid:
    if rotten:
        q.push(cell)
    if fresh:
        fresh++

if fresh == 0
    return 0

minutes = 0

while q not empty AND fresh > 0

    size = q.size()

    repeat size times

        cell = q.front()
        q.pop()

        for all 4 neighbours

            if neighbour is fresh

                make rotten
                fresh--
                q.push(neighbour)

    minutes++

if fresh > 0
    return -1

return minutes
```
