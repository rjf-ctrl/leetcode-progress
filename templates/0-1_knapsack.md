# 0-1 Knapsack

A knapsack has a max capacity on weight. Different objects with weights and an associated value
Problem: maximise profit and restrict yourself to the weight limit.

```
int knapsack(vector<int>& wt, vector<int>& val, int W) {
    int n = wt.size();

    vector<int> dp(W + 1, 0);

    for(int i = 0; i < n; i++) {
        for(int w = W; w >= wt[i]; w--) {
            dp[w] = max(dp[w],
                        val[i] + dp[w - wt[i]]);
        }
    }

    return dp[W];
}
```

