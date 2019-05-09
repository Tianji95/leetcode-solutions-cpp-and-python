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
    void calculSum(TreeNode* node, int fatherNum){
        int nowNum = fatherNum*10 + node->val;
        
        if(!node->left && !node->right){
            out += nowNum;
            return ;
        }
        if(node->left){
            calculSum(node->left, nowNum);
        }
        if(node->right){
            calculSum(node->right, nowNum);
        }

    }
    
    int sumNumbers(TreeNode* root) {
        if(!root)
            return 0;
        out = 0;
        
        calculSum(root, 0);
        return out;
        
        
    }
    int out;
};