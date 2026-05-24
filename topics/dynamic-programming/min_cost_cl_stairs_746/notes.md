# 746. Min Cost Climbing Stairs
You are given an integer array cost where cost[i] is the cost of ith step on a staircase. Once you pay the cost, you can either climb one or two steps.
You can either start from the step with index 0, or the step with index 1.
Return the minimum cost to reach the top of the floor.

Example 1:

Input: cost = [10,15,20]
Output: 15
Explanation: You will start at index 1.
- Pay 15 and climb two steps to reach the top.
The total cost is 15.

Example 2:

Input: cost = [1,100,1,1,1,100,1,1,100,1]
Output: 6
Explanation: You will start at index 0.
- Pay 1 and climb two steps to reach index 2.
- Pay 1 and climb two steps to reach index 4.
- Pay 1 and climb two steps to reach index 6.
- Pay 1 and climb one step to reach index 7.
- Pay 1 and climb two steps to reach index 9.
- Pay 1 and climb one step to reach the top.

The total cost is 6.

---

## SOLN
Here, you cant just always take 2 jumps to coer max distance, bcuz you might land on huge numbers you could have avoided (like the 100s in the second example). And selecting the smallest cost of next and next to next step is also not efficent bcuz you might just end up taking a lot of single steps with smaller value than its immediate neighbour but rack up the cost by ahving to take more steps.. so we need to do this in an almsot dijkstra way.. keep track of cheapest way to get to any step so that you can calculate how to get to a given step throught either the step beofre ore the step before that.
take step 0 and 1 as base cases and the cost of the last stair ot "top" as 0.  For any subsequent step see if dp[i-1] is greater or dp[i-2].
````
class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        if(n==2) return cost[0]<cost[1]? cost[0]:cost[1];

        vector <int> dp(n+1);
        dp[0] = cost[0];
        dp[1] = cost[1];
        int i=2;

        while(i<=cost.size()){
            int current = (i==cost.size())? 0: cost[i];
            if(dp[i-1]> dp[i-2]) dp[i] = current+dp[i-2];
            else dp[i] = dp[i-1]+current;
            i++;
        }

        return dp[n];
    }
};
`````


There is a recursive approach.. but this is slower and causes way more reppeated computations.

````
class Solution {
public:
    int solve(int i, vector<int>& cost) {
        if(i >= cost.size())
            return 0;

        return cost[i] +
               min(solve(i + 1, cost),
                   solve(i + 2, cost));
    }

    int minCostClimbingStairs(vector<int>& cost) {
        return min(solve(0, cost),
                   solve(1, cost));
    }
};
````

Here we take two different paths, one starting at 0 and one staring at 1. Solve for both and return the minimum. Solve starts from the last stair as base case and goes backward. 