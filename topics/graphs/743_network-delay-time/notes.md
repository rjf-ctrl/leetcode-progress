## LeetCode 743 — Network Delay Time

---

# Problem Description

You are given a directed weighted graph with:

```text
times[i] = [u, v, w]
```

meaning a signal takes `w` units of time to travel from node `u` to node `v`.

Given:

* `n` nodes numbered `1` to `n`
* Source node `k`

Return:

* The minimum time required for the signal to reach all nodes.
* Return `-1` if any node cannot be reached.

---

# Pattern

```text
Single Source Shortest Path
+
Weighted Directed Graph
+
Non-negative Edge Weights
```

Use:

```text
Dijkstra's Algorithm
```

---

# Key Observation

The signal spreads from node `k`.

We need:

```text
Shortest distance from k
to every other node
```

Once all shortest distances are known:

```text
Answer =
Maximum shortest distance
```

because the last node to receive the signal determines the total delay.

---

# Solution Logic (Dijkstra)

### Build Graph

Store adjacency list:

```cpp
adj[u].push_back({weight, neighbor});
```

---

### Distance Array

```cpp
dist[i]
```

Stores shortest known distance from source.

Initialize:

```cpp
dist[k] = 0
dist[others] = INF
```

---

### Min Heap

Store:

```cpp
{distance, node}
```

Priority queue always processes the closest node first.

```cpp
priority_queue<
    pair<int,int>,
    vector<pair<int,int>>,
    greater<pair<int,int>>
> pq;
```

---

### Relaxation

For every edge:

```text
node --wt--> neighbor
```

Check:

```cpp
if(dist[node] + wt < dist[neighbor])
```

If a shorter path is found:

```cpp
dist[neighbor] = dist[node] + wt
```

Push updated distance into heap.

---

### Stale Entry Check

Since a node can appear multiple times:

```cpp
if(currDist > dist[node])
    continue;
```

Skip outdated entries.

---

### Final Answer

If any node remains:

```cpp
INF
```

return:

```cpp
-1
```

Otherwise:

```cpp
max(dist[1..n])
```

---

# Complexity

### Time

```text
O(E log V)
```

### Space

```text
O(V + E)
```

---

# Interview Takeaway

```text
Weighted graph
+
Shortest path from one source
+
Non-negative weights

=> Dijkstra
```

Maintain:

1. Distance Array
2. Min Heap {distance, node}
3. Relaxation
4. Stale Entry Check

Answer is the maximum shortest distance from the source to any reachable node.

---

## C++ Skeleton

```cpp
vector<int> dist(n + 1, INF);

priority_queue<
    pair<int,int>,
    vector<pair<int,int>>,
    greater<pair<int,int>>
> pq;

dist[k] = 0;
pq.push({0, k});

while(!pq.empty())
{
    auto [d, node] = pq.top();
    pq.pop();

    if(d > dist[node])
        continue;

    for(auto &[wt, nbr] : adj[node])
    {
        if(d + wt < dist[nbr])
        {
            dist[nbr] = d + wt;
            pq.push({dist[nbr], nbr});
        }
    }
}
```

---

## Common Mistakes

❌ Forgetting:

```cpp
dist[k] = 0;
```

❌ Missing stale-entry check

```cpp
if(d > dist[node]) continue;
```

❌ Relaxing without checking for improvement

```cpp
if(d + wt < dist[nbr])
```
