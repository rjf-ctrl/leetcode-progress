#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    int good = 0;

    void dfs(TreeNode* root, int mx) {
        if (!root) return;

        if (root->val >= mx) {
            good++;
            mx = root->val;
        }

        dfs(root->left, mx);
        dfs(root->right, mx);
    }

    int goodNodes(TreeNode* root) {
        good = 0;                 // Reset for each test case
        dfs(root, INT_MIN);
        return good;
    }
};

int main() {
    Solution sol;

    vector<pair<TreeNode*, int>> tests;

    // Test 1: [3,1,4,3,null,1,5] -> 4
    {
        TreeNode* root = new TreeNode(3);
        root->left = new TreeNode(1);
        root->right = new TreeNode(4);
        root->left->left = new TreeNode(3);
        root->right->left = new TreeNode(1);
        root->right->right = new TreeNode(5);

        tests.push_back({root, 4});
    }

    // Test 2: [3,3,null,4,2] -> 3
    {
        TreeNode* root = new TreeNode(3);
        root->left = new TreeNode(3);
        root->left->left = new TreeNode(4);
        root->left->right = new TreeNode(2);

        tests.push_back({root, 3});
    }

    // Test 3: [1] -> 1
    {
        TreeNode* root = new TreeNode(1);

        tests.push_back({root, 1});
    }

    // Test 4: [2,2,2] -> 3
    {
        TreeNode* root = new TreeNode(2);
        root->left = new TreeNode(2);
        root->right = new TreeNode(2);

        tests.push_back({root, 3});
    }

    // Test 5: [5,4,6,3,null,5,7] -> 3
    {
        TreeNode* root = new TreeNode(5);
        root->left = new TreeNode(4);
        root->right = new TreeNode(6);
        root->left->left = new TreeNode(3);
        root->right->left = new TreeNode(5);
        root->right->right = new TreeNode(7);

        tests.push_back({root, 3});
    }

    for (int i = 0; i < tests.size(); i++) {
        int ans = sol.goodNodes(tests[i].first);

        cout << "Test " << i + 1 << ": ";

        if (ans == tests[i].second)
            cout << "PASS";
        else
            cout << "FAIL";

        cout << " | Expected = " << tests[i].second
             << ", Got = " << ans << '\n';
    }

    return 0;
}