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


# LEVEL ORDER TRAVERSAL
### with queue

### version 1
'''
 #include <queue>
 struct qNode {
    TreeNode *x;
    int level;
 };

class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> result;
        if(!root) return result;

        queue<qNode> q;
        q.push({root, 0});

        while(!q.empty()){
        
            qNode current = q.front();
            q.pop();

            if(current.level == result.size()){
                result.push_back({});
            }

            result[current.level].push_back(current.x->val);

            if(current.x->left)  q.push({current.x->left, current.level+1});
            if(current.x->right )q.push({current.x->right, current.level+1});
            
        }

        return result;
    }
};
'''


### version 2 : standard
'''
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> result;

        if (!root) return result;

        queue<TreeNode*> q;
        q.push(root);

        while (!q.empty()) {
            
            int size = q.size();
            vector<int> level;

            for (int i = 0; i < size; i++) {
                TreeNode* node = q.front();
                q.pop();

                level.push_back(node->val);

                if (node->left) q.push(node->left);
                if (node->right) q.push(node->right);
            }

            result.push_back(level);
        }

        return result;
    }
};
'''