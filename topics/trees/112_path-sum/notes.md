# LC 112. Path Sum


Problem

Given the root of a binary tree and an integer targetSum, return true if the tree has a root-to-leaf path such that adding up all the values along the path equals targetSum.

A valid path:
- Starts at the root.
- Ends at a leaf.
- Must follow parent-child connections.

--------------------------------------------------

Approach: Top-Down DFS

Observation

As we move from the root towards a leaf, we continuously subtract the current node's value from the remaining target sum.

At each node:
- Include the current node in the path.
- Reduce the remaining target.
- Continue searching both subtrees.

The answer should ONLY be checked at a leaf node, since the problem asks for a root-to-leaf path.

--------------------------------------------------

Algorithm

1. If the current node is NULL, return false.
2. If the current node is a leaf:
      return (targetSum == node->val)
3. Subtract the current node's value from targetSum.
4. Recursively search the left and right subtrees.
5. Return true if either subtree contains a valid path.

--------------------------------------------------

Pseudo Code

hasPathSum(node, target):

    if node == NULL:
        return false

    if node is a leaf:
        return target == node.val

    target -= node.val

    return hasPathSum(node.left, target) OR
           hasPathSum(node.right, target)

--------------------------------------------------

Time Complexity: O(N)

Every node is visited once.

Space Complexity: O(H)

H = height of the tree due to the recursion stack.

--------------------------------------------------

Pattern

This is a Top-Down DFS problem.

State passed downward:
- Remaining target sum.

Decision made at leaf:
- Does the remaining target equal the leaf's value?

Unlike Maximum Path Sum or Diameter, there is NO global answer.