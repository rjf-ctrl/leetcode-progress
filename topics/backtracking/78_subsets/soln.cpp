#include <bits/stdc++.h>
#include <iostream>
#include <set>
using namespace std;

class Solution {
public:
    set <vector <int>> result;
    void dfs(int i, vector<int>&nums, vector<int>&rset){
        if (i==nums.size()){
            result.insert(rset);
            return;
        }
        
            rset.push_back(nums[i]);
            dfs(i+1, nums, rset);
            rset.pop_back();
            dfs(i+1, nums, rset);
        
        return;
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        vector <int> rset;
        dfs(0, nums, rset);
        vector<vector<int>> ans(result.begin(), result.end());
        return ans;
    }
};

bool equal(vector<vector<int>> a, vector<vector<int>> b) {
    auto normalize = [](vector<vector<int>>& v) {
        for (auto& x : v)
            sort(x.begin(), x.end());
        sort(v.begin(), v.end());
    };

    normalize(a);
    normalize(b);
    return a == b;
}

void runTest(vector<int> nums, vector<vector<int>> expected) {
    Solution sol;
    auto ans = sol.subsets(nums);

    if (equal(ans, expected))
        cout << "PASS\n";
    else {
        cout << "FAIL\n";
        cout << "Expected:\n";
        for (auto& v : expected) {
            cout << "[ ";
            for (int x : v) cout << x << " ";
            cout << "]\n";
        }

        cout << "Got:\n";
        for (auto& v : ans) {
            cout << "[ ";
            for (int x : v) cout << x << " ";
            cout << "]\n";
        }
    }
}

int main() {
    runTest({1,2,3},
    {
        {},
        {1},
        {2},
        {3},
        {1,2},
        {1,3},
        {2,3},
        {1,2,3}
    });

    runTest({0},
    {
        {},
        {0}
    });

    return 0;
}