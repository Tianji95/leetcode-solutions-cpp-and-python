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
    void pushValue(TreeNode* node){
        if(node->left)
            pushValue(node->left);
        out.push_back(node->val);
        if(node->right)
            pushValue(node->right);
    }
    
    vector<int> inorderTraversal(TreeNode* root) {
        if(root)
            pushValue(root);
        return out;
    }
    vector<int> out;
};