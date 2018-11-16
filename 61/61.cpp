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
    ListNode* rotateRight(ListNode* head, int k) {
        int count = 1;
        int posIdx = 0;
        ListNode *now = head;
        if(head == NULL)
            return NULL;
        if(k == 0)
            return head;
        
        while(now->next){
            now = now->next;
            count++;
        }
        posIdx = count - k % count;
        
        now->next = head;
        now = head;
        int i = 1;
        
        while(i<posIdx){
            now = now->next;
            i++;
        }
        head = now->next;
        now->next = NULL;
        return head;
        
        
        
    }
};