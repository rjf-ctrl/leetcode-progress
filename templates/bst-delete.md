
Approach: Recursive BST Deletion

Observation

Deleting a node depends on how many children it has.

Case 1:
Leaf Node (0 children)

Simply remove the node.

Case 2:
One Child

Replace the node with its only child.

Case 3:
Two Children

Replacing the node directly would violate the BST property.

Instead:

1. Find the inorder successor
   (smallest node in the right subtree).

2. Copy the successor's value into the current node.

3. Delete the successor from the right subtree.

The inorder successor is guaranteed to have at most one child, making the second deletion simpler.

--------------------------------------------------

Algorithm

Search for the node using the BST property.

If key < root->val:
    recurse into left subtree

If key > root->val:
    recurse into right subtree

Else:
    Node found.

Case 1:
    return nullptr

Case 2:
    return only child

Case 3:
    successor = smallest(right subtree)

    root->val = successor->val

    root->right = delete(successor)

Return the updated root.

--------------------------------------------------

Pseudo Code

delete(node, key):

    if node == NULL:
        return NULL

    if key < node.val:
        node.left = delete(node.left)

    else if key > node.val:
        node.right = delete(node.right)

    else:

        if leaf:
            return NULL

        if only left:
            return left

        if only right:
            return right

        successor = smallest(node.right)

        node.val = successor.val

        node.right = delete(node.right, successor.val)

    return node

--------------------------------------------------

Finding the Inorder Successor

findMin(node):

    while node.left exists:
        node = node.left

    return node

--------------------------------------------------

Why It Works

The recursive function always returns the updated root of the current subtree.

Whenever a subtree changes after deletion, the parent reconnects it by assigning:

root->left = ...

or

root->right = ...

This automatically updates parent pointers without explicitly storing the parent node.

--------------------------------------------------

Time Complexity

O(H)

H = height of the BST.

Balanced BST:
O(log N)

Worst Case:
O(N)

--------------------------------------------------

Space Complexity

O(H)

Recursion stack.

--------------------------------------------------

Pattern

This is a Recursive BST Modification problem.

The recursive call returns the updated subtree.

Pattern:

if key < root->val
    root->left = recurse(...)

else if key > root->val
    root->right = recurse(...)

else
    modify current node

return root

This same pattern is used in:
- LC 701 Insert into BST
- LC 450 Delete Node in BST