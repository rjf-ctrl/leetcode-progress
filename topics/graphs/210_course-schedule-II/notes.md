#  210 - Course Schedule II

## Problem

There are `numCourses` labeled from `0` to `numCourses - 1`.

Each prerequisite pair `[a, b]` means:

* To take course `a`, you must first complete course `b`.
* This forms a directed edge: `b → a`.

Return **any valid ordering** of courses that allows all courses to be completed.

If it is impossible (graph contains a cycle), return an empty array.

---

## Approach (Topological Sort - Kahn's Algorithm)

A course can only be taken once **all its prerequisites have been completed**.

* Build the graph.
* Compute the indegree of every node.
* Push all nodes with indegree `0` into a queue.
* Repeatedly remove a node, add it to the answer, and reduce the indegree of its neighbours.
* Whenever a neighbour's indegree becomes `0`, push it into the queue.
* If every course is processed, the order is valid.
* Otherwise, a cycle exists.

---

## Logic

1. Build adjacency list.
2. Compute indegree of every course.
3. Push all courses with indegree `0` into the queue.
4. While queue is not empty:

   * Pop a course.
   * Add it to the answer.
   * Reduce indegree of its neighbours.
   * Push neighbours whose indegree becomes `0`.
5. If answer size equals `numCourses`, return it.
6. Otherwise return an empty vector.

---

## Why Kahn's Algorithm?

* A node with indegree `0` has no remaining prerequisites and can be taken immediately.
* Removing it may unlock other courses.
* If some nodes never reach indegree `0`, they belong to a cycle, making completion impossible.

---

## Complexity

* **Time:** `O(V + E)`
* **Space:** `O(V + E)`

---

## Pseudocode

```text
Build adjacency list
Compute indegree[]

Queue q

for every course
    if indegree == 0
        push into queue

answer = []

while queue not empty

    node = q.front()
    q.pop()

    answer.push_back(node)

    for each neighbour

        indegree--

        if indegree == 0
            q.push(neighbour)

if answer.size() != numCourses
    return {}

return answer
```
