#include <iostream>
#include <algorithm>
#include <vector>
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector <vector<int>> result;
    void dfs(int start, vector<int> &nums, int target, vector<int> &curr){
        if(target==0){
            result.push_back(curr);
            return;
        }
        if(start==nums.size()) return;
        if(target<0) return;

        for(int i=start; i<nums.size(); i++){
            if(i>start && nums[i]==nums[i-1])  continue;
            curr.push_back(nums[i]);
            dfs(i+1, nums, target-nums[i], curr);
            curr.pop_back();
        }
        return;
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<int> curr;
        sort(candidates.begin(), candidates.end());
        dfs(0, candidates, target, curr);
        return result;
    }
};

bool equal(vector<vector<int>> a, vector<vector<int>> b) {
    auto normalize = [](vector<vector<int>>& v) {
        for (auto &x : v)
            sort(x.begin(), x.end());
        sort(v.begin(), v.end());
    };

    normalize(a);
    normalize(b);

    return a == b;
}

void runTest(vector<int> nums, int target, vector<vector<int>> expected) {
    Solution sol;
    auto ans = sol.combinationSum2(nums, target);

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
        {10,1,2,7,6,1,5},
        8,
        {
            {1,1,6},
            {1,2,5},
            {1,7},
            {2,6}
        }
    );

    runTest(
        {2,5,2,1,2},
        5,
        {
            {1,2,2},
            {5}
        }
    );

    return 0;
}

