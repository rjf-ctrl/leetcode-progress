### Implicit Graphs

#### Intuition

In an implicit graph, nodes and edges are **not explicitly given**. Instead:

* **State = Node**
* **Valid Move = Edge**

Neighbors are generated on the fly rather than stored in an adjacency list.

#### Common Examples

* Grids (Number of Islands, Rotting Oranges)
* Word Ladder
* Open the Lock
* Sliding Puzzle
* Knight's Minimum Moves

#### BFS Pattern

```cpp
while (!q.empty()) {

    State curr = q.front();
    q.pop();

    for (State next : generateNeighbors(curr)) {

        if (visited.count(next))
            continue;

        visited.insert(next);
        q.push(next);
    }
}
```

#### Key Observation

Unlike explicit graphs:

```cpp
for (auto nei : adj[node])
```

Implicit graphs use:

```cpp
generateNeighbors(state)
```

to produce all valid next states.

#### When to Think of Implicit Graphs

If the problem involves:

* Grid cells
* Strings
* Lock combinations
* Board/Game states
* Transformations

and asks for:

* Minimum steps
* Minimum moves
* Shortest transformation/path

Think:

```text
State = Node
Move = Edge
BFS Shortest Path
```

#### Complexity

Typically:

* Time: **O(States + Transitions)**
* Space: **O(States)**

#### Pattern Recognition

Most implicit graph problems are shortest-path problems on an **unweighted graph**, making **BFS** the standard solution.
