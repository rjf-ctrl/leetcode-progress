#include <iostream>
using namespace std;

// Definition for binary tree node
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int x) {
        val = x;
        left = nullptr;
        right = nullptr;
    }
};

//---------------------------------------------------------------------------------------------------------------------------------------------

class Solution {
public:
    
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if(!p && !q) return true;
        if(p&&q&& p->val==q->val) return true && isSameTree(p->right, q->right) && isSameTree(p->left, q->left);
        return false;
    }
};

//---------------------------------------------------------------------------------------------------------------------------------------------


void printResult(bool actual, bool expected, string testName) {
    cout << testName << ": ";
    if (actual == expected)
        cout << "PASS";
    else
        cout << "FAIL";
    cout << endl;
}

int main() {

    Solution sol;

    /*
        Test Case 1

            1         1
           / \       / \
          2   3     2   3

        Expected: true
    */

    TreeNode* t1 = new TreeNode(1);
    t1->left = new TreeNode(2);
    t1->right = new TreeNode(3);

    TreeNode* t2 = new TreeNode(1);
    t2->left = new TreeNode(2);
    t2->right = new TreeNode(3);

    printResult(
        sol.isSameTree(t1, t2),
        true,
        "Test Case 1"
    );


    TreeNode* t3 = new TreeNode(1);
    t3->left = new TreeNode(2);

    TreeNode* t4 = new TreeNode(1);
    t4->right = new TreeNode(2);

    printResult(
        sol.isSameTree(t3, t4),
        false,
        "Test Case 2"
    );


    TreeNode* t5 = new TreeNode(1);
    t5->left = new TreeNode(2);
    t5->right = new TreeNode(1);

    TreeNode* t6 = new TreeNode(1);
    t6->left = new TreeNode(1);
    t6->right = new TreeNode(2);

    printResult(
        sol.isSameTree(t5, t6),
        false,
        "Test Case 3"
    );

    return 0;
}