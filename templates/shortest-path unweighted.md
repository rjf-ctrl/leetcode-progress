### BFS Shortest Path (Unweighted Graph)

#### Intuition

BFS explores nodes level-by-level. Since all edges have equal weight (1), the first time a node is visited is through the shortest possible path from the source.

#### Algorithm

1. Initialize a distance array with `-1`.
2. Set `dist[src] = 0`.
3. Push the source node into a queue.
4. While the queue is not empty:

   * Pop the front node.
   * Traverse all its neighbors.
   * If a neighbor is unvisited:

     * Set `dist[neighbor] = dist[node] + 1`
     * Push it into the queue.
5. `dist[i]` stores the shortest distance from the source to node `i`.

#### Key Observation

```
dist[neighbor] = dist[node] + 1;
```

Since BFS processes nodes in increasing order of distance, the first distance assigned to a node is guaranteed to be the shortest.

#### Complexity

* Time: **O(V + E)**
* Space: **O(V)**

#### Template

```cpp
vector<int> dist(n, -1);
queue<int> q;

dist[src] = 0;
q.push(src);

while (!q.empty()) {
    int node = q.front();
    q.pop();

    for (int nei : adj[node]) {
        if (dist[nei] == -1) {
            dist[nei] = dist[node] + 1;
            q.push(nei);
        }
    }
}
```
