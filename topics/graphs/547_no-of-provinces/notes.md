LEETCODE 547 - NUMBER OF PROVINCES

PROBLEM
--------
You are given an n x n adjacency matrix isConnected where:

isConnected[i][j] = 1
    -> city i and city j are directly connected

isConnected[i][j] = 0
    -> not directly connected

A province is a group of directly or indirectly connected cities.

Return the total number of provinces.

--------------------------------------------------

DFS SOLUTION

Idea:
Each province is a connected component.

1. Maintain a visited array.
2. Iterate through every city.
3. If a city is unvisited:
      - Start DFS from it.
      - Mark all reachable cities.
      - Increment province count.

Why it works:
One DFS visits exactly one connected component.

Time Complexity: O(n²)
Space Complexity: O(n)

--------------------------------------------------

UNION FIND (DSU) SOLUTION

Idea:
Initially every city is its own province.

1. Create a DSU with n cities.
2. For every pair (i,j):
      If isConnected[i][j] == 1:
           Union(i,j)
3. Count unique roots.

Why it works:
Cities in the same province end up with the same root.

Time Complexity: O(n²)
Space Complexity: O(n)

--------------------------------------------------

PATTERN RECOGNITION

Connected Components
    -> DFS/BFS

Connected Components + Merging Sets
    -> DSU / Union Find