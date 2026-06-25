LC 124. Binary Tree Maximum Path Sum

Difficulty: Hard

Problem
Given the root of a binary tree, return the maximum path sum of any non-empty path.

A path is any sequence of nodes connected by parent-child edges. The path:
- Can start and end at any node.
- Must contain at least one node.
- Cannot visit a node more than once.
- Does NOT have to pass through the root.

--------------------------------------------------

Approach: Bottom-Up DFS (Tree DP)

Observation
At every node, there are two different values to consider:

1. Value returned to the parent
   - A parent can only continue ONE branch.
   - Therefore we return:
     max(root, root + left, root + right)

2. Best path passing through the current node
   - The path may include:
       left subtree + current node + right subtree
   - This path cannot be extended upward, so it is only used to update the global answer.

For every node:
- Recursively compute the best downward path from the left subtree.
- Recursively compute the best downward path from the right subtree.
- Compute:
    • root only
    • root + left
    • root + right
    • left + root + right
- Update the global maximum using all valid possibilities.
- Return the best downward path to the parent.

Time Complexity: O(N)
Each node is visited exactly once.

Space Complexity: O(H)
H = height of the tree (recursion stack).

--------------------------------------------------

Pseudo Code

solve(node):
    if node == NULL:
        return 0

    left = solve(node.left)
    right = solve(node.right)

    oneSide = max(left, right) + node.val
    onlyRoot = node.val
    throughRoot = left + right + node.val

    answer = max(answer,
                 oneSide,
                 onlyRoot,
                 throughRoot)

    return max(oneSide, onlyRoot)

Main:
    answer = -INF
    solve(root)
    return answer