# 130 - Surrounded Regions

## Problem

You are given an `m x n` board containing `'X'` and `'O'`.

Capture all regions surrounded by `'X'` by flipping every surrounded `'O'` into `'X'`.

Any `'O'` connected to the border (directly or indirectly) **cannot** be captured.

---

## Approach (DFS/BFS from Borders)

Instead of finding surrounded regions directly:

* Start DFS/BFS from every border `'O'`.
* Mark all border-connected `'O'` cells as **safe**.
* After traversal:

  * Flip every remaining `'O'` to `'X'`.
  * Restore the marked safe cells back to `'O'`.

The key idea is that only border-connected regions survive.

---

## Logic

1. Traverse all border cells.
2. Whenever a border cell contains `'O'`, run DFS/BFS.
3. Mark every reachable `'O'` as a temporary character (e.g. `'T'`).
4. Traverse the board again:

   * `'O'` → `'X'` (captured)
   * `'T'` → `'O'` (restore safe cells)
5. Return the modified board.

---

## Why Start from the Borders?

Every surrounded region is **not connected to any border**.

Instead of searching for surrounded regions, identify the cells that **cannot** be captured.

Everything else is automatically surrounded.

---

## Complexity

* **Time:** `O(m × n)`
* **Space:**

  * DFS: `O(m × n)` recursion stack (worst case)
  * BFS: `O(m × n)` queue

---

## Pseudocode

```text
DFS(r, c):

    if out of bounds
        return

    if board[r][c] != 'O'
        return

    board[r][c] = 'T'

    DFS(up)
    DFS(down)
    DFS(left)
    DFS(right)

Run DFS from:
    Top row
    Bottom row
    Left column
    Right column

Traverse board:

    if cell == 'O'
        cell = 'X'

    if cell == 'T'
        cell = 'O'

return board
```

