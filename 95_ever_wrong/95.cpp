class Solution {
public:
    vector<TreeNode*> generateTrees(int n) {
        TreeNode *mytree;
        
        // First generate all possible configurations
        // with node values pending to be assigned
        vector<TreeNode *> emptyTrees = generateTreeNoVal(n);
        
        //cout << "reached here\n";
        
        if(n == 0)
            return vector<TreeNode *>();
        
        // Now inorder traverse every tree in emptyTrees
        // and assign node values as we traverse. BST outputs
        // valus in sorted increasing order when inorder traversed
        for(int i = 0; i < emptyTrees.size(); i++){
            fillVals(emptyTrees[i]);
        } 
        
        return emptyTrees;
    }

private:
    vector<TreeNode*> generateTreeNoVal(int n){
        vector<TreeNode *> result;
        
        //cout << "generateTreeNoVal: " << n << "\n";
        
        if(n == 0){
            result.push_back(NULL);
            return result;
        }
        
        if(n == 1){
            TreeNode *newroot = new TreeNode(-1);
            result.push_back(newroot);
            return result;
        }
        
        for(int i = 0; i < n ; i++){
            // otpimization here, left and right can be swapped
            // as a mirror image to save some recursion
            vector<TreeNode *> left = generateTreeNoVal(i);
            vector<TreeNode *> right = generateTreeNoVal(n - i - 1);
        
            for(int j = 0; j < left.size(); j++)
                for(int k = 0; k < right.size(); k++){
                    TreeNode *newroot = new TreeNode(-1);
                    newroot->left = left[j];
                    newroot->right = right[k];
                    result.push_back(newroot);
                }
        }
        
        return result;
    }
    
    void fillVals(TreeNode *root){
        TreeNode *cur = root;
        stack<TreeNode *> mystack;
        int       val = 1;
        
        pushLeft(root, mystack);
        
        while(!mystack.empty()){
            cur = mystack.top();
            cur->val = val;
            val++;
            mystack.pop();
            
            if(cur->right){
                pushLeft(cur->right, mystack);
            }
        }
    }
    
    TreeNode* pushLeft(TreeNode *root, stack<TreeNode *>& mystack){
        TreeNode *cur = root;
        
        mystack.push(root);
        while(cur->left){
            mystack.push(cur->left);
            cur = cur->left;
        }
        
        return cur;
    }
    
    TreeNode* deepCopyTree(TreeNode *root){
        TreeNode *newroot = new TreeNode(root->val);
        TreeNode *left = NULL, *right = NULL;
        
        if(root->left){
            left = deepCopyTree(root->left);
        }
        
        if(root->right){
            right = deepCopyTree(root->right);
        }
        
        newroot->left = left;
        newroot->right = right;
        
        return newroot;
    }
};