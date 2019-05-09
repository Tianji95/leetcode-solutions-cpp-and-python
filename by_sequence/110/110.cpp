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
    int calculDepth(TreeNode* node, int depth){
        int leftDepth;
        int rightDepth;
        if(node->left){
            leftDepth = calculDepth(node->left, depth+1);
        }
        else{
            leftDepth = depth;
        }
        if(node->right){
            rightDepth = calculDepth(node->right, depth+1);
        }
        else{
            rightDepth = depth;
        }
        
        if(abs(rightDepth - leftDepth) > 1){
            isB = false;
        }
            
        return rightDepth > leftDepth?rightDepth:leftDepth;
    }
        
    bool isBalanced(TreeNode* root) {
        if(!root)
            return true;
        
        isB = true;
        calculDepth(root, 0);
        return isB;
    }
    bool isB;

};