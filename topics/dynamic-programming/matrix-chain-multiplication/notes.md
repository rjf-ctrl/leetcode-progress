# Matrix chain multiplication
Given a chain of matrices A1, A2, A3,.....An, you have to figure out the most efficient way to multiply these matrices. In other words, determine where to place parentheses to minimize the number of multiplications.

Given an array nums of size n. Dimension of matrix Ai ( 0 < i < n ) is nums[i - 1] x nums[i].Find a minimum number of multiplications needed to multiply the chain.

Example 1
Input : nums = [10, 15, 20, 25]
Output : 8000
Explanation : There are two ways to multiply the chain - A1*(A2*A3) or (A1*A2)*A3.

If we multiply in order- A1*(A2*A3), then number of multiplications required are 11250.
If we multiply in order- (A1*A2)*A3, then number of multiplications required are 8000.

Thus minimum number of multiplications required is 8000.
Example 2
Input : nums = [4, 2, 3]
Output : 24
Explanation : There is only one way to multiply the chain - A1*A2.
Thus minimum number of multiplications required is 24.

---

## SOLN

Given:
arr = [p0, p1, p2, ... , pn]

Matrices:
A1 = p0 × p1
A2 = p1 × p2
...
An = p(n-1) × pn

Goal:
Find minimum multiplication cost by choosing the best parenthesization.

--------------------------------------------------

MATRIX MULTIPLICATION COST

A = m × n
B = n × p

Cost = m × n × p

Reason:
Result has m×p cells and each cell needs n multiplications.

--------------------------------------------------

DP STATE

solve(i,j)

= Minimum cost to multiply matrices
  Ai ... Aj

Example:
solve(2,4)
= cost of multiplying A2 A3 A4

--------------------------------------------------

BASE CASE

If only one matrix exists:

solve(i,i) = 0

No multiplication needed.

--------------------------------------------------

PARTITION IDEA

For range:

Ai ... Aj

Try every split:

Ai...Ak | A(k+1)...Aj

where:

k = i to j-1

NOTE:
k = last matrix in left half
NOT the position of the cut.

Example:

A1 A2 | A3 A4
     ^
     k=2

--------------------------------------------------

COST OF ONE SPLIT

cost =
solve(i,k)
+
solve(k+1,j)
+
cost to multiply final results

--------------------------------------------------

FINAL MULTIPLICATION COST

Left result dimensions:
arr[i-1] × arr[k]

Right result dimensions:
arr[k] × arr[j]

Cost:

arr[i-1] * arr[k] * arr[j]

--------------------------------------------------

RECURRENCE

dp[i][j] = min over all k:

dp[i][k]
+
dp[k+1][j]
+
arr[i-1]*arr[k]*arr[j]

--------------------------------------------------

RECURSIVE TEMPLATE

int solve(int i, int j, vector<int>& arr)
{
    if(i == j)
        return 0;

    int mini = 1e9;

    for(int k=i; k<j; k++)
    {
        int cost =
            solve(i,k,arr)
          + solve(k+1,j,arr)
          + arr[i-1]*arr[k]*arr[j];

        mini = min(mini, cost);
    }

    return mini;
}

Answer:
solve(1, n-1)

--------------------------------------------------

WHY k < j ?

Valid:

k=i
Ai | A(i+1)...Aj

k=j-1
Ai...A(j-1) | Aj

Invalid:

k=j
Ai...Aj | EMPTY

Hence:

for(int k=i; k<j; k++)

--------------------------------------------------
TABULATION TEMPLATE

```
for(int len=2; len<=N; len++)
{
    for(int i=... )
    {
        int j = i + len - 1;

        dp[i][j] = INF;

        for(int k=i; k<j; k++)
        {
            dp[i][j] = min(
                dp[i][j],
                dp[i][k]
              + dp[k+1][j]
              + cost(i,k,j)
            );
        }
    }
}
```

KEY OBSERVATION

dp[i][j] depends on:

dp[i][k]
dp[k+1][j]

which are SMALLER RANGES.

So we must compute smaller ranges first

FINAL ANSWER

dp[1][n-1]

because we want the cost of
multiplying all matrices
A1 ... A(n-1)


INTUITION

Choose the LAST multiplication.

For every range [i,j]:
1. Try every split k
2. Solve left part
3. Solve right part
4. Add multiplication cost
5. Take minimum

--------------------------------------------------

PATTERN

Partition DP

Recognition:

solve(i,j)
=
min/max over all k
(
    solve(i,k)
  + solve(k+1,j)
  + cost
)

NOW **MEMOIZE** over dp[i][j]... as solve(i, j) calls are repeated;
Add memoization.
   => Top-down DP

Examples:
- Matrix Chain Multiplication
- Burst Balloons
- Minimum Cost to Cut a Stick
- Boolean Parenthesization
- Palindrome Partitioning

--------------------------------------------------

ONE-LINER

For every range [i,j], try every split k,
solve left and right recursively,
pay arr[i-1]*arr[k]*arr[j],
and take the minimum.