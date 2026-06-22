# Bridges in Graphs

## Problem

Find all edges whose removal disconnects the graph.

A bridge is an edge that does not belong to any cycle.

## Key Concepts

tin[node]

* Discovery time during DFS.

low[node]

* Earliest discovery time reachable from the node's subtree using tree edges and at most one back edge.

## Intuition

For a DFS tree edge:

u ---- v

Ask:

Can v's subtree reach u or an ancestor of u through another path?

If yes:

* Not a bridge.

If no:

* Bridge.

## Bridge Condition

For a DFS tree edge (u,v):

low[v] > tin[u]

If true:
(u,v) is a bridge.

Reason:
v's subtree cannot reach u or any ancestor of u without using edge (u,v).

## Algorithm

DFS(u,parent):

```
tin[u] = low[u] = timer++

for each v:

    if v == parent:
        continue

    if not visited[v]:

        DFS(v,u)

        low[u] =
            min(low[u], low[v])

        if low[v] > tin[u]:
            bridge found

    else:

        low[u] =
            min(low[u], tin[v])
```

## Pseudocode

DFS(u,parent):

```
visited[u] = true

tin[u] = low[u] = timer++

for v in adj[u]:

    if v == parent:
        continue

    if not visited[v]:

        DFS(v,u)

        low[u] =
            min(low[u], low[v])

        if low[v] > tin[u]:
            bridges.push_back({u,v})

    else:

        low[u] =
            min(low[u], tin[v])
```

## Complexity

Time: O(V + E)

Space: O(V)

## Interview Memory Trick

For edge:

u ---- v

If v's subtree cannot climb back to u or above:

low[v] > tin[u]

Bridge Found.
