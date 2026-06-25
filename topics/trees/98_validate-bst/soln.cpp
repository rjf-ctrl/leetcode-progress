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
    bool dfs(TreeNode* root, long long low, long long high) {
        if (!root)
            return true;

        if (root->val <= low || root->val >= high)
            return false;

        return dfs(root->left, low, root->val) &&
               dfs(root->right, root->val, high);
    }

    bool isValidBST(TreeNode* root) {
        return dfs(root, LLONG_MIN, LLONG_MAX);
    }
};

int main() {
    Solution sol;

    vector<pair<TreeNode*, bool>> tests;

    // Test 1: [2,1,3] -> true
    {
        TreeNode* root = new TreeNode(2);
        root->left = new TreeNode(1);
        root->right = new TreeNode(3);
        tests.push_back({root, true});
    }

    // Test 2: [5,1,4,null,null,3,6] -> false
    {
        TreeNode* root = new TreeNode(5);
        root->left = new TreeNode(1);
        root->right = new TreeNode(4);
        root->right->left = new TreeNode(3);
        root->right->right = new TreeNode(6);
        tests.push_back({root, false});
    }

    // Test 3: [2147483647] -> true
    {
        TreeNode* root = new TreeNode(INT_MAX);
        tests.push_back({root, true});
    }

    // Test 4: [-2147483648] -> true
    {
        TreeNode* root = new TreeNode(INT_MIN);
        tests.push_back({root, true});
    }

    // Test 5: [10,5,15,null,null,6,20] -> false
    {
        TreeNode* root = new TreeNode(10);
        root->left = new TreeNode(5);
        root->right = new TreeNode(15);
        root->right->left = new TreeNode(6);
        root->right->right = new TreeNode(20);
        tests.push_back({root, false});
    }

    // Test 6: [1,1] -> false
    {
        TreeNode* root = new TreeNode(1);
        root->left = new TreeNode(1);
        tests.push_back({root, false});
    }

    // Test 7: Empty tree -> true
    {
        TreeNode* root = nullptr;
        tests.push_back({root, true});
    }

    for (int i = 0; i < tests.size(); i++) {
        bool ans = sol.isValidBST(tests[i].first);

        cout << "Test " << i + 1 << ": ";

        if (ans == tests[i].second)
            cout << "PASS";
        else
            cout << "FAIL";

        cout << " | Expected = "
             << (tests[i].second ? "true" : "false")
             << ", Got = "
             << (ans ? "true" : "false")
             << '\n';
    }

    return 0;
}