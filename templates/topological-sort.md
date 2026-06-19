
# BFS (Kahn's Algorithm) – Topological Sort

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

# TOPOLOGICAL SORT (DFS)

Idea:
A node is added to the answer only after all of its neighbors
(dependent nodes) have been processed.

------------------------------------------------------------

DFS(node):

    visited[node] = true

    for each neighbor in adj[node]:

        if visited[neighbor] == false:

            DFS(neighbor)

    topo.push_back(node)


TOPOLOGICAL_SORT(V, adj):

    visited = array of size V initialized to false

    topo = empty list

    for node = 0 to V-1:

        if visited[node] == false:

            DFS(node)

    reverse(topo)

    return topo

------------------------------------------------------------

Why does it work?

If there is an edge:

    u -> v

DFS guarantees that v is pushed into topo before u.

Therefore before reversing:

    [..., v, ..., u]

After reversing:

    [..., u, ..., v]

which satisfies the topological ordering requirement.

------------------------------------------------------------

Complexity:

Time  = O(V + E)
Space = O(V)
