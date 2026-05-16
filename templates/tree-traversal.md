/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
# RECURSIVE

## Preorder Traversal

'''
class Solution {
public:
    void preorder(TreeNode*root, vector<int> &result){
        if(!root) return;
        result.push_back(root->val);
        preorder(root->left, result);
        preorder(root->right, result);
        return;
    }
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> result;
        preorder(root, result);
        return result;
    }
};
'''

## Inorder Traversal

'''
class Solution {
public: 
    void inorder(TreeNode *root, vector<int> &result){

        if(!root) return;
        inorder(root->left, result);
        result.push_back(root->val);
        inorder(root->right, result);
        
    }
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> result;
        inorder(root, result);
        return result;
    }
};

'''

## Postorder Traversal

'''
class Solution {
public: 
    void inorder(TreeNode *root, vector<int> &result){

        if(!root) return;
        inorder(root->left, result);
        inorder(root->right, result);
        result.push_back(root->val);

        
    }
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> result;
        inorder(root, result);
        return result;
    }
};

'''