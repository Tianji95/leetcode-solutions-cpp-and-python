/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
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
    TreeNode* buildTree(int start, int end){
        if(start > end)
            return nullptr;
        
        int mid = (start + end) / 2;
        TreeNode* newNode = new TreeNode(nodeVector[mid]->val);
        newNode->left = buildTree(start, mid-1);
        newNode->right = buildTree(mid+1, end);
        
        return newNode;
    }
    
    TreeNode* sortedListToBST(ListNode* head) {
        
        ListNode* nowNode = head;
        
        while(nowNode){
            nodeVector.push_back(nowNode);
            nowNode = nowNode->next;
        }
        
        return buildTree(0, nodeVector.size()-1);
        
    }
    vector<ListNode*> nodeVector;
};