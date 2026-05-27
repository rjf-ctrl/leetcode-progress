# 416. Partition Equal Subset Sum
Given an integer array nums, return true if you can partition the array into two subsets such that the sum of the elements in both subsets is equal or false otherwise.

Example 1:

Input: nums = [1,5,11,5]
Output: true
Explanation: The array can be partitioned as [1, 5, 5] and [11].

Example 2:

Input: nums = [1,2,3,5]
Output: false
Explanation: The array cannot be partitioned into equal sum subsets.

---

## SOLN

**KEY POINT**: for two equal sum partitions.. therthat gives sum off all numbers/2 as sum. so.. there should be at least one set. So, if sum of all is odd then immediately false.

for every number, see if you can include it in the sum to get target or not and use dfs for that. This is slow tho:

```
class Solution {
public:
    unordered_map <string, bool> dp;
    bool check(int i, int t, vector<int> &nums){


        string key = to_string(i) +","+to_string(t);  //this process of memoization would bmean a computation occurs in every recursive call even if it has already been computed. this slows it down
        if(dp.find(key) != dp.end()) return dp[key];  

        if(i==nums.size()) return dp[key] = false;  //out of bounds
        if(nums[i]==t) return dp[key]=true;       //reached target

        bool add = false;  //decide if number needs to be included or not
        if(t-nums[i]>0) add = check(i+1, t-nums[i], nums);
        bool skip =check(i+1, t, nums);
        dp[key] = add||skip;
        
        return dp[key];        
        }

    bool canPartition(vector<int>& nums) {
        int n=nums.size();
        int sum=0;
        for(int i=0; i<n; i++)
            sum+=nums[i];
        if (sum%2!=0) return false;
        int target=sum/2;
        return check(0, target, nums);
    }
};
```

But we have realised that the cache would have tareget and i, so we can just use a 2d vector:

```
class Solution {
public:
    int check(int i, int t, vector<int> &nums, vector<vector<int>> &dp){
        if(i==nums.size()) return false;
        if(dp[i][t]!=-1) return dp[i][t];
        if(t==nums[i]) return true;

        bool add = false;
        if(t-nums[i]>=0) add = check(i+1, t-nums[i], nums, dp);
        bool skip =check(i+1, t, nums, dp);
        dp[i][t] = add||skip;

        return dp[i][t];        
        }

    bool canPartition(vector<int>& nums) {
        int n=nums.size();
        int sum=0;
        for(int i=0; i<n; i++)
            sum+=nums[i];
        if (sum%2!=0) return false;
        int target=sum/2;
        vector<vector<int>> dp(n, vector<int>(target+1, -1));
        return check(0, target, nums, dp)==1? true:false;
    }
};
```

But it can still be optimised.


A good way of doing this is with an unorder set.. take one number, add it to all the numbers currently in the set.. see if you can reach the target;

```
class Solution {
public:
    bool canPartition(vector<int>& nums) {
        
        int n= nums.size();
        int sum=0; 
        for(int i=0; i<n; i++){
            sum+=nums[i];
        }

        if(sum%2!=0)return false;

        unordered_set <int> dp ={0}; 
        unordered_set <int> next; 

        for(int x: nums){
            for(int y: dp){
                y+=x;
                if(y==sum/2) return true;
                if(y<sum/2) next.insert(y);
            }
            dp=next;
        }       

        return false;
    }
};

```
 and then theres a way to shoryten even this... using bitset:

 ```
 class Solution {
public:
    bool canPartition(vector<int>& nums) {

        int sum = 0, n = nums.size();
        for (int i = 0; i < n; i++) {
            sum += nums[i];
        }
        if (sum % 2 != 0)
            return false;

        bitset<10001> bit(1);
        for (auto i : nums) {
            bit |= bit << i;
            if (bit[sum / 2])
                return true;
        }
        return bit[sum / 2];
    }
};
```
[1 5 5 11]
declare a 1001 but number.. initalise it to 1..
so bascially only 0 is acheivaable ..000001
then add 1
so shift by 1 and or it with bit
000001 or 0000010 = 0000011
add 5
so shift by 5
001100000 or 0000011 = 1100011

this basicllaly lists all reachable sums.. thenif sum/2 is there , return true

