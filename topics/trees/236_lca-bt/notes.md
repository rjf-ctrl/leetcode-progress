LC 236. Lowest Common Ancestor of a Binary Tree

Difficulty: Medium

Problem

Given the root of a binary tree and two nodes p and q, return their Lowest Common Ancestor (LCA).

The Lowest Common Ancestor is defined as the lowest node in the tree that has both p and q as descendants (a node can be a descendant of itself).

--------------------------------------------------

Approach: Bottom-Up DFS

Observation

Each recursive call returns one of three things:

1. NULL
   Neither p nor q exists in this subtree.

2. p or q
   One of the target nodes was found in this subtree.

3. LCA
   If both targets are found in different subtrees, the current node becomes their Lowest Common Ancestor.

--------------------------------------------------

Algorithm

1. If the current node is NULL, return NULL.
2. If the current node is p or q, return the current node.
3. Recursively search the left subtree.
4. Recursively search the right subtree.
5. If both recursive calls return non-null:
      Current node is the LCA.
6. Otherwise return whichever side is non-null.
7. If both are null, return null.

--------------------------------------------------

Why it Works

If:
- p is found in the left subtree, and
- q is found in the right subtree,

then the first node where both searches meet is the Lowest Common Ancestor.

If only one subtree returns a node, both targets lie in that subtree (or one of them is the current node), so simply propagate that result upward.

--------------------------------------------------

Pseudo Code

LCA(node):

    if node == NULL:
        return NULL

    if node == p or node == q:
        return node

    left = LCA(node.left)
    right = LCA(node.right)

    if left != NULL and right != NULL:
        return node

    if left != NULL:
        return left

    return right

--------------------------------------------------

Time Complexity: O(N)

Every node is visited at most once.

Space Complexity: O(H)

H = height of the tree due to the recursion stack.

--------------------------------------------------

Pattern

This is a Bottom-Up DFS problem.

Each subtree returns information upward:

- "I found p."
- "I found q."
- "I found neither."

The parent combines the results to determine whether it is the Lowest Common Ancestor.

Unlike Diameter or Maximum Path Sum, there is no global answer.
The answer is propagated upward through the return value.