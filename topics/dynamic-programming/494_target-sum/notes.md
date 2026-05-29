# 494. Target Sum
You are given an integer array nums and an integer target.

You want to build an expression out of nums by adding one of the symbols '+' and '-' before each integer in nums and then concatenate all the integers.

    For example, if nums = [2, 1], you can add a '+' before 2 and a '-' before 1 and concatenate them to build the expression "+2-1".

Return the number of different expressions that you can build, which evaluates to target.

Example 1:

Input: nums = [1,1,1,1,1], target = 3
Output: 5
Explanation: There are 5 ways to assign symbols to make the sum of nums be target 3.
-1 + 1 + 1 + 1 + 1 = 3
+1 - 1 + 1 + 1 + 1 = 3
+1 + 1 - 1 + 1 + 1 = 3
+1 + 1 + 1 - 1 + 1 = 3
+1 + 1 + 1 + 1 - 1 = 3

---

## SOLN
SImple logic  
At each point, you have two choices add it or subtract it. If you reach the final element an etrgtm is acheived count it.  
Simple dfs works.


```
class Solution {
public:
    int res=0;
    void dfs(int i, int t, int s, vector<int> &nums, vector<vector<int>> &dp){
        if(i==nums.size()){
            if(s==t) res++;
            return ;
        }
        
        
        dfs(i+1, t, s+nums[i], nums, dp);
        dfs(i+1, t, s-nums[i], nums, dp);

        return;

    }
    int findTargetSumWays(vector<int>& nums, int target) {
        int n= nums.size();
        int sum=0;
        for(int x: nums) sum+=x;

        vector<vector<int>> dp(n, vector<int>(2*sum, n-1));

        dfs(0, target, 0, nums, dp);
        return res;
    }
};
```

Now, memoizing this with dp(i, sum) = number of ways:-

```
class Solution {
public:
    int res=0;
    int dfs(int i, int t, int s, vector<int> &nums, vector<vector<int>> &dp){
        if(i==nums.size()){
            if(s==t) return 1;
            return 0;
        }
        if(dp[i][s]!=-1) return dp[i][s];
        
        dp[i][s]+=dfs(i+1, t, s+nums[i], nums, dp);
        dp[i][s]+=dfs(i+1, t, s-nums[i], nums, dp);

        return dp[i][s];

    }
    int findTargetSumWays(vector<int>& nums, int target) {
        int n= nums.size();
        int sum=0;
        for(int x: nums) sum+=x;

        vector<vector<int>> dp(n, vector<int>(2*sum, n-1));

        dfs(0, target, 0, nums, dp);
        return 1+dp[0][target];
    }
};
```

There is yet another much faster way to solve it. Use the exact same bitset method or unordered set method as equal prtition sum. But Use the *LOGIC:* We ahve to divide the numbers into two sets P and N. where P + N = total sum and P-N = target. AAdd the two eqns and you get 2 * P = tagett + total; P = (target + total) /2. Then count the number of ways to make P.
```
class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int n= nums.size();
        int total =0;
        for(int x: nums) total+=x;

        if(total+target<0||(total+target)%2!=0) return 0;

        int p=(total+target)/2;

        vector<int> dp(p+1, 0);  //dp[i] = number of ways to get sum i
        dp[0]=1; //only one way to get sum 0 : {}

        for(int x: nums){
            for(int i=p; i>=x; i--){
                dp[i]+=dp[i-x];   //for every x : nums, the number of ways it is possible to get i = n. of ways to get i=x;
            }
        }
        return dp[p];
    }
};
```
