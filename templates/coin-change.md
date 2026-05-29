# COIN_CHANGE
coins of different denpominations available. infinite coins of each. 
find fewest amt of coins neeeded to make a given amount
if not possibe -1

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