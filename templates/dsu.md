========================
UNION FIND / DSU NOTES
========================

PURPOSE
-------
Used to:
1. Maintain connected components
2. Check if two nodes are connected
3. Merge components
4. Detect cycles in an undirected graph

Main Idea:
Each set has a representative/root.

Example:
1 - 2 - 3

parent:
1 -> 1
2 -> 1
3 -> 2

Root of all nodes = 1


DATA STRUCTURES
---------------
parent[i] = parent of node i
size[i]   = size of component rooted at i


OPERATION 1: FIND
-----------------
Returns the root of a node.

Without compression:
find(4):
4 -> 3 -> 2 -> 1

return 1

Pseudo:

find(x):
    while parent[x] != x:
        x = parent[x]
    return x


PATH COMPRESSION
----------------
While finding root, make every visited node
point directly to the root.

Pseudo:

find(x):
    if parent[x] == x:
        return x

    parent[x] = find(parent[x])

    return parent[x]

Benefit:
Future finds become almost O(1).


OPERATION 2: UNION
------------------
Merge two components.

Steps:
1. Find roots
2. If same root -> already connected
3. Otherwise merge

Pseudo:

union(a,b):

    ra = find(a)
    rb = find(b)

    if ra == rb:
        return

    parent[rb] = ra


UNION BY SIZE
-------------
Always attach smaller tree under larger tree.

Pseudo:

union(a,b):

    ra = find(a)
    rb = find(b)

    if ra == rb:
        return

    if size[ra] < size[rb]:
        swap(ra, rb)

    parent[rb] = ra
    size[ra] += size[rb]


INITIALIZATION
--------------

for i = 1 to n:
    parent[i] = i
    size[i] = 1


CYCLE DETECTION
---------------
For every edge (u,v):

if find(u) == find(v):
    cycle exists
else:
    union(u,v)

Why?
-----
If u and v already have the same root,
they are already connected.

Adding another edge between them creates
a cycle.


FULL DSU TEMPLATE
-----------------

initialize(n):

    for i = 1 to n:
        parent[i] = i
        size[i] = 1


find(x):

    if parent[x] == x:
        return x

    parent[x] = find(parent[x])

    return parent[x]


union(a,b):

    ra = find(a)
    rb = find(b)

    if ra == rb:
        return

    if size[ra] < size[rb]:
        swap(ra, rb)

    parent[rb] = ra
    size[ra] += size[rb]


INTERVIEW APPLICATIONS
----------------------
✓ Number of Connected Components
✓ Cycle Detection (Undirected Graph)
✓ Kruskal's MST
✓ Number of Provinces (LC 547)
✓ Redundant Connection (LC 684)
✓ Accounts Merge (LC 721)
✓ Making Large Island (LC 827)
✓ Most Stones Removed (LC 947)


COMPLEXITY
----------
Find  : O(α(n))
Union : O(α(n))

α(n) = Inverse Ackermann Function

Practically:
Find ≈ O(1)
Union ≈ O(1)


KEY INTERVIEW RULE
-----------------
Same Root  -> Already Connected
Different Root -> Different Components

find(u) == find(v)
=> u and v belong to the same component