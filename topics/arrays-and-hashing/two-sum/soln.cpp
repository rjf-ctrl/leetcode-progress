#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:

    vector<int> twoSum(vector<int>& nums, int target) {

        if(nums.size() == 2) return {0, 1};
        unordered_map<int, int> hash;

        for(int i=0; i<nums.size();i++) {

            if(hash.count(target-nums[i])) 
                return { hash[target-nums[i]], i};
            
            hash[nums[i]] = i;
        }       
        return {};
    }

};

int main(){
    Solution sol;

    vector<int> nums1 = {2,7,11,15};
    cout << "TC1:" << sol.twoSum(nums1, 9)[0] <<"," << sol.twoSum(nums1, 9)[1]<< endl;

    vector<int> nums2 = {3,2,4};
    cout << "TC2:" << sol.twoSum(nums2, 6)[0] <<"," << sol.twoSum(nums2, 6)[1]<< endl;

    vector<int> nums3 = {3,3};
    cout << "TC3:" << sol.twoSum(nums3, 6)[0] <<"," << sol.twoSum(nums3, 6)[1]<< endl;
}