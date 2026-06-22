ADVANCED DIJKSTRA CHEAT SHEET

==================================================
1. NORMAL DIJKSTRA
==================================================

State:
    dist[node]

Heap:
    {distance, node}

Relaxation:
    newDist = dist[u] + wt

    if(newDist < dist[v])
    {
        dist[v] = newDist;
        pq.push({newDist, v});
    }

Use When:
    - Shortest Path
    - Weighted Graph
    - Non-negative Weights

Problems:
    - LC 743 Network Delay Time


==================================================
2. STATE SPACE DIJKSTRA
==================================================

Idea:
    Answer depends on more than just the node.

State:
    (node, extra_state)

Examples:
    (node, stops_used)
    (node, coupons_left)
    (node, walls_broken)

Distance:
    dist[node][state]

Heap:
    {cost, node, state}

Relaxation:
    if(newCost < dist[next][newState])
    {
        dist[next][newState] = newCost;
        pq.push({newCost, next, newState});
    }

Recognition:
    - At most K stops
    - K coupons
    - Can break K walls
    - Limited fuel

Problems:
    - LC 787 Cheapest Flights Within K Stops
    - LC 1293 Shortest Path in Grid with Obstacles Elimination


==================================================
3. GRID DIJKSTRA
==================================================

State:
    (row, col)

Distance:
    dist[r][c]

Heap:
    {cost, row, col}

Directions:
    up, down, left, right

Relaxation:
    newCost = currCost + moveCost

Recognition:
    - Weighted Grid
    - Variable movement cost

Problems:
    - LC 778 Swim in Rising Water
    - LC 1631 Path With Minimum Effort


==================================================
4. MINIMAX DIJKSTRA
==================================================

Goal:
    Minimize the maximum edge encountered.

Normal Dijkstra:
    dist[u] + wt

Minimax Dijkstra:
    max(dist[u], wt)

Relaxation:
    newCost = max(dist[u], wt)

    if(newCost < dist[v])
    {
        dist[v] = newCost;
        pq.push({newCost, v});
    }

Recognition:
    - Minimum Effort
    - Minimize Maximum
    - Minimum Worst Cost
    - Bottleneck Path

Problems:
    - LC 1631 Path With Minimum Effort
    - LC 1102 Path With Maximum Minimum Value


==================================================
5. COUNTING SHORTEST PATHS
==================================================

Maintain:
    dist[node]
    ways[node]

Initialization:
    dist[src] = 0
    ways[src] = 1

Case 1: Better Path Found

    if(newDist < dist[v])
    {
        dist[v] = newDist;
        ways[v] = ways[u];

        pq.push({newDist, v});
    }

Case 2: Another Shortest Path Found

    else if(newDist == dist[v])
    {
        ways[v] += ways[u];
    }

Recognition:
    - Number of shortest paths
    - Count minimum-cost routes
    - Number of ways

Problems:
    - LC 1976 Number of Ways to Arrive at Destination




==================================================
RELAXATION FORMULAS
==================================================

Normal:
    newCost = dist[u] + wt

State Space:
    newCost = dist[u][state] + wt

Grid:
    newCost = currCost + moveCost

Minimax:
    newCost = max(dist[u], wt)

Counting Paths:
    newDist = dist[u] + wt
    + maintain ways[]


MENTAL MODEL

Normal Dijkstra:
    State = Node

State Space Dijkstra:
    State = Node + Extra Information

Grid Dijkstra:
    State = Cell

Minimax Dijkstra:
    Replace (+) with max()

Counting Paths:
    Maintain ways[] alongside dist[]
