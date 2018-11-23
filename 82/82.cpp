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
    ListNode* deleteDuplicates(ListNode* head) {
        
        
        if(head == NULL)
            return head;
        ListNode* left  = head->next;
        if(left==NULL)
            return head;
        
        ListNode* right = left->next;
        ListNode* last  = head;
        ListNode* delNode;
        bool isDup = false;
        
        while(left&&last->val == left->val){
            while(left&&last->val == left->val){
                delNode = left;
                left = left->next;
                head = left;
                delete delNode;
            }
            if(head == NULL)
                return NULL;
            left = head->next;
            if(left == NULL)
                return head;
            right = left->next;
            last  = head;
        }
        while(right){
            if(right->val == left->val){
                delNode = right;
                left->next = right->next;
                right = right->next;
                delete delNode;
                isDup = true;
                
            }
            else{
                if(isDup){
                    delNode = left;
                    last->next = right;
                    delete delNode;
                    isDup = false;
                    right = right->next;
                    left = last->next;
                }
                else{
                    last = last->next;
                    right = right->next;
                    left = left->next;
                }
            }
        }
        if(isDup){
            delNode = left;
            last->next = right;
            left = last;
            delete delNode;
        }
        return head;
    }
};