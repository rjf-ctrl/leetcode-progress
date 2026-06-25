# LC 1448. Count Good Nodes in Binary Tree

Problem

Given the root of a binary tree, return the number of "good" nodes.

A node X in the tree is considered good if, on the path from the root to X,
there are no nodes with a value greater than X.

The root is always a good node.

--------------------------------------------------

Approach: Top-Down DFS

Observation

Whether a node is good depends only on the maximum value seen on the path
from the root to that node.

During DFS, maintain:

currentMax = maximum node value seen from the root to the current node.

At each node:
- If node->val >= currentMax, it is a good node.
- Update currentMax.
- Continue DFS on both children.

This is a Top-Down DFS problem because information flows from parent to child.

--------------------------------------------------

Algorithm

1. Start DFS from the root.
2. Pass the maximum value seen so far.
3. If the current node's value is greater than or equal to the maximum,
   increment the answer.
4. Update the maximum.
5. Recurse on the left and right children.

--------------------------------------------------

Pseudo Code

dfs(node, currentMax):

    if node == NULL:
        return

    if node.val >= currentMax:
        answer++

    currentMax = max(currentMax, node.val)

    dfs(node.left, currentMax)
    dfs(node.right, currentMax)

Main:
    answer = 0
    dfs(root, root.val)
    return answer

--------------------------------------------------

Time Complexity: O(N)

Each node is visited exactly once.

Space Complexity: O(H)

H = height of the tree due to the recursion stack.