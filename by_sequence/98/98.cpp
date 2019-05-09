class Solution {
public:
    bool checkValid(TreeNode* node, int minValue, int maxValue){
        bool isValid = true;
        if(node->left){
            if(node->left->val < minValue || node->left->val > maxValue || node->left->val >= node->val)
                return false;
            else
                isValid = checkValid(node->left, minValue, min(node->val-1, maxValue)) && isValid;
        }
        if(node->right){
            if(node->right->val < minValue || node->right->val > maxValue || node->right->val <= node->val)
                return false;
            else
                isValid = checkValid(node->right, max(minValue, node->val+1), maxValue) && isValid;
        }
        return isValid;
    }
    bool isValidBST(TreeNode* root) {
        if(!root)
            return true;
        return checkValid(root, INT_MIN, INT_MAX);
    }
};