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
    ListNode* reverseTotal(ListNode* leftprev, ListNode*right){
        ListNode* left = leftprev->next;
        ListNode* next;
        ListNode* rightNext = right->next;
        ListNode* prev = leftprev;
        
        while(left!=right){
            next = left->next;
            left->next = prev;
            prev = left;
            left = next;
        }
        next = left->next;
        left->next = prev;
        right = leftprev->next;
        leftprev->next->next = rightNext;
        leftprev->next = left;
        
        return right;
    }
    
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(k == 1)
            return head;
        if(!head)
            return NULL;
        
        ListNode *left = new ListNode(0);
        left->next = head;
        head = left;
        ListNode *right = left;
        int count = 0;
        
        while(right){
            if(count == k){
                left = reverseTotal(left, right);
                right = left;
                count = 0;
            }
            right = right->next;
            count++;
        }
        return head->next;
    }
};