#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:

    bool backtrack (int start, int k, int sum, int target, vector <bool> &used, vector<int>& nums){
        if(k==1) return true;
        
        if(sum==target) return backtrack(0, k-1, 0, target, used, nums);

        int prev=-1;
        for(int i=start; i<nums.size(); i++){
            if(used[i]) continue;
            if(nums[i]+sum>target) continue;
            if(nums[i]==prev) continue;
            used[i]=true;
            if(backtrack(i+1, k, sum+nums[i], target, used, nums)) return true;
            used[i]=false;

            prev=nums[i];
        }

        return false;
    }

    bool canPartitionKSubsets(vector<int>& nums, int k) {
        int n=nums.size();
        sort(nums.rbegin(), nums.rend());
        
        int total=0;
        for(int x: nums) total+=x;

        if(total%k!=0) return false;
        int target=total/k;

        if(nums[0]>target) return false;

        vector <bool> used(n, false);
        return backtrack(0, k, 0, target, used, nums);
        
    }
};


struct TestCase {
    vector<int> nums;
    int k;
    bool expected;
};

void runTests() {
    vector<TestCase> tests = {
        {{4, 3, 2, 3, 5, 2, 1}, 4, true},
        {{1, 2, 3, 4}, 3, false},
        {{1, 1, 1, 1}, 2, true},
        {{2, 2, 2, 2, 3, 4, 5}, 4, false},
        {{5, 5, 5, 5, 4, 4, 4, 4, 3, 3, 3, 3}, 4, true},
        {{10}, 1, true},
        {{1, 1, 1, 1, 1, 1, 1, 1}, 4, true},
        {{2, 2, 2, 2, 2, 2}, 3, true},
        {{1, 2, 3, 4, 5, 6, 7, 8}, 4, true},
        {{9, 1, 1, 1, 1, 1, 1, 1}, 3, false}
    };

    Solution sol;

    int passed = 0;

    for (int i = 0; i < tests.size(); i++) {
        bool result = sol.canPartitionKSubsets(tests[i].nums, tests[i].k);

        if (result == tests[i].expected) {
            cout << "Test Case " << i + 1 << ": PASS\n";
            passed++;
        } else {
            cout << "Test Case " << i + 1 << ": FAIL\n";
            cout << "Expected: " << (tests[i].expected ? "true" : "false") << "\n";
            cout << "Got: " << (result ? "true" : "false") << "\n";
        }
    }

    cout << "\nPassed " << passed << "/" << tests.size() << " test cases.\n";
}

int main() {
    runTests();
    return 0;
}