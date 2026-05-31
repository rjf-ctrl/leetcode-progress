
=================================
DP LOOP DIRECTION CHEAT SHEET
=================================

QUESTION TO ASK:

Can I use the same item multiple times?

YES  -> FORWARD LOOP
NO   -> BACKWARD LOOP

=================================
1. SUBSET SUM (0/1)
=================================

Each element can be used ONCE.

for(int x : arr) {
    for(int sum = K; sum >= x; sum--) {
        dp[sum] |= dp[sum - x];
    }
}

Examples:
- Subset Sum
- Partition Equal Subset Sum (LC 416)

Memory:
"Take it or leave it."

Loop:
K -> x

=================================
2. COUNT SUBSETS WITH SUM K
=================================

Each element can be used ONCE.

for(int x : arr) {
    for(int sum = K; sum >= x; sum--) {
        dp[sum] += dp[sum - x];
    }
}

Examples:
- Perfect Sum
- Target Sum (LC 494)

Memory:
"Count subsets."

Loop:
K -> x

=================================
3. 0/1 KNAPSACK
=================================

Each item can be taken ONCE.

for(int i = 0; i < n; i++) {
    for(int w = W; w >= wt[i]; w--) {
        dp[w] = max(dp[w],
                    val[i] + dp[w - wt[i]]);
    }
}

Memory:
"Take item once."

Loop:
W -> wt[i]

=================================
4. COIN CHANGE II
=================================

Coins can be reused.

for(int coin : coins) {
    for(int sum = coin; sum <= amount; sum++) {
        dp[sum] += dp[sum - coin];
    }
}

Example:
- LC 518

Memory:
"Unlimited coins."

Loop:
coin -> amount

=================================
5. UNBOUNDED KNAPSACK
=================================

Items can be reused.

for(int i = 0; i < n; i++) {
    for(int w = wt[i]; w <= W; w++) {
        dp[w] = max(dp[w],
                    val[i] + dp[w - wt[i]]);
    }
}

Memory:
"Take item again and again."

Loop:
wt[i] -> W

=================================
6. ROD CUTTING
=================================

Cuts can be reused.

for(int len : lengths) {
    for(int L = len; L <= N; L++) {
        dp[L] = max(dp[L],
                    price + dp[L - len]);
    }
}

Memory:
"Unlimited cuts."

Loop:
Forward

=================================
7. COMBINATION SUM IV
=================================

Order matters.

for(int sum = 1; sum <= target; sum++) {
    for(int num : nums) {

        if(sum >= num)
            dp[sum] += dp[sum - num];
    }
}

Example:
- LC 377

Memory:
Count:
1+2 and 2+1 separately.

Loop:
sum outside
number inside

=================================
MASTER RULE
=================================

BACKWARD LOOP

for(sum = K; sum >= x; sum--)

Meaning:
"Do NOT reuse current item."

Used in:
- Subset Sum
- Count Subsets Sum K
- 0/1 Knapsack

---------------------------------

FORWARD LOOP

for(sum = x; sum <= K; sum++)

Meaning:
"Reuse current item as many times as needed."

Used in:
- Coin Change II
- Unbounded Knapsack
- Rod Cutting

---------------------------------

SUM OUTSIDE, ITEM INSIDE

for(sum = 1; sum <= K; sum++)
    for(item)

Meaning:
"Order matters."

Used in:
- Combination Sum IV
- Number of sequences
- Permutation counting

=================================
3-SECOND INTERVIEW RULE
=================================

Use item once?      -> BACKWARD

Use item many times? -> FORWARD

Does order matter?  -> SUM OUTSIDE

