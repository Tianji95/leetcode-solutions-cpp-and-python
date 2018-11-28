class Solution {
    
    TreeNode *helper(vector<int>& inorder, vector<int>& postorder,
                     int inleft, int inright, int *pre)
    {
        int idx;
        TreeNode *ret;
        if (inleft > inright || *pre < 0) return NULL;
        for (idx = inright; idx >= inleft; idx --) 
            if (inorder[idx] == postorder[*pre]) break;
        if (idx < inleft) return NULL;
        
        ret = new TreeNode(postorder[*pre]);
        (*pre) --;
        ret->right = helper(inorder, postorder, idx+1, inright, pre);
        ret->left = helper(inorder, postorder, inleft, idx-1, pre);
        return ret;
    }
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int i = postorder.size() - 1;
        return helper(inorder, postorder, 0, inorder.size() - 1, &i);
    }
};