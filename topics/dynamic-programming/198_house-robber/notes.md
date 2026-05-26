# 198. House Robber
You are a professional robber planning to rob houses along a street. Each house has a certain amount of money stashed, the only constraint stopping you from robbing each of them is that adjacent houses have security systems connected and it will automatically contact the police if two adjacent houses were broken into on the same night.
Given an integer array nums representing the amount of money of each house, return the maximum amount of money you can rob tonight without alerting the police.
Example 1:

Input: nums = [1,2,3,1]
Output: 4
Explanation: Rob house 1 (money = 1) and then rob house 3 (money = 3).
Total amount you can rob = 1 + 3 = 4.

Example 2:

Input: nums = [2,7,9,3,1]
Output: 12
Explanation: Rob house 1 (money = 2), rob house 3 (money = 9) and rob house 5 (money = 1).
Total amount you can rob = 2 + 9 + 1 = 12.

---

## SOLN

````
class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n==1) return nums[0];
        if(n==2) return nums[0]>nums[1]? nums[0]:nums[1];

        int rob1 = 0, rob2 = 0;

        for(int i=0; i<n; i++){
            int current = max(nums[i]+rob1, rob2);
            rob1=rob2;
            rob2 = current;
        }

        return rob2;
    }
};

````
try writing out the decison trea and identiy the subproblem first. Here for every house you can rob it and the maximum of the subarray after leaving the adjecent house. So, for every house decide. Should I rob this house[i] + maximum of house[i-2] OR should i not rob this house or just stick to maxx of robbing house[i-1];
so hae rob1 keep track of max till house[i-2] and rob2 keep track of max till house [i-1]; 
```
 int current = max(nums[i]+rob1, rob2);
            rob1=rob2;
            rob2 = current;
```

