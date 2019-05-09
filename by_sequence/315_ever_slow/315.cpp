class Solution {
public:
    // Count of Smaller Numbers After Self => Count of Smaller Numbers Before Self
    struct TreeNode {
        int val;
        int count;
        int left_count;
        TreeNode *left;
        TreeNode *right;
        TreeNode(int val) {
            this->val = val;
            count = 1;
            left_count = 0;
            left = NULL;
            right = NULL;
        }
    };
    
    vector<int> countSmaller(vector<int>& nums) {
        if(nums.size() == 0) {
            return vector<int>{};
        }
        reverse(nums.begin(), nums.end());
        vector<int> ret(nums.size(), 0);
        TreeNode *root = new TreeNode(nums[0]);
        for(int i = 1; i < nums.size(); i++) {
            ret[i] = insert(root, nums[i]);
        }
        reverse(ret.begin(), ret.end());
        return ret;
    }
    
    int insert(TreeNode *root, int val) {
        if(val < root->val) {//insert left
            root->left_count += 1;
            if(!root->left) {
                root->left = new TreeNode(val);
                return 0;
            }
            return insert(root->left, val);    
        }
        else if(val > root->val) {//insert right////////////////////////////////
            if(!root->right) {
                root->right = new TreeNode(val);
                //root->right->left_count = root->left_count + root->count;
                return root->left_count + root->count;    
            }   
            return insert(root->right, val) + root->left_count + root->count;
            //return insert(root->right, val);
        }
        else {
            root->count += 1;
            return root->left_count;
        }
    }
};