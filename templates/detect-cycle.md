# DETECT CYCLE

## DIRECTED GRAPH

### DFS:
Logic:
Use 3 states for each node:
0 = Unvisited, 1 = Visiting (currently in DFS path), 2 = Visited (fully processed).
A cycle exists if during DFS we encounter a neighbor that is already in the Visiting state, since that means we've found a back edge to the current DFS path.

**Key Insight:**
`Visiting` = currently in recursion stack.
Encountering a `Visiting` node ⇒ back edge ⇒ cycle in directed graph.

Pseudocode:
```
DFS(node):
    state[node] = 1   // Visiting

    for neighbor in adj[node]:

        if state[neighbor] == 1:
            return true    // Cycle found

        if state[neighbor] == 0:
            if DFS(neighbor):
                return true

    state[node] = 2   // Visited
    return false


for each node:
    if state[node] == 0:
        if DFS(node):
            return false   // Cannot finish courses

return true
```

