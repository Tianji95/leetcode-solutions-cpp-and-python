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
    ListNode* swapPairs(ListNode* head) {
        ListNode* left;
        ListNode* right;
        ListNode* now;
        ListNode* tmp;
        
        if(!head)
            return NULL;
        if(!(head->next))
            return head;
        
        left = now = head;
        right = head->next;
        head = right;
        left->next = right->next;
        right->next = left;
        if(left->next)
            right = left->next->next;
        else
            right = left->next;
        
        
        while(left && right){
            tmp = left->next;
            left->next = right;
            tmp->next = right->next;
            right->next = tmp;
            
            left = tmp;
            if(left->next)
                right = left->next->next;
            else
                right = left->next;
        }
        return head;
    }
};