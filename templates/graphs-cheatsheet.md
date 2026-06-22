# Graph Contest Cheat Sheet (Interview + CP)

---

# 1. BFS

### Use When

* Shortest path in **unweighted graph**
* Multi-source shortest path
* Grid traversal

### Template

```cpp
queue<int> q;
vector<int> vis(n,0);

q.push(src);
vis[src]=1;

while(!q.empty()){
    int node=q.front();
    q.pop();

    for(int nei: adj[node]){
        if(!vis[nei]){
            vis[nei]=1;
            q.push(nei);
        }
    }
}
```

### Complexity

```text
O(V+E)
```

---

# 2. DFS

### Use When

* Components
* Cycle Detection
* Islands
* Bridges/SCC foundations

### Template

```cpp
void dfs(int node){
    vis[node]=1;

    for(int nei: adj[node]){
        if(!vis[nei]){
            dfs(nei);
        }
    }
}
```

---

# 3. Connected Components

```cpp
int components=0;

for(int i=0;i<n;i++){
    if(!vis[i]){
        dfs(i);
        components++;
    }
}
```

---

# 4. Cycle Detection (Undirected)

### DFS

```cpp
bool dfs(int node,int parent){

    vis[node]=1;

    for(int nei: adj[node]){

        if(!vis[nei]){
            if(dfs(nei,node))
                return true;
        }

        else if(nei!=parent){
            return true;
        }
    }

    return false;
}
```

### Questions

* LC 547
* LC 684

---

# 5. Cycle Detection (Directed)

### DFS State Method

```cpp
0 = unvisited
1 = visiting
2 = visited
```

```cpp
bool dfs(int node){

    state[node]=1;

    for(int nei: adj[node]){

        if(state[nei]==1)
            return true;

        if(state[nei]==0 && dfs(nei))
            return true;
    }

    state[node]=2;
    return false;
}
```

### Questions

* LC 207
* LC 210

---

# 6. Topological Sort (Kahn)

### Template

```cpp
queue<int> q;

for(int i=0;i<n;i++)
    if(indegree[i]==0)
        q.push(i);

while(!q.empty()){

    int node=q.front();
    q.pop();

    topo.push_back(node);

    for(int nei: adj[node]){

        indegree[nei]--;

        if(indegree[nei]==0)
            q.push(nei);
    }
}
```

### Cycle Check

```cpp
topo.size() != n
```

---

# 7. Bipartite Graph

### BFS Coloring

```cpp
queue<int> q;

color[src]=0;
q.push(src);

while(!q.empty()){

    int node=q.front();
    q.pop();

    for(int nei: adj[node]){

        if(color[nei]==-1){
            color[nei]=1-color[node];
            q.push(nei);
        }

        else if(color[nei]==color[node]){
            return false;
        }
    }
}

return true;
```

### Questions

* LC 785
* LC 886

---

# 8. Dijkstra

### Use When

```text
Positive edge weights
Shortest path
```

### Template

```cpp
priority_queue<
pair<int,int>,
vector<pair<int,int>>,
greater<pair<int,int>>
> pq;

dist[src]=0;
pq.push({0,src});

while(!pq.empty()){

    auto [d,node]=pq.top();
    pq.pop();

    if(d>dist[node]) continue;

    for(auto &[wt,nei]: adj[node]){

        if(dist[node]+wt < dist[nei]){

            dist[nei]=dist[node]+wt;

            pq.push({
                dist[nei],
                nei
            });
        }
    }
}
```

### Complexity

```text
O((V+E)logV)
```

---

# 9. Bellman Ford

### Use When

```text
Negative edges exist
```

### Relax V-1 Times

```cpp
for(int i=1;i<n;i++){

    for(auto &e: edges){

        int u=e[0];
        int v=e[1];
        int wt=e[2];

        dist[v]=min(
            dist[v],
            dist[u]+wt
        );
    }
}
```

### Detect Negative Cycle

One extra relaxation.

---

# 10. Union Find (DSU)

### Template

```cpp
int find(int x){

    if(parent[x]==x)
        return x;

    return parent[x]
        = find(parent[x]);
}
```

```cpp
void unite(int a,int b){

    a=find(a);
    b=find(b);

    if(a==b) return;

    if(rank[a]<rank[b])
        swap(a,b);

    parent[b]=a;

    if(rank[a]==rank[b])
        rank[a]++;
}
```

### Questions

* LC 547
* LC 684
* LC 1319

---

# 11. Kruskal MST

### Steps

```text
Sort edges by weight

Take edge if
find(u)!=find(v)

Union
```

### Complexity

```text
O(E log E)
```

### Question

* LC 1584

---

# 12. Prim MST

### Template

```cpp
priority_queue<
pair<int,int>,
vector<pair<int,int>>,
greater<pair<int,int>>
> pq;

pq.push({0,0});

while(!pq.empty()){

    auto [wt,node]=pq.top();
    pq.pop();

    if(vis[node]) continue;

    vis[node]=1;
    cost+=wt;

    for(auto &[nwt,nei]: adj[node]){
        if(!vis[nei]){
            pq.push({nwt,nei});
        }
    }
}
```

---

# 13. Bridges

### Condition

```cpp
low[child] > tin[parent]
```

### Update

Tree Edge

```cpp
low[u]=min(low[u],low[v]);
```

Back Edge

```cpp
low[u]=min(low[u],tin[v]);
```

### Question

* LC 1192

---

# 14. Articulation Point

### Root

```cpp
children > 1
```

### Non-root

```cpp
low[child] >= tin[node]
```

---

# 15. Kosaraju SCC

### Steps

```text
1. DFS order stack

2. Reverse graph

3. DFS in stack order
```

### Complexity

```text
O(V+E)
```

### Question

* SCC counting problems

---

# 16. Floyd Warshall

### Use When

```text
All-pairs shortest path
n ≤ 400
```

### Template

```cpp
for(int via=0;via<n;via++)
for(int i=0;i<n;i++)
for(int j=0;j<n;j++)
{
    dist[i][j]=min(
        dist[i][j],
        dist[i][via]+dist[via][j]
    );
}
```

### Complexity

```text
O(N³)
```

---

# Grid Problems Checklist

### Islands

```text
DFS/BFS
```

### Shortest Path Grid

```text
BFS
```

### Weighted Grid

```text
Dijkstra
```

### Multi-source

```text
Push all sources initially
```

Examples:

```text
LC 994 Rotting Oranges
LC 286 Walls and Gates
LC 542 01 Matrix
```

---

# Contest Recognition Guide

| Clue                             | Algorithm          |
| -------------------------------- | ------------------ |
| Components                       | DFS/BFS            |
| Unweighted shortest path         | BFS                |
| Positive weights                 | Dijkstra           |
| Negative weights                 | Bellman Ford       |
| All pairs shortest path          | Floyd Warshall     |
| MST                              | Kruskal / Prim     |
| Connectivity after removing edge | Bridges            |
| Connectivity after removing node | Articulation Point |
| Course Schedule                  | Topological Sort   |
| Grouping/Connectivity queries    | DSU                |
| Strongly Connected Components    | Kosaraju           |
| Bipartition/Two Teams            | Bipartite          |

