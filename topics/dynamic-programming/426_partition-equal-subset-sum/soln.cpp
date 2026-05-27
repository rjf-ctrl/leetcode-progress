#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

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

void runTest(vector<int> nums, bool expected, int testNo) {

    Solution sol;

    bool result = sol.canPartition(nums);

    cout << "Test Case " << testNo << ": ";

    if(result == expected)
        cout << "PASS";
    else
        cout << "FAIL";

    cout << "\nExpected: " << (expected ? "true" : "false");
    cout << "\nGot: " << (result ? "true" : "false") << "\n\n";
}

int main() {

    // Test Case 1
    vector<int> nums1 = {1, 5, 11, 5};

    runTest(nums1, true, 1);

    // Test Case 2
    vector<int> nums2 = {1, 2, 3, 5};

    runTest(nums2, false, 2);

    // Test Case 3
    vector<int> nums3 = {2, 2, 1, 1};

    runTest(nums3, true, 3);

    // Test Case 4
    vector<int> nums4 = {3, 3, 3, 4, 5};

    runTest(nums4, true, 4);

    // Test Case 5
    vector<int> nums5 = {1, 1, 3, 4, 7};

    runTest(nums5, true, 5);

    return 0;
}