BIPARTITE GRAPH CHECK (BFS COLORING)

Idea:
A graph is bipartite if we can color every node using
2 colors such that no adjacent nodes have the same color.

Colors:
    -1 = uncolored
     0 = color A
     1 = color B

------------------------------------------------------------

BFS(start):

    queue.push(start)

    color[start] = 0

    while queue not empty:

        node = queue.front()
        queue.pop()

        for each neighbor in adj[node]:

            if color[neighbor] == -1:

                color[neighbor] = 1 - color[node]

                queue.push(neighbor)

            else if color[neighbor] == color[node]:

                return false

    return true

------------------------------------------------------------

IS_BIPARTITE(V, adj):

    color = array of size V initialized to -1

    for node = 0 to V-1:

        if color[node] == -1:

            if BFS(node) == false:

                return false

    return true

------------------------------------------------------------

Why does it work?

Every edge must connect nodes of opposite colors.

If we ever find:

    color[u] == color[v]

for an edge:

    u --- v

then bipartite coloring is impossible.

------------------------------------------------------------

Interview One-Liner

A graph is bipartite if it can be colored using two colors such
that no adjacent nodes share the same color. BFS assigns alternate
colors level by level and detects conflicts.

------------------------------------------------------------

Complexity

Time  : O(V + E)
Space : O(V)

------------------------------------------------------------

DFS Version

DFS(node, colorToAssign):

    color[node] = colorToAssign

    for neighbor in adj[node]:

        if color[neighbor] == -1:

            if DFS(neighbor, 1-colorToAssign) == false:
                return false

        else if color[neighbor] == color[node]:

            return false

    return true

------------------------------------------------------------

Key Fact

Graph is Bipartite
⇔ Graph contains NO odd-length cycle


***NOTE***: Make sure to run bfs/dfs on evry single node in case of multiple connected components

````
Another Interview Fact

A graph is bipartite iff it contains no odd-length cycle.

The coloring algorithm is essentially detecting odd cycles. If an odd cycle exists, eventually two adjacent nodes are forced to have the same color, triggering:

else if(color[nei] == color[node])
    return false;
````