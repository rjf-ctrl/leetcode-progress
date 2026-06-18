# 207. Course Schedule
There are a total of numCourses courses you have to take, labeled from 0 to numCourses - 1.   
You are given an array prerequisites where prerequisites[i] = [ai, bi] indicates that you must take course bi first if you want to take course ai.

For example, the pair [0, 1], indicates that to take course 0 you have to first take course 1.
Return true if you can finish all courses. Otherwise, return false.

Example 1:

Input: numCourses = 2, prerequisites = [[1,0]]
Output: true
Explanation: There are a total of 2 courses to take. 
To take course 1 you should have finished course 0. So it is possible.

---
## SOLN
1. (DFS)

Build an adjacency list from prerequisites, then run DFS from every unvisited node. Use 3 states: 0 = Unvisited, 1 = Visiting (currently in recursion stack), 2 = Visited (fully processed). If DFS reaches a node already in the Visiting state, a back edge exists and the graph contains a cycle. Mark nodes as Visited after exploring all neighbors to avoid reprocessing and achieve O(V + E) time.

NOTE:
Pass the state array by reference (vector<int>& state), not by value, otherwise each DFS call gets a copy and processed states are lost. Also build an adjacency list first instead of scanning the entire prerequisites array inside every DFS call. to prevent TLE.

2. (BFS / Kahn's Algorithm)

Build adjacency list and indegree array.
Push all nodes with indegree 0 into a queue.
Repeatedly remove a node, count it, and decrease the indegree of its neighbors.
If a neighbor's indegree becomes 0, push it into the queue.
If the number of processed nodes equals numCourses, no cycle exists; otherwise a cycle is present.