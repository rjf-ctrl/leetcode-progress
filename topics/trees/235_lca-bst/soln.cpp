#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int totalGas = 0;
        int totalCost = 0;

        for (int x : gas)
            totalGas += x;

        for (int x : cost)
            totalCost += x;

        if (totalGas < totalCost)
            return -1;

        int start = 0;
        int fuel = 0;

        for (int i = 0; i < gas.size(); i++) {
            fuel += gas[i] - cost[i];

            if (fuel < 0) {
                start = i + 1;
                fuel = 0;
            }
        }

        return start;
    }
};

int main() {
    Solution sol;

    vector<tuple<vector<int>, vector<int>, int>> tests = {
        {{1,2,3,4,5}, {3,4,5,1,2}, 3},
        {{2,3,4}, {3,4,3}, -1},
        {{5}, {4}, 0},
        {{4}, {5}, -1},
        {{3,1,1}, {1,2,2}, 0},
        {{2,0,1,2}, {1,1,1,1}, 3},
        {{6,1,4,3,5}, {3,8,2,4,2}, -1},
        {{5,8,2,8}, {6,5,6,6}, 3}
    };

    for (int i = 0; i < tests.size(); i++) {
        auto [gas, cost, expected] = tests[i];

        int ans = sol.canCompleteCircuit(gas, cost);

        cout << "Test " << i + 1 << ": ";

        if (ans == expected)
            cout << "PASS";
        else
            cout << "FAIL";

        cout << " | Expected = " << expected
             << ", Got = " << ans << '\n';
    }

    return 0;
}