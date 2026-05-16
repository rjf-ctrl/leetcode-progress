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

//-------------------------------------------------------------------------------------------------

class Solution {
public:

    TreeNode* invertTree(TreeNode* root) {
        if(!root) return root;
        swap(root->left, root->right);
        invertTree(root->left);
        invertTree(root->right);

        return root;
    }
};

//-------------------------------------------------------------------------------------------------

int main() {

    /*
            Original Tree

                 4
               /   \
              2     7
             / \   / \
            1   3 6   9
    */

    TreeNode* root = new TreeNode(4);

    root->left = new TreeNode(2);
    root->right = new TreeNode(7);

    root->left->left = new TreeNode(1);
    root->left->right = new TreeNode(3);

    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(9);

    Solution sol;

    TreeNode* inverted = sol.invertTree(root);

    /*
            Expected Inverted Tree

                 4
               /   \
              7     2
             / \   / \
            9   6 3   1
    */

    cout << "Root: "
         << inverted->val << endl;

    cout << "Left Child: "
         << inverted->left->val << endl;

    cout << "Right Child: "
         << inverted->right->val << endl;

    cout << "Left->Left: "
         << inverted->left->left->val << endl;

    cout << "Left->Right: "
         << inverted->left->right->val << endl;

    cout << "Right->Left: "
         << inverted->right->left->val << endl;

    cout << "Right->Right: "
         << inverted->right->right->val << endl;

    return 0;
}