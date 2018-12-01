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
    void connect(TreeLinkNode *root) {
        if(!root)
            return ;
        TreeLinkNode* now = root;
        TreeLinkNode* fatherNext;  
        TreeLinkNode* leftStart = nullptr;
        TreeLinkNode* next;

        while(now){
            while(now){
                if(now->left){
                    if(leftStart == nullptr)
                        leftStart  = now->left;
                    fatherNext = now->next;
                    next = now->right;
                    while(!next&&fatherNext){
                        if(fatherNext->left){
                            next = fatherNext->left;
                            break;
                        }
                        if(fatherNext->right){
                            next = fatherNext->right;
                            break;
                        }
                        fatherNext = fatherNext->next;
                    }
                    now->left->next = next;
                }
                if(now->right){
                    if(leftStart == nullptr)
                        leftStart  = now->right;
                    fatherNext = now->next;
                    if(fatherNext)
                        next = fatherNext->left;
                    else
                        next = nullptr;
                    while(!next&&fatherNext){
                        if(fatherNext->left){
                            next = fatherNext->left;
                            break;
                        }
                        if(fatherNext->right){
                            next = fatherNext->right;
                            break;
                        }
                        fatherNext = fatherNext->next;
                    }
                    now->right->next = next;
                }
                now = now->next;
            }
            now = leftStart;
            leftStart = nullptr;
        }
    }
};