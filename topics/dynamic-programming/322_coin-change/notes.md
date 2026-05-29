# 322. Coin Change
You are given an integer array coins representing coins of different denominations and an integer amount representing a total amount of money.

Return the fewest number of coins that you need to make up that amount. If that amount of money cannot be made up by any combination of the coins, return -1.

You may assume that you have an infinite number of each kind of coin.

Example 1:

Input: coins = [1,2,5], amount = 11
Output: 3
Explanation: 11 = 5 + 5 + 1

Example 2:

Input: coins = [2], amount = 3
Output: -1

Example 3:

Input: coins = [1], amount = 0
Output: 0

---

## SOLN

You try to check the minimum  amount of coins, required to make every single amount leading up to target.
```
class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        if(amount==0) return 0;
        int n = coins.size();
       
        vector <int> dp(amount+1, amount+1);
        dp[0]=0;
        for(int i=0; i<=amount; i++){
            for(int x:coins){
                if(i-x>=0)
                dp[i]=min(dp[i], 1+dp[i-x]);    
            }
        }
     return dp[amount]!=amount+1? dp[amount]:-1;   
    }
};

```

Finally dp[i] will have minimum no of coind required to get i. if its not possible to get i it will have amount+1;


