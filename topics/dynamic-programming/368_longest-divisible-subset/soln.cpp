#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

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
struct TestCase {
    vector<int> nums;
    int expectedSize;
};

int main() {

    Solution sol;

    vector<TestCase> tests = {
        {{1,2,3}, 2},
        {{1,2,4,8}, 4},
        {{4,8,10,240}, 3},
        {{1}, 1},
        {{3,4,16,8}, 3},
        {{2,3,5,7,11}, 1},
        {{1,2,6,24}, 4},
        {{5,9,18,54,108}, 4},
        {{1,3,6,24}, 4},
        {{17,34,68,136,272}, 5}
    };

    int passed = 0;

    for(int t = 0; t < tests.size(); t++) {

        vector<int> result = sol.largestDivisibleSubset(tests[t].nums);

        bool pass = ((int)result.size() == tests[t].expectedSize);

        if(pass) {
            cout << "Test " << t + 1 << ": PASS\n";
            passed++;
        }
        else {
            cout << "Test " << t + 1 << ": FAIL\n";
            cout << "Expected Size: " << tests[t].expectedSize
                 << ", Got: " << result.size() << "\n";
        }
    }

    cout << "\nPassed " << passed << "/" << tests.size() << " test cases.\n";

    return 0;
}