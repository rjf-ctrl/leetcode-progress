#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        // Your logic here
        return 0;
    }
};





int main() {
    Solution sol;

    // Test Case 1
    vector<int> nums1 = {100, 4, 200, 1, 3, 2};
    cout << "Test Case 1 Output: "
         << sol.longestConsecutive(nums1) << endl;
    // Expected: 4  (sequence: 1,2,3,4)

    // Test Case 2
    vector<int> nums2 = {0, 3, 7, 2, 5, 8, 4, 6, 0, 1};
    cout << "Test Case 2 Output: "
         << sol.longestConsecutive(nums2) << endl;
    // Expected: 9  (sequence: 0 to 8)

    // Test Case 3
    vector<int> nums3 = {9, 1, 4, 7, 3, 2, 6, 8, 5};
    cout << "Test Case 3 Output: "
         << sol.longestConsecutive(nums3) << endl;
    // Expected: 9  (sequence: 1 to 9)

    return 0;
}