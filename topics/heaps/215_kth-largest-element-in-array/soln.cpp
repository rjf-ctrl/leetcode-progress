#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findKthLargest(std::vector<int>& nums, int k) {
        if(nums.size() == 0) return 0;
        
        std::vector<int> forCountSort(20001 , 0);

        for(const int& elem : nums){
            forCountSort[elem + 10000] ++;
            //we add 10000 as offset to include -ve numbers
            //as constraints are -10000 to +10000 , so we took
            //vector of size 20001
        }

        int tempCount = 0;
        for(int i=forCountSort.size()-1; i>=0; --i){
            if(forCountSort[i] > 0) tempCount += forCountSort[i];
            if(tempCount >= k) return i-10000;
        }

        return 0;
    }
};

void runTest(int testNo, vector<int> nums, int k, int expected) {
    Solution sol;
    int ans = sol.findKthLargest(nums, k);

    if (ans == expected)
        cout << "Test " << testNo << " Passed\n";
    else
        cout << "Test " << testNo << " Failed\n"
             << "Expected: " << expected
             << " Got: " << ans << "\n";
}

int main() {

    runTest(1, {3,2,1,5,6,4}, 2, 5);

    runTest(2, {3,2,3,1,2,4,5,5,6}, 4, 4);

    runTest(3, {1}, 1, 1);

    runTest(4, {-1,-1}, 2, -1);

    runTest(5, {7,6,5,4,3,2,1}, 5, 3);

    return 0;
}
