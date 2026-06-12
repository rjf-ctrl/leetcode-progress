# 312. Burst Balloons
You are given n balloons, indexed from 0 to n - 1. Each balloon is painted with a number on it represented by an array nums. You are asked to burst all the balloons.

If you burst the ith balloon, you will get nums[i - 1] * nums[i] * nums[i + 1] coins. If i - 1 or i + 1 goes out of bounds of the array, then treat it as if there is a balloon with a 1 painted on it.

Return the maximum coins you can collect by bursting the balloons wisely.

Example1:

Input: nums = [3,1,5,8]
Output: 167
Explanation:
nums = [3,1,5,8] --> [3,5,8] --> [3,8] --> [8] --> []
coins =  3*1*5    +   3*5*8   +  1*3*8  + 1*8*1 = 167

---

## SOLN

MAIN TRICK

Thinking about FIRST balloon to burst is difficult because neighbors change.

Instead think:

"What is the LAST balloon burst?"

----------------------------------

PADDING

Add virtual balloons:

nums = [1] + nums + [1]

Example:

[3,1,5,8]

becomes

[1,3,1,5,8,1]

----------------------------------

STATE

dp[L][R]

= Maximum coins obtainable
  from balloons L...R

(only considering balloons  inside this interval)

----------------------------------

BASE CASE

L > R

No balloons left

return 0

----------------------------------

PARTITION IDEA

Assume balloon k is burst LAST inside interval [L,R].

Then:

[L ... k-1]   k   [k+1 ... R]

The left and right intervals become independent.

Exactly like MCM.

----------------------------------

COINS FOR CHOOSING k LAST

At the moment k bursts:

Only boundaries survive.

Left boundary  = nums[L-1]
Right boundary = nums[R+1]

Coins:

nums[L-1] * nums[k] * nums[R+1]

----------------------------------

RECURRENCE

dp[L][R] = max over all k:

dp[L][k-1]
+
dp[k+1][R]
+
nums[L-1] * nums[k] * nums[R+1]

----------------------------------

RECURSIVE TEMPLATE

solve(L,R)

if(L > R)
    return 0;

ans = 0;

for(k=L; k<=R; k++)
{
    coins =
        solve(L,k-1)
      + solve(k+1,R)
      + nums[L-1]*nums[k]*nums[R+1];

    ans = max(ans, coins);
}

return ans;

----------------------------------

DEPENDENCIES

dp[L][R]

depends on

dp[L][k-1]
dp[k+1][R]

which are smaller intervals.

Therefore:

Compute smaller intervals first.

----------------------------------

TABULATION ORDER

Length = 1

[3]
[1]
[5]
[8]

↓

Length = 2

[3,1]
[1,5]
[5,8]

↓

Length = 3

[3,1,5]
[1,5,8]

↓

Length = 4

[3,1,5,8]

----------------------------------

TABULATION TEMPLATE

for(len = 1 → n)
{
    for(L)
    {
        R = L + len - 1;

        for(k = L → R)
        {
            dp[L][R] = max(
                dp[L][R],
                dp[L][k-1]
              + dp[k+1][R]
              + nums[L-1]*nums[k]*nums[R+1]
            );
        }
    }
}

----------------------------------

MCM vs BURST BALLOONS

MCM:

Choose split k

Ai...Ak | A(k+1)...Aj

dp[i][k]
+
dp[k+1][j]
+
cost

----------------------------------

Burst Balloons:

Choose k as LAST balloon

[L...k-1] k [k+1...R]

dp[L][k-1]
+
dp[k+1][R]
+
nums[L-1]*nums[k]*nums[R+1]

----------------------------------

MEMORY TRICK

MCM:
"What is the last multiplication?"

Burst Balloons:
"What is the last balloon to burst?"

Both are Partition DP.
The only difference is the cost formula.