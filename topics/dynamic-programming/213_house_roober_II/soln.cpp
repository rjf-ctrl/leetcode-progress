#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int steal(int j, vector <int>& nums){
        int n=nums.size();
        int rob1=0, rob2=0; 
        if(j==0) n--;
        
        for(int i=j; i<n; i++){
            int temp=max(rob1+nums[i], rob2);
            rob1=rob2;
            rob2=temp;
        }
        return rob2;
    }
    int rob(vector<int>& nums) {
        int n=nums.size();
        if(n==1) return nums[0];
        if(n==2) return max(nums[0], nums[1]);
        int a = steal(0, nums), b=steal(1, nums);
        return max(a, b);
    }
};

int main() {
    Solution sol;

    vector<pair<vector<int>, int>> testCases = {
        {{2, 3, 2}, 3},
        {{1, 2, 3, 1}, 4},
        {{1, 2, 1, 1}, 3}
    };

    for (int i = 0; i < testCases.size(); i++) {
        vector<int> nums = testCases[i].first;
        int expected = testCases[i].second;

        int result = sol.rob(nums);

        cout << "Test Case " << i + 1 << ": ";

        if (result == expected) {
            cout << "Passed";
        } else {
            cout << "Failed";
        }

        cout << " | Expected: " << expected
             << " | Got: " << result << endl;
    }

    return 0;
}