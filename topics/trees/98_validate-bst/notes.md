# LC 98. Validate Binary Search Tree


Problem

Given the root of a binary tree, determine whether it is a valid Binary Search Tree (BST).

A valid BST satisfies:
- Every node in the left subtree is strictly smaller than the current node.
- Every node in the right subtree is strictly greater than the current node.
- Both left and right subtrees must themselves be valid BSTs.

--------------------------------------------------

Approach: Top-Down DFS with Value Ranges

Observation

Comparing a node only with its immediate children is NOT sufficient.

Example:

        10
       /  \
      5    15
          /  \
         6   20

Here,
- 6 < 15 ✓
- 15 > 10 ✓

But 6 is in the right subtree of 10, so it must also satisfy:

6 > 10

which it does not.

Therefore every node must satisfy the constraints imposed by ALL of its ancestors.

--------------------------------------------------

Approach

Maintain the valid range for every node.

Initially:

(-∞, +∞)

For every node:

If

node->val <= low
or
node->val >= high

then the BST property is violated.

When moving left:

Range becomes

(low, node->val)

When moving right:

Range becomes

(node->val, high)

This propagates every ancestor's constraint down the tree.

--------------------------------------------------

Algorithm

1. Start DFS with:
      low = -∞
      high = +∞
2. If the node is NULL, return true.
3. Check if the current node lies within (low, high).
4. Recurse on:
      left  -> (low, node->val)
      right -> (node->val, high)
5. Both subtrees must be valid.

--------------------------------------------------

Pseudo Code

dfs(node, low, high):

    if node == NULL:
        return true

    if node.val <= low OR node.val >= high:
        return false

    return dfs(node.left, low, node.val) AND
           dfs(node.right, node.val, high)

Main:

return dfs(root, LLONG_MIN, LLONG_MAX)

--------------------------------------------------

Important Edge Case

Do NOT use:

INT_MIN
INT_MAX

as the initial bounds.

Example:

root = INT_MAX

The check

root >= INT_MAX

would incorrectly reject a valid BST.

Instead use:

LLONG_MIN
LLONG_MAX

so every possible int value lies strictly inside the range.

--------------------------------------------------

Time Complexity: O(N)

Every node is visited exactly once.

Space Complexity: O(H)

H = height of the tree (recursion stack).

--------------------------------------------------

Pattern

This is a Top-Down DFS problem.

State passed downward:
- Valid value range (low, high)

Decision at each node:
- Does the current value satisfy every constraint inherited from its ancestors?

Unlike Diameter or Maximum Path Sum, there is no global answer.
The recursion simply returns whether the subtree is valid.