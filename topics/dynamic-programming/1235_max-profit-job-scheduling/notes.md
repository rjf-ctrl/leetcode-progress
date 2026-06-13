# 1235. Maximum Profit in Job Scheduling
We have n jobs, where every job is scheduled to be done from startTime[i] to endTime[i], obtaining a profit of profit[i].

You're given the startTime, endTime and profit arrays, return the maximum profit you can take such that there are no two jobs in the subset with overlapping time range.

If you choose a job that ends at time X you will be able to start another job that starts at time X.
Example 1:

Input: startTime = [1,2,3,3], endTime = [3,4,5,6], profit = [50,10,40,70]
Output: 120
Explanation: The subset chosen is the first and fourth job. 
Time range [1-3]+[3-6] , we get profit of 120 = 50 + 70.

---

## SOLN

Each job:
(start, end, profit)

For every job i:
1. Skip it
    profit = dfs(i+1)
2. Take it
    profit = jobs[i].profit + dfs(next)
Answer:
    max(skip, take)

--------------------------------

STATE
dfs(i)
Meaning:
Maximum profit obtainable starting from job i.
Memo:
dp[i] = answer for dfs(i)

--------------------------------

PREPROCESSING
Create:
(start, end, profit)
Sort by start time.
Why?
Because after taking a job we need to quickly find
the next non-overlapping job.

--------------------------------

FINDING NEXT JOB

Need first job whose:
start >= current_job.end
Since jobs are sorted by start time:
next =
lower_bound(
    starts.begin(),
    starts.end(),
    currentEnd
)


RECURRENCE
skip = dfs(i+1)

take = profit[i] + dfs(next)
dp[i] = max(skip, take)


BASE CASE

if(i >= n)
    return 0

--------------------------------

COMPLEXITY

States:
    O(n)

Work per state:
    O(log n)

Total:
    O(n log n)

Space:
    O(n)

--------------------------------

WHY BINARY SEARCH?

Naive:

For every job,
    scan forward to find next compatible job

Cost:
    O(n²)

Observation:

Jobs are sorted by start time.

Need first start >= end.

This is exactly a lower_bound.

Cost:
    O(log n)

--------------------------------

PATTERN TO REMEMBER

Weighted Interval Scheduling

1. Sort intervals.
2. State = current interval.
3. Choice:
       Take
       Skip
4. Find next compatible interval using binary search.
5. Memoize.

Recurrence:

dp[i] =
max(
    dp[i+1],
    profit[i] + dp[next]
)

This pattern appears in:
- LeetCode 1235
- Weighted Interval Scheduling
- Event Scheduling DP problems
