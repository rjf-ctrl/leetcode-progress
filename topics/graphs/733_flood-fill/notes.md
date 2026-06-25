# 733 - Flood Fill

## Problem

You are given an `m x n` image where each cell represents a pixel color.

Given:

* Starting pixel `(sr, sc)`
* New color `color`

Replace the starting pixel and **all 4-directionally connected pixels having the same original color** with the new color.

---

## Approach (DFS/BFS)

Treat the image as a graph.

* The starting pixel defines the connected component.
* Store the original color.
* Traverse only cells:

  * Inside bounds
  * Having the original color
* Paint them with the new color.
* Continue recursively (DFS) or iteratively (BFS).

---

## Important Edge Case

If the original color is already equal to the new color:

* Return immediately.
* Otherwise DFS/BFS will keep revisiting already-painted cells and may recurse infinitely (or perform unnecessary work).

---

## Logic

1. Store original color.
2. If `original == color`, return image.
3. Start DFS/BFS from `(sr, sc)`.
4. For every valid neighbour:

   * Same original color
   * Paint with new color
   * Continue traversal.
5. Return image.

---

## Complexity

* **Time:** `O(m × n)`
* **Space:**

  * DFS: `O(m × n)` recursion stack (worst case)
  * BFS: `O(m × n)` queue

---

## Pseudocode

```text
original = image[sr][sc]

if original == color
    return image

DFS(r, c):
    if out of bounds
        return

    if image[r][c] != original
        return

    image[r][c] = color

    DFS(up)
    DFS(down)
    DFS(left)
    DFS(right)

Call DFS(sr, sc)

return image
```



