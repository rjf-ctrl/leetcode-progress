#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <sstream>

using namespace std;

// Definition for a binary tree node.
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

class Solution {
public:

    int height(TreeNode* root){
        if (!root) return 0;
        return 1 + max(height(root->left), height(root->right));
    }

    bool isBalanced(TreeNode* root) {
        if(!root) return true;
        if(abs(height(root->left)-height(root->right))<=1) return true & isBalanced(root->left) && isBalanced(root->right);
        return false;
    }
};

// Function to build tree from level-order input
TreeNode* buildTree(const vector<string>& nodes) {
    if (nodes.empty() || nodes[0] == "null")
        return nullptr;

    TreeNode* root = new TreeNode(stoi(nodes[0]));
    queue<TreeNode*> q;
    q.push(root);

    int i = 1;

    while (!q.empty() && i < nodes.size()) {
        TreeNode* curr = q.front();
        q.pop();

        // Left child
        if (i < nodes.size() && nodes[i] != "null") {
            curr->left = new TreeNode(stoi(nodes[i]));
            q.push(curr->left);
        }
        i++;

        // Right child
        if (i < nodes.size() && nodes[i] != "null") {
            curr->right = new TreeNode(stoi(nodes[i]));
            q.push(curr->right);
        }
        i++;
    }

    return root;
}

int main() {
    Solution sol;

    int t;
    cin >> t;
    cin.ignore();

    while (t--) {
        string line;
        getline(cin, line);

        stringstream ss(line);
        vector<string> nodes;
        string temp;

        while (ss >> temp) {
            nodes.push_back(temp);
        }

        TreeNode* root = buildTree(nodes);

        // Call solution
        bool ans = sol.isBalanced(root);

        cout << "Test case passed" << endl;
    }

    return 0;
}