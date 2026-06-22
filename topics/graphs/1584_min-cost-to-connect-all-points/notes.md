# Min Cost to Connect All Points

## Problem Description

Given an array of points where `points[i] = [xi, yi]`, connect all points such that there is exactly one simple path between any two points.

The cost of connecting two points is the Manhattan Distance:

```text
|x1 - x2| + |y1 - y2|
```

Return the minimum cost required to connect all points.

---

## Key Observation

Treat each point as a node in a graph.

Every point can connect to every other point:

```text
Complete Undirected Weighted Graph
```

Edge weight:

```text
Manhattan Distance
```

The problem reduces to finding the:

```text
Minimum Spanning Tree (MST)
```

---

# Approach 1: Prim's Algorithm (Heap)

## Reasoning

Start with any point.

Repeatedly connect the closest point that is not yet part of the MST.

Maintain:

* Min Heap storing `(cost, node)`
* Visited array
* Minimum connection cost for each node

The heap always gives the cheapest edge that can expand the current MST.

---

## Pseudocode

```text
Initialize minHeap

Push (0, 0)

Initialize visited[]

Initialize minDist[]

while heap not empty:

    pop minimum cost node

    if node already visited:
        continue

    add cost to answer

    mark node visited

    for every other point:

        compute Manhattan distance

        if better than current minDist:

            update minDist

            push into heap

return answer
```

---

## Complexity

```text
Time  : O(n² log n)
Space : O(n)
```

---

## Notes

* Uses standard Prim with a priority queue.
* Generates multiple heap entries for the same node.
* Requires stale entry checks using visited array.

---

# Approach 2: Prim's Algorithm (Optimal O(n²))

## Reasoning

The graph is complete:

```text
E = O(n²)
```

Building and maintaining a heap is unnecessary.

Maintain:

```text
minDist[i]
```

which represents:

```text
Minimum cost required to connect node i
to the current MST
```

At each step:

1. Pick the unvisited node with minimum `minDist`.
2. Add it to MST.
3. Update connection costs for all remaining nodes.

This avoids heap operations entirely.

---

## Pseudocode

```text
Initialize minDist[]

minDist[0] = 0

Initialize inMST[]

repeat n times:

    find unvisited node with minimum minDist

    add its cost to answer

    mark node as part of MST

    for every other node:

        if not in MST:

            minDist[node] =
                min(
                    minDist[node],
                    ManhattanDistance(...)
                )

return answer
```

---

## Complexity

```text
Time  : O(n²)
Space : O(n)
```

---

## Notes

* Optimal solution for this problem.
* No adjacency list required.
* Distances are computed on demand.
* Faster than heap-based Prim because the graph is complete.

---

## Takeaway

This problem is a direct MST problem.

```text
Points     -> Nodes
Distance   -> Edge Weight
Goal       -> Minimum Spanning Tree
```

Solutions:

```text
Prim + Heap      : O(n² log n)
Prim (Optimal)   : O(n²)
```

The O(n²) Prim solution is the standard and preferred approach for LeetCode 1584.
