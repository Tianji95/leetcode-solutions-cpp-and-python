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
        if(node->left)
            iterout(node->left);
        if(node->right)
            iterout(node->right);
        
        out.push_back(node->val);
    }
    
    vector<int> postorderTraversal(TreeNode* root) {
        if(!root)
            return out;
        if(root->left)
            iterout(root->left);
        if(root->right)
            iterout(root->right);
        
        out.push_back(root->val);
        
        return out;
    }
    vector<int> out;
};