#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        if(n==2) return cost[0]<cost[1]? cost[0]:cost[1];

        vector <int> dp(n+1);
        dp[0] = cost[0];
        dp[1] = cost[1];
        int i=2;

        while(i<=cost.size()){
            int current = (i==cost.size())? 0: cost[i];
            if(current + dp[i-1]> current+dp[i-2]) dp[i] = current+dp[i-2];
            else dp[i] = dp[i-1]+current;
            i++;
        }

        return dp[n];
    }
};

int main() {
    Solution sol;

    vector<pair<vector<int>, int>> testCases = {
        {{10, 15, 20}, 15},
        {{1, 100, 1, 1, 1, 100, 1, 1, 100, 1}, 6},
        {{0, 0, 1, 1}, 1}
    };

    for (int i = 0; i < testCases.size(); i++) {
        vector<int> cost = testCases[i].first;
        int expected = testCases[i].second;

        int result = sol.minCostClimbingStairs(cost);

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