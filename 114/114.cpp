/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    void flatten(TreeNode* root) {
        if(!root)
            return;
        
        flatten(root->right);
        flatten(root->left);
        root->left = nullptr;
        root->right = prevNode;
        prevNode = root;
        
    }
    TreeNode* prevNode;
};