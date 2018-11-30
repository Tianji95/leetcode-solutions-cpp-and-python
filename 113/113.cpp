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
    void calcul(TreeNode* node, vector<int>& tmp, int target){
        int now = target - node->val;
        tmp.push_back(node->val);
        if(!node->left && !node->right){
            if(now==0){
                out.push_back(tmp);
            }
        }
        if(node->left){
            calcul(node->left, tmp, now);
        }
        if(node->right){
            calcul(node->right, tmp, now);
        }
            
        tmp.pop_back();
    }
    
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        if(!root)
            return out;
        
        vector<int> tmp;
        calcul(root, tmp, sum);
        return out;
    }
    
    vector<vector<int>> out;
};