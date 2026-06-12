#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    int superEggDrop(int k, int n) {
        vector <int> dp(k+1, 0);
        int moves=0;
        while(dp[k]<n){
            moves++;
            for(int e=k; e>=1; e--){
                dp[e]=dp[e] + dp[e-1] + 1;
            }
        }
        return moves;
    }
};

struct TestCase {
    int eggs;
    int floors;
    int expected;
};

int main() {

    vector<TestCase> tests = {

        // LeetCode examples
        {1, 2, 2},
        {2, 6, 3},
        {3, 14, 4},

        // Base cases
        {1, 1, 1},
        {1, 5, 5},
        {1, 10, 10},

        {2, 1, 1},
        {3, 1, 1},

        // Small cases
        {2, 2, 2},
        {2, 3, 2},
        {2, 4, 3},
        {2, 5, 3},
        {2, 7, 4},
        {2, 10, 4},

        // Classic values
        {2, 36, 8},
        {2, 100, 14},

        {3, 25, 5},
        {3, 100, 9},

        {4, 100, 8},

        // Larger cases
        {3, 200, 11},
        {4, 500, 11},
        {5, 1000, 11},

        // Stress-ish
        {8, 10000, 14}
    };

    int passed = 0;

    for(int i = 0; i < tests.size(); i++) {

      
        int actual = Solution().superEggDrop(
            tests[i].eggs,
            tests[i].floors
        );

        if(actual == tests[i].expected) {
            cout << "[PASS] Test " << i + 1 << '\n';
            passed++;
        }
        else {
            cout << "[FAIL] Test " << i + 1
                 << " Eggs=" << tests[i].eggs
                 << " Floors=" << tests[i].floors
                 << " Expected=" << tests[i].expected
                 << " Got=" << actual
                 << '\n';
        }
        
    }

    

    return 0;
}