#include <bits/stdc++.h>
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> result;

    void backtrack(vector<int>& nums, vector<int>& curr, vector<bool>& used) {
        if (curr.size() == nums.size()) {
            result.push_back(curr);
            return;
        }

        for (int i = 0; i < nums.size(); i++) {
            if (used[i]) continue;

            used[i] = true;
            curr.push_back(nums[i]);

            backtrack(nums, curr, used);

            curr.pop_back();
            used[i] = false;
        }
    }

    vector<vector<int>> permute(vector<int>& nums) {
        vector<int> curr;
        vector<bool> used(nums.size(), false);

        backtrack(nums, curr, used);
        return result;
    }
};
bool equal(vector<vector<int>> a, vector<vector<int>> b) {
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    return a == b;
}

void runTest(vector<int> nums, vector<vector<int>> expected) {
    Solution sol;
    auto ans = sol.permute(nums);

    if (equal(ans, expected))
        cout << "PASS\n";
    else {
        cout << "FAIL\n";

        cout << "Expected:\n";
        for (auto &v : expected) {
            cout << "[ ";
            for (int x : v) cout << x << " ";
            cout << "]\n";
        }

        cout << "Got:\n";
        for (auto &v : ans) {
            cout << "[ ";
            for (int x : v) cout << x << " ";
            cout << "]\n";
        }
    }
}

int main() {

    runTest(
        {1,2,3},
        {
            {1,2,3},
            {1,3,2},
            {2,1,3},
            {2,3,1},
            {3,1,2},
            {3,2,1}
        }
    );

    runTest(
        {0,1},
        {
            {0,1},
            {1,0}
        }
    );

    runTest(
        {1},
        {
            {1}
        }
    );

    return 0;
}
