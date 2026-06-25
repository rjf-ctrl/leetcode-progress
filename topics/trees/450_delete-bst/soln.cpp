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
    TreeNode* findMin(TreeNode* root) {
        while (root->left)
            root = root->left;
        return root;
    }

    TreeNode* deleteNode(TreeNode* root, int key) {
        if (!root)
            return nullptr;

        if (key < root->val)
            root->left = deleteNode(root->left, key);

        else if (key > root->val)
            root->right = deleteNode(root->right, key);

        else {
            // Case 1: Leaf
            if (!root->left && !root->right)
                return nullptr;

            // Case 2: One child
            if (!root->left)
                return root->right;

            if (!root->right)
                return root->left;

            // Case 3: Two children
            TreeNode* successor = findMin(root->right);
            root->val = successor->val;
            root->right = deleteNode(root->right, successor->val);
        }

        return root;
    }
};

bool sameTree(TreeNode* a, TreeNode* b) {
    if (!a && !b) return true;
    if (!a || !b) return false;

    return a->val == b->val &&
           sameTree(a->left, b->left) &&
           sameTree(a->right, b->right);
}

int main() {
    Solution sol;

    struct TestCase {
        TreeNode* input;
        int key;
        TreeNode* expected;
    };

    vector<TestCase> tests;

    // Test 1
    // Delete Leaf
    {
        TreeNode* root = new TreeNode(5);
        root->left = new TreeNode(3);
        root->right = new TreeNode(6);
        root->left->left = new TreeNode(2);
        root->left->right = new TreeNode(4);
        root->right->right = new TreeNode(7);

        TreeNode* exp = new TreeNode(5);
        exp->left = new TreeNode(4);
        exp->right = new TreeNode(6);
        exp->left->left = new TreeNode(2);
        exp->right->right = new TreeNode(7);

        tests.push_back({root, 3, exp});
    }

    // Test 2
    // Delete Root
    {
        TreeNode* root = new TreeNode(2);
        root->left = new TreeNode(1);
        root->right = new TreeNode(3);

        TreeNode* exp = new TreeNode(3);
        exp->left = new TreeNode(1);

        tests.push_back({root, 2, exp});
    }

    // Test 3
    // Delete Non-existent Node
    {
        TreeNode* root = new TreeNode(2);
        root->left = new TreeNode(1);

        TreeNode* exp = new TreeNode(2);
        exp->left = new TreeNode(1);

        tests.push_back({root, 5, exp});
    }

    // Test 4
    // Delete Only Node
    {
        TreeNode* root = new TreeNode(1);

        tests.push_back({root, 1, nullptr});
    }

    for (int i = 0; i < tests.size(); i++) {

        TreeNode* ans = sol.deleteNode(tests[i].input, tests[i].key);

        cout << "Test " << i + 1 << ": ";

        if (sameTree(ans, tests[i].expected))
            cout << "PASS";
        else
            cout << "FAIL";

        cout << '\n';
    }

    return 0;
}