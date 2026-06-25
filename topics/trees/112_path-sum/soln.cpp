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
   
    bool hasPathSum(TreeNode* root, int targetSum) {
        if(!root) return false;
        if(!root->left && !root->right) {
            if(targetSum-root->val==0) return true;
            return false;
        }
        int take=targetSum-root->val;
        return hasPathSum(root->left, take) || hasPathSum(root->right, take);
    }
};

int main() {
    Solution sol;

    vector<pair<pair<TreeNode*, int>, bool>> tests;

    // Test 1: [5,4,8,11,null,13,4,7,2,null,null,null,1], 22 -> true
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

        tests.push_back({{root, 22}, true});
    }

    // Test 2: [1,2,3], 5 -> false
    {
        TreeNode* root = new TreeNode(1);
        root->left = new TreeNode(2);
        root->right = new TreeNode(3);

        tests.push_back({{root, 5}, false});
    }

    // Test 3: [1,2], 1 -> false
    {
        TreeNode* root = new TreeNode(1);
        root->left = new TreeNode(2);

        tests.push_back({{root, 1}, false});
    }

    // Test 4: [1], 1 -> true
    {
        TreeNode* root = new TreeNode(1);

        tests.push_back({{root, 1}, true});
    }

    // Test 5: [1,-2,-3,1,3,-2,null,-1], -1 -> true
    {
        TreeNode* root = new TreeNode(1);
        root->left = new TreeNode(-2);
        root->right = new TreeNode(-3);
        root->left->left = new TreeNode(1);
        root->left->right = new TreeNode(3);
        root->right->left = new TreeNode(-2);
        root->left->left->left = new TreeNode(-1);

        tests.push_back({{root, -1}, true});
    }

    for (int i = 0; i < tests.size(); i++) {
        bool ans = sol.hasPathSum(tests[i].first.first, tests[i].first.second);

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