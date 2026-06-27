#include <vector>
#include <iostream>
using namespace std;
#include <algorithm>
class Solution {
public:
    void backtrack(vector<int>& candidates, int remaining, int start, vector<int>& path, vector<vector<int>>& results) {
        if (remaining == 0) {
            results.push_back(path);
            return;
        }
        if (remaining < 0) return;

        for (int i = start; i < candidates.size(); ++i) {
            path.push_back(candidates[i]);
            backtrack(candidates, remaining - candidates[i], i, path, results);
            path.pop_back();
        }
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> results;
        vector<int> path;
        backtrack(candidates, target, 0, path, results);
        return results;
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
    auto ans = sol.combinationSum(nums, target);

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
        {2,3,6,7},
        7,
        {
            {2,2,3},
            {7}
        }
    );

    runTest(
        {2,3,5},
        8,
        {
            {2,2,2,2},
            {2,3,3},
            {3,5}
        }
    );

    return 0;
}