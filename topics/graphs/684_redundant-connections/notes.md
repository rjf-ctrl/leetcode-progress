LEETCODE 684 - REDUNDANT CONNECTION

PROBLEM
--------
You are given a tree with n nodes and one extra edge added.

A tree:
- Is connected
- Has exactly n-1 edges
- Contains no cycles

Adding one extra edge creates exactly one cycle.

Return the edge that can be removed so that the graph becomes a tree again.

--------------------------------------------------

KEY OBSERVATION
---------------
In DSU, if two nodes already belong to the same component,
adding an edge between them creates a cycle.

Example:

1 -- 2
|    |
3 ----

Edges:
[1,2]
[1,3]
[2,3]

Process:

[1,2]
Different components -> Union

[1,3]
Different components -> Union

[2,3]
find(2) == find(3)

Both nodes already belong to the same component.

Adding this edge creates a cycle.

Answer = [2,3]

--------------------------------------------------

DSU LOGIC
---------
For every edge (u,v):

1. Find roots of u and v
2. If roots are same:
       This edge creates a cycle
       Return this edge
3. Otherwise:
       Union the two components

--------------------------------------------------

WHY IT WORKS
------------
A cycle exists if there is already a path between u and v.

If DSU says:
find(u) == find(v)

Then u and v are already connected.

Adding another edge between them creates a cycle.

--------------------------------------------------

TIME COMPLEXITY
---------------
O(E * α(N))

Practically O(E)

--------------------------------------------------

PATTERN
-------
for every edge (u,v):

    if find(u) == find(v):
        return edge

    union(u,v)