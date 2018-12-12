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
    void iterout(TreeNode* node){
        out.push_back(node->val);
        if(node->left)
            iterout(node->left);
        if(node->right)
            iterout(node->right);
    }
    
    vector<int> preorderTraversal(TreeNode* root) {
        if(!root)
            return out;
        out.push_back(root->val);
        if(root->left)
            iterout(root->left);
        if(root->right)
            iterout(root->right);
        return out;
    }
    vector<int> out;
};