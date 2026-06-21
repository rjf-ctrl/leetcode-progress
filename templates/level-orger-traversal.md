### Level Order Traversal (BFS)

#### Intuition

Level Order Traversal visits tree nodes level by level from top to bottom. A queue is used to process all nodes of the current level before moving to the next level.

#### Algorithm

1. If the tree is empty, return.
2. Push the root into a queue.
3. While the queue is not empty:

   * Store `size = q.size()` (number of nodes in the current level).
   * Process exactly `size` nodes.
   * For each node:

     * Pop it from the queue.
     * Add its value to the current level.
     * Push its left and right children if they exist.
4. Store each level's nodes separately.

#### Key Observation

```cpp
int size = q.size();
```

`size` represents the number of nodes in the current level. Processing exactly `size` nodes ensures level-by-level traversal.

#### Zigzag Variation

Maintain a boolean flag `leftToRight`.

* If `leftToRight == true`, store nodes normally.
* Otherwise, store nodes in reverse order for that level.
* Toggle the flag after every level.

```cpp
leftToRight = !leftToRight;
```

A common optimization is:

```cpp
level[leftToRight ? i : size - 1 - i] = node->val;
```

which avoids reversing the level vector.

#### Complexity

* Time: **O(N)**
* Space: **O(W)**

Where:

* `N` = Number of nodes
* `W` = Maximum width of the tree

#### Common Applications

* Binary Tree Level Order Traversal (LC 102)
* Binary Tree Zigzag Level Order Traversal (LC 103)
* Average of Levels in Binary Tree (LC 637)
* Binary Tree Right Side View (LC 199)
* Maximum Level Sum of a Binary Tree (LC 1161)
* Minimum Depth of Binary Tree (LC 111)

#### Template

```cpp
queue<TreeNode*> q;
q.push(root);

while (!q.empty()) {

    int size = q.size();
    vector<int> level;

    for (int i = 0; i < size; i++) {

        TreeNode* node = q.front();
        q.pop();

        level.push_back(node->val);

        if (node->left)
            q.push(node->left);

        if (node->right)
            q.push(node->right);
    }

    ans.push_back(level);
}
```

**Pattern Recognition:** Whenever you see **level-wise processing**, **nodes at depth k**, **zigzag order**, or **one level at a time**, think **BFS + Queue + `size = q.size()`**.
