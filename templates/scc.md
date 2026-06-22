# Kosaraju's Algorithm

## Problem

Find all Strongly Connected Components (SCCs) in a directed graph.

## Key Observations

* SCC = maximal set of nodes where every node can reach every other node.
* If every SCC is collapsed into a single node, the resulting graph is always a DAG.
* Source SCCs in the condensation DAG finish last during DFS.

## Intuition

1. Perform DFS and store nodes in order of finishing time.
2. Reverse all graph edges (Transpose Graph).
3. Process nodes in decreasing finish time order.
4. Each DFS on the transpose graph discovers exactly one SCC.

The transpose graph prevents DFS from leaking into other SCCs.

## Algorithm

1. Run DFS on original graph and push nodes after DFS completion.
2. Build transpose graph.
3. Reset visited array.
4. Pop nodes from stack.
5. For each unvisited node, run DFS on transpose graph.
6. Each DFS traversal forms one SCC.

## Pseudocode

DFS1(u):
visited[u] = true

```
for v in adj[u]:
    if not visited[v]:
        DFS1(v)

push u into stack
```

Build Transpose:
for u:
for v in adj[u]:
transpose[v].push_back(u)

DFS2(u):
visited[u] = true

```
for v in transpose[u]:
    if not visited[v]:
        DFS2(v)
```

Main:
DFS1 on all components

```
Build transpose graph

Clear visited

while stack not empty:
    node = stack.top()
    stack.pop()

    if not visited[node]:
        DFS2(node)
        SCC++
```

## Complexity

Time: O(V + E)
Space: O(V + E)
