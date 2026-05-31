# Unbounded Knapsack — Problem Statement
You are given:
N items
An array wt[] where wt[i] is the weight of the i-th item
An array val[] where val[i] is the value of the i-th item
A knapsack with capacity W

You may pick any item any number of times (including zero times).
Find the maximum total value that can be obtained without exceeding the knapsack capacity.

---

```
class Solution {
public:
    int unboundedKnapsack(int W, vector<int>& wt, vector<int>& val) {
        vector<int> dp(W + 1, 0);

        for (int i = 0; i < wt.size(); i++) {
            for (int w = wt[i]; w <= W; w++) {
                dp[w] = max(dp[w], val[i] + dp[w - wt[i]]);
            }
        }

        return dp[W];
    }
};
```

PATTERN:

```
for (each item)
    for (capacity = weight -> W)   // forward
        dp[capacity] = max(
            dp[capacity],          // not take
            value + dp[capacity - weight] // take again
        );
```