# 368. Largest Divisible Subset
Description:
Given a set of distinct positive integers nums, return the largest subset answer
such that every pair (answer[i], answer[j]) of elements in this subset satisfies:

    answer[i] % answer[j] == 0
or
    answer[j] % answer[i] == 0

If there are multiple solutions, return any of them.

Examples:

Input: nums = [1,2,3]
Output: [1,2]
Explanation:
[1,3] is also accepted.

Input: nums = [1,2,4,8]
Output: [1,2,4,8]

Constraints:
1 <= nums.length <= 1000
1 <= nums[i] <= 2 * 10^9
All the integers in nums are unique.

---

## SOLN

Use LIS type logic. I tred appedning the soln as i went.
```
class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int n=nums.size();
        sort(nums.begin(), nums.end());
        vector <vector<int>> dp(n);
        vector <int> result;
        for(int i=n-1; i>=0; i--){
            vector <int> temp;
            temp.push_back(nums[i]);
            for(int j=n-1; j>i; j--){
                vector <int> curr;
                curr.push_back(nums[i]);
                if(nums[i]%dp[j][0]==0 || dp[j][0]%nums[i]==0) {
                for(int k=0; k<dp[j].size(); k++)
                    curr.push_back(dp[j][k]);
                if(curr.size()>=temp.size()) temp=curr;
                }
            }
            dp[i]=temp;
            if(temp.size()>=result.size()) result=temp;
        }
        return result;
    }
};
```

But a cleaner saner way to do it would just be following LIS with a parent array

```
class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {

        int n = nums.size();

        sort(nums.begin(), nums.end());

        vector<int> dp(n, 1);
        vector<int> parent(n);

        int bestLen = 1;
        int bestIdx = 0;

        for(int i = 0; i < n; i++) {

            parent[i] = i;

            for(int j = 0; j < i; j++) {

                if(nums[i] % nums[j] == 0 &&
                   dp[j] + 1 > dp[i]) {

                    dp[i] = dp[j] + 1;
                    parent[i] = j;
                }
            }

            if(dp[i] > bestLen) {
                bestLen = dp[i];
                bestIdx = i;
            }
        }

        vector<int> result;

        while(parent[bestIdx] != bestIdx) {
            result.push_back(nums[bestIdx]);
            bestIdx = parent[bestIdx];
        }

        result.push_back(nums[bestIdx]);

        reverse(result.begin(), result.end());

        return result;
    }
};

```