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
    int calculSum(TreeNode* node){
                
        int leftMax  = 0;
        int rightMax = 0;
        if(node->left)
            leftMax = calculSum(node->left);
        if(node->right)
            rightMax = calculSum(node->right);
        
        if(leftMax + rightMax + node->val > out)
            out = leftMax + rightMax + node->val;
        if(leftMax+node->val> out)
            out = leftMax+node->val;
        if(rightMax + node->val > out)
            out = rightMax + node->val;
        if(node->val > out)
            out = node->val;
        
        int nowMax = leftMax > rightMax ? leftMax:rightMax;
        if(nowMax>0)
            return nowMax + node->val;
        else
            return node->val;
    }
        
    int maxPathSum(TreeNode* root) {
        if(!root)
            return 0;
        
        out = INT_MIN;
        int leftMax  = 0;
        int rightMax = 0;
        if(root->left)
            leftMax = calculSum(root->left);
        if(root->right)
            rightMax = calculSum(root->right);
        
        if(leftMax + rightMax + root->val > out)
            out = leftMax + rightMax + root->val;
        if(leftMax+root->val> out)
            out = leftMax+root->val;
        if(rightMax + root->val > out)
            out = rightMax + root->val;
        if(root->val > out)
            out = root->val;
        
        return out;
            
        
    }
    int out;
};