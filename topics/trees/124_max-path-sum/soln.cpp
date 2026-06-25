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
    int solve(TreeNode* root, int& maxSum) {
        if (root == nullptr)
            return 0;

        int left = solve(root->left, maxSum);
        int right = solve(root->right, maxSum);

        // Best downward path
        int oneSide = max(left, right) + root->val;

        // Path containing only the current node
        int onlyRoot = root->val;

        // Path passing through the current node
        int throughRoot = left + right + root->val;

        maxSum = max({maxSum, oneSide, onlyRoot, throughRoot});

        return max(oneSide, onlyRoot);
    }

    int maxPathSum(TreeNode* root) {
        int maxSum = INT_MIN;
        solve(root, maxSum);
        return maxSum;
    }
};

int main() {
    Solution sol;

    vector<pair<TreeNode*, int>> tests;

    // Test 1: [1,2,3] -> 6
    {
        TreeNode* root = new TreeNode(1);
        root->left = new TreeNode(2);
        root->right = new TreeNode(3);
        tests.push_back({root, 6});
    }

    // Test 2: [-10,9,20,null,null,15,7] -> 42
    {
        TreeNode* root = new TreeNode(-10);
        root->left = new TreeNode(9);
        root->right = new TreeNode(20);
        root->right->left = new TreeNode(15);
        root->right->right = new TreeNode(7);
        tests.push_back({root, 42});
    }

    // Test 3: [-3] -> -3
    {
        TreeNode* root = new TreeNode(-3);
        tests.push_back({root, -3});
    }

    // Test 4: [2,-1] -> 2
    {
        TreeNode* root = new TreeNode(2);
        root->left = new TreeNode(-1);
        tests.push_back({root, 2});
    }

    // Test 5: [1,-2,-3,1,3,-2,null,-1] -> 3
    {
        TreeNode* root = new TreeNode(1);
        root->left = new TreeNode(-2);
        root->right = new TreeNode(-3);
        root->left->left = new TreeNode(1);
        root->left->right = new TreeNode(3);
        root->right->left = new TreeNode(-2);
        root->left->left->left = new TreeNode(-1);
        tests.push_back({root, 3});
    }

    // Test 6: [5,4,8,11,null,13,4,7,2,null,null,null,1] -> 48
    {
        TreeNode* root = new TreeNode(5);
        root->left = new TreeNode(4);
        root->right = new TreeNode(8);
        root->left->left = new TreeNode(11);
        root->left->left->left = new TreeNode(7);
        root->left->left->right = new TreeNode(2);
        root->right->left = new TreeNode(13);
        root->right->right = new TreeNode(4);
        root->right->right->right = new TreeNode(1);
        tests.push_back({root, 48});
    }

    // Test 7: [1] -> 1
    {
        TreeNode* root = new TreeNode(1);
        tests.push_back({root, 1});
    }

    // Test 8: [-2,-1] -> -1
    {
        TreeNode* root = new TreeNode(-2);
        root->left = new TreeNode(-1);
        tests.push_back({root, -1});
    }

    // Run Tests
    for (int i = 0; i < tests.size(); i++) {
        int ans = sol.maxPathSum(tests[i].first);

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