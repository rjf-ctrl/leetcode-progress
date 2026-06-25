#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

/*--------------------------------------------------
Approach 1
--------------------------------------------------*/

class Solution1 {
public:
    int ans = -1;

    void inorder(TreeNode* root, int& k) {
        if (!root)
            return;

        inorder(root->left, k);

        if (--k == 0) {
            ans = root->val;
            return;
        }

        inorder(root->right, k);
    }

    int kthSmallest(TreeNode* root, int k) {
        ans = -1;
        inorder(root, k);
        return ans;
    }
};

/*--------------------------------------------------
Approach 2 (Early Exit)
--------------------------------------------------*/

class Solution2 {
public:
    int ans = -1;

    void inorder(TreeNode* root, int& k) {
        if (!root || ans != -1)
            return;

        inorder(root->left, k);

        if (--k == 0) {
            ans = root->val;
            return;
        }

        inorder(root->right, k);
    }

    int kthSmallest(TreeNode* root, int k) {
        ans = -1;
        inorder(root, k);
        return ans;
    }
};

struct TestCase {
    TreeNode* root;
    int k;
    int expected;
};

int main() {

    vector<TestCase> tests;

    // Test 1
    //      3
    //     / \
    //    1   4
    //     \
    //      2
    {
        TreeNode* n3 = new TreeNode(3);
        TreeNode* n1 = new TreeNode(1);
        TreeNode* n4 = new TreeNode(4);
        TreeNode* n2 = new TreeNode(2);

        n3->left = n1;
        n3->right = n4;
        n1->right = n2;

        tests.push_back({n3, 1, 1});
    }

    // Test 2
    //        5
    //      /   \
    //     3     6
    //    / \
    //   2   4
    //  /
    // 1
    {
        TreeNode* n5 = new TreeNode(5);
        TreeNode* n3 = new TreeNode(3);
        TreeNode* n6 = new TreeNode(6);
        TreeNode* n2 = new TreeNode(2);
        TreeNode* n4 = new TreeNode(4);
        TreeNode* n1 = new TreeNode(1);

        n5->left = n3;
        n5->right = n6;
        n3->left = n2;
        n3->right = n4;
        n2->left = n1;

        tests.push_back({n5, 3, 3});
    }

    // Test 3
    {
        TreeNode* root = new TreeNode(1);
        tests.push_back({root, 1, 1});
    }

    Solution1 s1;
    Solution2 s2;

    cout << "Testing Solution 1\n";

    for (int i = 0; i < tests.size(); i++) {
        int ans = s1.kthSmallest(tests[i].root, tests[i].k);

        cout << "Test " << i + 1 << ": ";

        if (ans == tests[i].expected)
            cout << "PASS";
        else
            cout << "FAIL";

        cout << " | Expected = " << tests[i].expected
             << ", Got = " << ans << '\n';
    }

    cout << "\nTesting Solution 2\n";

    for (int i = 0; i < tests.size(); i++) {
        int ans = s2.kthSmallest(tests[i].root, tests[i].k);

        cout << "Test " << i + 1 << ": ";

        if (ans == tests[i].expected)
            cout << "PASS";
        else
            cout << "FAIL";

        cout << " | Expected = " << tests[i].expected
             << ", Got = " << ans << '\n';
    }

    return 0;
}