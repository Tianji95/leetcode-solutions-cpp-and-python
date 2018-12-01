/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */
class Solution {
public:
    void connectTree(TreeLinkNode* node){
        if(node->left && node->right){
            node->left->next = node->right;
            if(node->next)
                node->right->next = node->next->left;
            else
                node->right->next = nullptr;
            
            connectTree(node->left);
            connectTree(node->right);
            

        }
    }
    
    void connect(TreeLinkNode *root) {
        if(!root)
            return ;
        root->next = nullptr;
        if(root->left && root->right){
            root->left->next = root->right;
            root->right->next = nullptr;
            connectTree(root->left);
            connectTree(root->right);
        }
    }
};