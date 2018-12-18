/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class BSTIterator {
public:
    std::queue<int> Q;
    void buildQ(TreeNode* node){
        if(node->left)
            buildQ(node->left);
        Q.push(node->val);
        if(node->right)
            buildQ(node->right);
    }
    
    BSTIterator(TreeNode *root) {
        if(root){
            if(root->left)
                buildQ(root->left);
            Q.push(root->val);
            if(root->right)
                buildQ(root->right);
        }

        
    }

    /** @return whether we have a next smallest number */
    bool hasNext() {
        if(Q.empty())
            return false;
        else
            return true;
    }

    /** @return the next smallest number */
    int next() {
        int r = Q.front();
        Q.pop();
        return r;
    }
};

/**
 * Your BSTIterator will be called like this:
 * BSTIterator i = BSTIterator(root);
 * while (i.hasNext()) cout << i.next();
 */