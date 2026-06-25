# LC 230. Kth Smallest Element in a BST

Difficulty: Medium

Problem

Given the root of a Binary Search Tree (BST) and an integer k, return the kth smallest value in the tree.

--------------------------------------------------

Key Observation

The inorder traversal of a BST always visits the nodes in sorted (ascending) order.

Therefore, the kth node visited during an inorder traversal is the kth smallest element.

--------------------------------------------------

Approach 1: Inorder Traversal + Counter

Perform an inorder traversal while maintaining a counter.

Every time a node is visited:
- Decrement k.
- When k becomes 0, the current node is the answer.

Since inorder visits nodes in sorted order, the kth visited node is exactly the kth smallest.

--------------------------------------------------

Algorithm

1. Traverse the left subtree.
2. Visit the current node.
3. Decrement k.
4. If k == 0:
      Store the answer.
5. Traverse the right subtree.

--------------------------------------------------

Pseudo Code

inorder(node):

    if node == NULL:
        return

    inorder(node.left)

    k--

    if k == 0:
        answer = node.val
        return

    inorder(node.right)

--------------------------------------------------

Approach 2: Early Exit Optimization

The basic inorder traversal continues traversing even after finding the answer.

Instead, once the answer has been found, immediately stop all remaining recursive calls.

Add the condition:

if answer already found:
    return

This avoids unnecessary traversal of the remaining nodes.

--------------------------------------------------

Pseudo Code

inorder(node):

    if node == NULL OR answer found:
        return

    inorder(node.left)

    k--

    if k == 0:
        answer = node.val
        return

    inorder(node.right)

--------------------------------------------------

Time Complexity

Approach 1:
O(N)

Approach 2:
Worst Case: O(N)
Average: O(H + K)

H = height of the BST.

--------------------------------------------------

Space Complexity

O(H)

Recursion stack.

--------------------------------------------------

Pattern

This is an Inorder Traversal problem.

State maintained:
- Remaining value of k.

Observation:
- Inorder traversal of a BST produces values in sorted order.

The kth visited node is therefore the kth smallest.