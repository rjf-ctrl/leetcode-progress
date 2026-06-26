#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int start=0; int tank=0; int total=0;

        for(int i=0; i<gas.size(); i++){
            int t=gas[i]-cost[i];
            tank+=t;
            total+=t;
            if(tank<0) {start=i+1; tank=0;}
        }
        if(total<0)return -1;
        return start;

    }
};

void runTest(int testNo,
             vector<int> gas,
             vector<int> cost,
             int expected) {

    Solution sol;

    int ans = sol.canCompleteCircuit(gas, cost);

    if(ans == expected)
        cout << "Test " << testNo << " Passed\n";
    else
        cout << "Test " << testNo << " Failed\n"
             << "Expected: " << expected
             << " Got: " << ans << "\n";
}

int main() {

    runTest(
        1,
        {1,2,3,4,5},
        {3,4,5,1,2},
        3
    );

    runTest(
        2,
        {2,3,4},
        {3,4,3},
        -1
    );

    runTest(
        3,
        {5},
        {4},
        0
    );

    runTest(
        4,
        {4,5,2,6,5,3},
        {3,2,7,3,2,9},
        -1
    );

    runTest(
        5,
        {5,1,2,3,4},
        {4,4,1,5,1},
        4
    );

    return 0;
}
