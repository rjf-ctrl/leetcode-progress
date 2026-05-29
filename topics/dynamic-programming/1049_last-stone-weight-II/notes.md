1.    Last Stone Weight II
You are given an array of integers stones where stones[i] is the weight of the ith stone.

We are playing a game with the stones. On each turn, we choose any two stones and smash them together. Suppose the stones have weights x and y with x <= y. The result of this smash is:

    If x == y, both stones are destroyed, and
    If x != y, the stone of weight x is destroyed, and the stone of weight y has new weight y - x.

At the end of the game, there is at most one stone left.

Return the smallest possible weight of the left stone. If there are no stones left, return 0.

Example 1:

Input: stones = [2,7,4,1,8,1]
Output: 1
Explanation:
We can combine 2 and 4 to get 2, so the array converts to [2,7,1,8,1] then,
we can combine 7 and 8 to get 1, so the array converts to [2,1,1,1] then,
we can combine 2 and 1 to get 1, so the array converts to [1,1,1] then,
we can combine 1 and 1 to get 0, so the array converts to [1], then that's the optimal value.

Example 2:

Input: stones = [31,26,33,21,40]
Output: 5


---

## SOLN

You should do it as a 0-1 knapsack problem.But afirst we have to covert it to that form. A lot pf rpoblems like this, try to convert to knapsack.
Here.. you smash some stones against other stones.. so make into two subsets. A and B.. for sum of B-sum of A (assume A less than B)to be minimum, should be maximum. ad for A to be lesser than B max avlue of A is total/2. So, find the value closest to total/2 that can be made from a subset sum of stones.

```
class Solution {
public:
    int lastStoneWeightII(vector<int>& stones) {
        int n= stones.size();
        int sum = accumulate(stones.begin(), stones.end(), 0);
        int target = sum/2;

        vector<bool> dp(target+1, 0);
        dp[0]=true;

        for(int stone: stones){
            for(int i=target; i>=stone; i--){
                dp[i]=dp[i]||dp[i-stone];
            }
        }
        int res=0;
        for(int i=target; i>=0; i--){
            if(dp[i]){
                res=i;
                break;
            }
        }
        return sum-(2*res);
    }
};
```
