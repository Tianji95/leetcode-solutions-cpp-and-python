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
    bool calcul(TreeNode* node, int target){
        int now = target - node->val;
        if(!node->left && !node->right){
            if(now == 0){
                return true;
            }
            else{
                return false;
            }
        }
        bool isRight = false;
        bool isLeft  = false;
        if(node->right){
            isRight = calcul(node->right, now);
        }
        if(node->left){
            isLeft = calcul(node->left, now);
        }
        return isLeft || isRight;
    }
    
    bool hasPathSum(TreeNode* root, int sum) {
        if(!root){
            return false;
        }
        return calcul(root, sum);
    }
};