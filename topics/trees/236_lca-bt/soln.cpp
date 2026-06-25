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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (!root || root == p || root == q)
            return root;

        TreeNode* left = lowestCommonAncestor(root->left, p, q);
        TreeNode* right = lowestCommonAncestor(root->right, p, q);

        if (left && right)
            return root;

        return left ? left : right;
    }
};

int main() {
    Solution sol;

    struct TestCase {
        TreeNode* root;
        TreeNode* p;
        TreeNode* q;
        int expected;
    };

    vector<TestCase> tests;

    // Common Tree
    //
    //          3
    //        /   \
    //       5     1
    //      / \   / \
    //     6   2 0   8
    //        / \
    //       7   4
    //
    {
        TreeNode* n3 = new TreeNode(3);
        TreeNode* n5 = new TreeNode(5);
        TreeNode* n1 = new TreeNode(1);
        TreeNode* n6 = new TreeNode(6);
        TreeNode* n2 = new TreeNode(2);
        TreeNode* n0 = new TreeNode(0);
        TreeNode* n8 = new TreeNode(8);
        TreeNode* n7 = new TreeNode(7);
        TreeNode* n4 = new TreeNode(4);

        n3->left = n5;
        n3->right = n1;
        n5->left = n6;
        n5->right = n2;
        n1->left = n0;
        n1->right = n8;
        n2->left = n7;
        n2->right = n4;

        tests.push_back({n3, n5, n1, 3});
        tests.push_back({n3, n5, n4, 5});
        tests.push_back({n3, n7, n4, 2});
        tests.push_back({n3, n6, n4, 5});
        tests.push_back({n3, n0, n8, 1});
    }

    for (int i = 0; i < tests.size(); i++) {
        TreeNode* ans = sol.lowestCommonAncestor(
            tests[i].root,
            tests[i].p,
            tests[i].q
        );

        cout << "Test " << i + 1 << ": ";

        if (ans && ans->val == tests[i].expected)
            cout << "PASS";
        else
            cout << "FAIL";

        cout << " | Expected = " << tests[i].expected
             << ", Got = "
             << (ans ? to_string(ans->val) : "NULL")
             << '\n';
    }

    return 0;
}