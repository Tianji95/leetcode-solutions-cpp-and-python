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
    void recoverTree(TreeNode* root) {
        vector<TreeNode*> nodes;
        vector<int> vals;
        
        inorder(root, nodes, vals);
        sort(vals.begin(), vals.end());
        for (int i = 0; i < vals.size(); i++)
            nodes[i]->val = vals[i];
    }
    
    void inorder(TreeNode* root, vector<TreeNode*>& nodes, vector<int>& vals) {
        if (root == NULL)
            return;
        inorder(root->left, nodes, vals);
        nodes.push_back(root);
        vals.push_back(root->val);
        inorder(root->right, nodes, vals);
    }
};