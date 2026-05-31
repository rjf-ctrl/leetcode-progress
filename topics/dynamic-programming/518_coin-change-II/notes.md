# 518. Coin Change II
You are given an integer array coins representing coins of different denominations and an integer amount representing a total amount of money.
Return the number of combinations that make up that amount. If that amount of money cannot be made up by any combination of the coins, return 0.
You may assume that you have an infinite number of each kind of coin.
The answer is guaranteed to fit into a signed 32-bit integer.

Example 1:

Input: amount = 5, coins = [1,2,5]
Output: 4
Explanation: there are four ways to make up the amount:
5=5
5=2+2+1
5=2+1+1+1
5=1+1+1+1+1

Example 2:

Input: amount = 3, coins = [2]
Output: 0
Explanation: the amount of 3 cannot be made up just with coins of 2.

Example 3:

Input: amount = 10, coins = [10]
Output: 1

---

## SOLN

Brute force:
at every point you have the hoice to pick any of the coins... so at each pint in the decision tree you have m choices.. but the problem here is that there will be repitions, 1, 2 and 2, 1 are the same. So we put a limitation. We can at atime ony access the current coin and the ones befroe it. eg: in (1, 2, 5) if ur using 1 u can only use 1.. if ur using 2 u can use 1 nd 2 if ure using 5 then u can use 1 2 and 5. this will ensure combinations are not repeated. 

so, we have a 2d dp with amount x coins.
but at a time we only need current row and previous row.

```
class Solution {
public:
    int change(int amount, vector<int>& coins) {
        vector <long long> dp(amount+1, 0);
        dp[0]=1;
        
        for(int i: coins){
            vector<long long>curr(amount+1, 0);
            curr[0]=1;
            for(int j=1; j<=amount; j++){

                int  left=0;
                if(j-i>=0) left=curr[j-i];
                curr[j]=curr[j] + left + dp[j];
            }
            dp=curr;
        }

        return (int)dp[amount];      

    
    }
};
```

even more space optimised 


```
class Solution {
public:
    int change(int amount, vector<int>& coins) {
        vector<unsigned long long> dp(amount + 1, 0);
        dp[0] = 1;

        for (int coin : coins) {
            for (int j = coin; j <= amount; j++) {
                dp[j] += dp[j - coin];
            }
        }

        return dp[amount];
    }
};
```


