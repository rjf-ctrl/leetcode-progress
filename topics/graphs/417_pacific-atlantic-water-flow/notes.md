#  417 - Pacific Atlantic Water Flow

## Problem

You are given an `m x n` matrix of heights.

Water can flow from a cell to its **4-directionally adjacent** cells if the adjacent cell's height is **less than or equal** to the current cell.

The:

* **Pacific Ocean** touches the top and left borders.
* **Atlantic Ocean** touches the bottom and right borders.

Return all cells from which water can flow to **both oceans**.

---

## Approach (Reverse DFS/BFS)

Instead of checking every cell individually:

* Start DFS/BFS **from the oceans inward**.
* Reverse the direction of water flow.
* From an ocean, we can move to a neighbour only if the neighbour's height is **greater than or equal** to the current cell.
* Perform one traversal from the Pacific borders and another from the Atlantic borders.
* Cells visited in **both traversals** are the answer.

This avoids running a search from every cell.

---

## Logic

1. Create two visited matrices:

   * `pacific`
   * `atlantic`
2. Start DFS/BFS from:

   * Pacific: top row + left column.
   * Atlantic: bottom row + right column.
3. During traversal, move only to neighbours whose height is **>= current height**.
4. Mark all reachable cells.
5. Traverse the grid and collect cells visited by both matrices.

---

## Why Reverse the Flow?

Normal flow goes from **higher → lower/equal**.

Instead, begin at the oceans and travel **lower → higher/equal**.

Any cell reached in this reverse traversal can naturally send water back to that ocean.

This reduces the complexity from running DFS/BFS from every cell to just two traversals.

---

## Complexity

* **Time:** `O(m × n)`
* **Space:** `O(m × n)`

---

## Pseudocode

```text
pacificVisited = matrix(false)
atlanticVisited = matrix(false)

DFS(r, c, visited):

    mark visited

    for each neighbour

        if inside grid
        if not visited
        if neighbour height >= current height

            DFS(neighbour)

Run DFS from:
    Pacific:
        every cell in top row
        every cell in left column

Run DFS from:
    Atlantic:
        every cell in bottom row
        every cell in right column

For every cell:
    if visited by both
        add to answer

return answer
```

