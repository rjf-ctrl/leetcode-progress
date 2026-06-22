# Minimum Spanning Tree

## Definition

A Minimum Spanning Tree (MST) of a connected, undirected, weighted graph is a subset of edges that:

* Connects all vertices.
* Contains no cycles.
* Has exactly `V - 1` edges.
* Has the minimum possible total edge weight.

---

## Important Properties

* MST exists only for connected graphs.
* MST contains exactly `V - 1` edges.
* Multiple MSTs may exist if edge weights are repeated.
* Cut Property:

  * The minimum weight edge crossing any cut is safe to include in an MST.

---

# Prim's Algorithm

## Idea

Start from any node and repeatedly add the minimum weight edge that connects the current MST to an unvisited node.

## Data Structures

* Adjacency List
* Min Heap `(weight, node)`
* Visited Array

## Pseudocode

```text
mstCost = 0

push (0, startNode) into minHeap

while minHeap not empty:

    (wt, node) = pop minimum

    if node already visited:
        continue

    mark node visited

    mstCost += wt

    for each (neighbor, edgeWeight):

        if neighbor not visited:
            push (edgeWeight, neighbor)

return mstCost
```

## Complexity

```text
Time  : O(E log V)
Space : O(V + E)
```

## Important Points

* Similar to Dijkstra.
* Heap stores edge weights, not shortest distances.
* Does not require DSU.
* Best suited when graph is given as an adjacency list.

---

# Kruskal's Algorithm

## Idea

Process edges in increasing order of weight and include an edge only if it does not form a cycle.

## Data Structures

* Edge List
* DSU / Union Find

## Pseudocode

```text
sort edges by weight

mstCost = 0

for each edge (u, v, w):

    if find(u) != find(v):

        union(u, v)

        mstCost += w

return mstCost
```

## Complexity

```text
Sorting : O(E log E)
DSU     : O(E α(V))

Total   : O(E log E)
```

## Important Points

* Requires DSU for cycle detection.
* Works directly on edge lists.
* Particularly useful when edges are already available as `(u, v, w)`.
* MST is complete after selecting `V - 1` edges.

---

# Prim vs Kruskal

| Feature         | Prim                 | Kruskal                |
| --------------- | -------------------- | ---------------------- |
| Approach        | Grow MST from a node | Process edges globally |
| Data Structure  | Min Heap             | DSU                    |
| Input           | Adjacency List       | Edge List              |
| Cycle Detection | Visited Array        | Union Find             |
| Time Complexity | O(E log V)           | O(E log E)             |

## Memory Aid

```text
Prim     = Dijkstra for MST
Kruskal  = Sort Edges + DSU
```
