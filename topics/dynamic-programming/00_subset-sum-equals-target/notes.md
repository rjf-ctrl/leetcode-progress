# Subset sum equals to target
Given an array arr of n integers and an integer target, determine if there is a subset of the given array with a sum equal to the given target.

Example 1
Input: arr = [1, 2, 7, 3], target = 6
Output: True
Explanation: There is a subset (1, 2, 3) with sum 6.

Example 2
Input: arr = [2, 3, 5], target = 6
Output: False
Explanation: There is no subset with sum 6.

---

## SOLN

logic: standard
```
class Solution{   
public:
    bool isSubsetSum(vector<int>arr, int target){
        int n=arr.size();
        if(n==1){
            if(target==arr[0]) return true;
            return false;
        }
        int sum=0;
        for(int x: arr) sum+=x;
        if(sum<target) return false; 

        unordered_set <int> dp;
        unordered_set <int> ndp;
        ndp.insert(0);
    
        for(int y: arr){
            dp=ndp;
            for (int x: dp) {
                ndp.insert(x+y);
            }

            if(ndp.find(target)!=ndp.end()) return true;
        }      
        return false;
    }
};

```
