# Binary Tree Paths 
--------------------------------------------------

1. Root → Leaf Path

Starts at the root and ends at a leaf.


Typical DFS:

dfs(node, currentState):
    update state

    if leaf:
        process answer

    dfs(left)
    dfs(right)

Backtracking may be required if storing the actual path.

--------------------------------------------------

1. Root → Any Node

Starts at the root but may end at any node.


Usually solved with Top-Down DFS.

--------------------------------------------------

1. Any Node → Any Descendant

The path starts anywhere and only moves downward.


Usually solved using:
- Prefix Sum
or
- DFS from every node

--------------------------------------------------

1. Any Node ↔ Any Node

Can start and end at any node.
Can move through parents and children.
Cannot revisit nodes.


These are Bottom-Up DFS (Tree DP) problems.

Key observation:

Every node computes:

1. Best path passing through itself
2. Best path it can return to its parent

--------------------------------------------------

5. Root → Current Node

Very common traversal state.

Maintain information while moving downward.

Examples:
- Count Good Nodes
- Path Sum
- Binary Tree Paths

Pattern:

dfs(node, state)

update state

dfs(left)
dfs(right)

--------------------------------------------------

6. Current Node → Deepest Leaf

This is simply the HEIGHT of a subtree.

Examples:
- Maximum Depth
- Diameter
- Balanced Binary Tree

Pattern:

height(node)

returns

1 + max(leftHeight, rightHeight)

--------------------------------------------------

7. Path Through Current Node

The path enters from one child and leaves through the other.

Examples:
- Diameter
- Maximum Path Sum

Pattern:

throughNode =
leftContribution +
current +
rightContribution

This path CANNOT be returned upward.

--------------------------------------------------

The Golden Rule

Whenever a problem involves paths, ask:

✓ Where can the path START?
- Root?
- Any node?

✓ Where can the path END?
- Leaf?
- Any node?

✓ Can the path CHANGE DIRECTION?
- Only downward?
- Can go left → parent → right?

✓ What should DFS RETURN?
- Height?
- Best downward path?
- Boolean?
- Sum?

✓ Is there a GLOBAL answer?
Many tree DP problems require:
- Return one value to parent.
- Update another global answer.

--------------------------------------------------

Tree DP Pattern

Most hard tree problems follow this template:

dfs(node):

    left = dfs(node.left)
    right = dfs(node.right)

    // Use both children to compute answer at current node
    update global answer

    // Return only what parent can extend
    return best one-sided answer


--------------------------------------------------

