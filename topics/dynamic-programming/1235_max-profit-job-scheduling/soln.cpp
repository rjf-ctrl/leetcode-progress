#include <iostream>
#include <vector>
#include <tuple>
#include <algorithm>
using namespace std;

/*
=========================================
LC 1235 - Maximum Profit in Job Scheduling
=========================================

Given:

startTime[i]
endTime[i]
profit[i]

Return the maximum profit you can earn such that
no selected jobs overlap.

Implement:

class Solution {
public:
    int jobScheduling(
        vector<int>& startTime,
        vector<int>& endTime,
        vector<int>& profit
    );
};

=========================================
*/

class Solution {
public:

    int dfs(
        int i,
        vector<tuple<int,int,int>>& jobs,
        vector<int>& starts,
        vector<int>& dp
    ) {
        if(i >= jobs.size()) return 0;

        if(dp[i] != -1)
            return dp[i];

        int next = lower_bound(
            starts.begin(),
            starts.end(),
            get<1>(jobs[i])
        ) - starts.begin();

        int skip = dfs(i + 1, jobs, starts, dp);

        int take =
            get<2>(jobs[i]) +
            dfs(next, jobs, starts, dp);

        return dp[i] = max(skip, take);
    }

    int jobScheduling(
        vector<int>& startTime,
        vector<int>& endTime,
        vector<int>& profit
    ) {

        int n = startTime.size();

        vector<tuple<int,int,int>> jobs;

        for(int i = 0; i < n; i++) {
            jobs.push_back({
                startTime[i],
                endTime[i],
                profit[i]
            });
        }

        sort(
            jobs.begin(),
            jobs.end(),
            [](const auto& a, const auto& b) {
                return get<0>(a) < get<0>(b);
            }
        );

        vector<int> starts;

        for(auto& job : jobs) {
            starts.push_back(get<0>(job));
        }

        vector<int> dp(n, -1);

        return dfs(0, jobs, starts, dp);
    }
};

void runTest(
    string testName,
    vector<int> startTime,
    vector<int> endTime,
    vector<int> profit,
    int expected
) {
    Solution sol;

    int result =
        sol.jobScheduling(
            startTime,
            endTime,
            profit
        );

    cout << testName << ": ";

    if(result == expected) {
        cout << "PASS\n";
    }
    else {
        cout << "FAIL\n";
        cout << "Expected: "
             << expected
             << "\nGot: "
             << result
             << "\n";
    }
}

int main() {

    runTest(
        "Example 1",
        {1,2,3,3},
        {3,4,5,6},
        {50,10,40,70},
        120
    );

    runTest(
        "Example 2",
        {1,2,3,4,6},
        {3,5,10,6,9},
        {20,20,100,70,60},
        150
    );

    runTest(
        "Example 3",
        {1,1,1},
        {2,3,4},
        {5,6,4},
        6
    );

    runTest(
        "Single Job",
        {1},
        {2},
        {100},
        100
    );

    runTest(
        "All Compatible",
        {1,3,5},
        {2,4,6},
        {10,20,30},
        60
    );

    runTest(
        "Choose Large Profit",
        {1,2,3},
        {4,5,6},
        {50,10,100},
        100
    );

    runTest(
        "Classic Weighted Interval",
        {1,2,4,6},
        {3,5,6,7},
        {50,20,70,60},
        180
    );

    runTest(
        "Many Overlaps",
        {1,2,3,4},
        {10,10,10,10},
        {5,6,7,8},
        8
    );

    return 0;
}