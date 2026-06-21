###Dijkstra's Algorithm (Min Heap)

---

## Problem Pattern

Given a weighted graph with **non-negative edge weights**, find the shortest distance from a source node to all other nodes.

Common Questions:

* Network Delay Time (LC 743)
* Path With Minimum Effort
* Cheapest Flights Within K Stops (modified)
* Number of Ways to Arrive at Destination
* Shortest Path in Binary Matrix (variation)

---

## Core Concepts

### Distance Array

```cpp
dist[i]
```

Stores the shortest distance found so far from the source to node `i`.

Initialization:

```cpp
dist[src] = 0;
dist[others] = INF;
```

---

### Min Heap / Priority Queue

Always process the node with the smallest known distance.

```cpp
priority_queue<
    pair<int,int>,
    vector<pair<int,int>>,
    greater<pair<int,int>>
> pq;
```

Stores:

```cpp
{distance, node}
```

---

### Relaxation

For every edge:

```text
u --wt--> v
```

Check if going through `u` improves the distance to `v`.

```cpp
if(dist[u] + wt < dist[v])
```

If yes:

```cpp
dist[v] = dist[u] + wt;
pq.push({dist[v], v});
```

This update process is called **Relaxation**.

---

## Algorithm Logic

1. Initialize distance array with INF.
2. Set source distance to 0.
3. Push source into min heap.
4. While heap is not empty:

   * Pop node with smallest distance.
   * Skip if stale/outdated.
   * Traverse all neighbors.
   * Relax every outgoing edge.
   * Push updated distances into heap.
5. Distances array contains shortest paths.

---

## Stale Entry Check

A node may appear multiple times in the heap.

Example:

```text
(10,1)
(2,1)
```

After distance improves to 2:

```cpp
if(d > dist[node]) continue;
```

Skip outdated entries.

---

## Pseudocode

```text
dist[src] = 0

push (0, src)

while heap not empty:

    pop (distance, node)

    if distance > dist[node]:
        continue

    for each neighbor:

        if dist[node] + weight < dist[neighbor]:

            dist[neighbor] =
                dist[node] + weight

            push updated pair
```

---

## Complexity

### Time

```text
O(E log V)
```

### Space

```text
O(V)
```

---


> Use a min heap to repeatedly process the closest node and relax its outgoing edges, updating the distance array whenever a shorter path is found.

WITH A FIBHEAP ITS WOULD BE O(E)*O(1);