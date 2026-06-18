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

### BFS (Kahn's Algorithm) – Topological Sort

Topological Sort:
An ordering of nodes such that for every edge A → B,
A always appears before B in the ordering.

Properties:
- Not unique.
- Only DAGs (Directed Acyclic Graphs) have a valid topological ordering.
- Kahn's Algorithm uses BFS.
- Time Complexity: O(V + E)

Core Idea:
Repeatedly remove nodes with no dependencies (indegree = 0)
and add them to the ordering. Continue until all nodes are
processed or no more nodes can be removed.

Algorithm:

1. Find the indegree of every node.
   (Indegree = number of incoming edges / prerequisites)

2. Add all nodes with indegree 0 to a queue.

3. While the queue is not empty:
   - Pop a node.
   - Add it to the topological ordering.
   - For every neighbor:
       indegree[neighbor]--
   - If any neighbor's indegree becomes 0,
       push it into the queue.

4. When the queue becomes empty:
   - If all nodes were processed,
       topological ordering exists → No Cycle.
   - If some nodes were not processed,
       a cycle exists.

Course Schedule Insight:
Treat indegree as the number of prerequisites remaining for a course.
Courses with indegree 0 can be taken immediately.
If we can process all courses, return true.
Otherwise, a cycle prevents completion.

Kahn's = Keep taking courses with 0 prerequisites; if some courses can never reach 0 prerequisites, they are trapped in a cycle.

## UNDIRECTED GRAPH

DFS

```
DFS(node, parent):

    mark node as visited

    for neighbor in adj[node]:

        if not visited[neighbor]:

            if DFS(neighbor, node):
                return true

        else if neighbor != parent:

            return true

    return false


for each node:

    if not visited[node]:

        if DFS(node, -1):
            return true

return false
```

BFS

```
BFS(start):

    mark start as visited
    push (start, -1) into queue

    while queue not empty:

        node, parent = queue.front()
        pop

        for neighbor in adj[node]:

            if not visited[neighbor]:

                mark neighbor as visited
                push (neighbor, node)

            else if neighbor != parent:

                return true

    return false


for each node:

    if not visited[node]:

        if BFS(node):
            return true

return false
```
