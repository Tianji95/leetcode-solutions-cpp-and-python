/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        ListNode* smallList = new ListNode(0);
        smallList->next = head;
        ListNode* smallHead = smallList;
        ListNode* left = new ListNode(0);
        ListNode* leftHead = left;
        left->next = head;
        ListNode* right = head;
        if(!right)
            return NULL;
			
        while(right){
            if(right->val < x){
                smallList->next = right;
                smallList = smallList->next;
                left->next = right->next; 
            }
            else{
                left = right;
            }
            right = right->next;
        }
        smallList->next = leftHead->next;
        return smallHead->next;
    }
};