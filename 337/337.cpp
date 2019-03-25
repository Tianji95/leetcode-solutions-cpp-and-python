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
    unordered_map<TreeNode*, int> mp;
    int rob(TreeNode* root) {
        if(!root){
            return 0;
        }
        if(mp.find(root)!=mp.end()){
            return mp[root];
        }
        int removeSelf = 0;
        int addSelf = root->val;
        TreeNode* left  = root->left;
        TreeNode* right = root->right;
        
        if(left){
            removeSelf += rob(left);
            if(left->left){
                addSelf += rob(left->left);
            }
            if(left->right){
                addSelf += rob(left->right);
            }
        }
        if(right){
            removeSelf += rob(right);
            if(right->left){
                addSelf += rob(right->left);
            }
            if(right->right){
                addSelf += rob(right->right);
            }
        };
        mp[root] = max(addSelf, removeSelf);
        return mp[root] ;
        
        
    }
};