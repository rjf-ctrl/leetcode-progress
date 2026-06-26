# 621. Task Scheduler

You are given an array of CPU tasks represented by characters and a non-negative integer n.

Each task takes one unit of time to execute. Two identical tasks must be separated by at least n intervals. During an interval, the CPU may either execute a task or remain idle.

Return the minimum number of intervals required to complete all tasks.

# Solution 1: Max Heap + Queue Simulation 

Approach: Greedy Simulation

Count the frequency of every task.
Store all frequencies in a max-heap.
Always execute the task with the highest remaining frequency.
After executing a task:
Decrease its frequency.
If it still has remaining occurrences, place it into a cooldown queue along with the earliest time it can be executed again.
At every time unit:
Execute the highest-frequency available task if possible.
Otherwise, insert an idle interval.
Move tasks whose cooldown has expired back into the heap.
Continue until both the heap and cooldown queue become empty.

### Why It Works
Executing the task with the highest remaining frequency first minimizes future idle intervals.
The cooldown queue ensures no task violates the cooldown constraint.

### Complexity
Time: O(m log 26) where m is the total schedule length (effectively O(m) since there are only 26 task types).
Space: O(26).

## Solution 2: Greedy Mathematical Formula (Optimal) 
Approach: Build the Schedule Around the Most Frequent Task

### Key Observation
The task with the highest frequency determines the minimum possible schedule.
If the maximum frequency is maxFreq, there are maxFreq - 1 gaps between its occurrences.
Each gap must contain at least n intervals.
Skeleton Construction
Each row contains one occurrence of the most frequent task followed by n cooldown positions.
Skeleton length:
(maxFreq - 1) × (n + 1)
If multiple tasks have the same maximum frequency (maxCount), they all occupy the last row.
Therefore,
Skeleton Length =
(maxFreq - 1) × (n + 1) + maxCount

### Final Answer
If there are enough remaining tasks to fill every cooldown slot, no idle intervals are needed.
In that case, the answer is simply the total number of tasks.
Therefore,
Answer =
max(
    total number of tasks,
    (maxFreq - 1) × (n + 1) + maxCount
)

### Complexity
Time: O(n)
Space: O(1) (26 task frequencies)