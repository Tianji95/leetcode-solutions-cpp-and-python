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
    ListNode* insertionSortList(ListNode* head) {
        
        ListNode* h   = head;
        ListNode* preHead = new ListNode(INT_MIN);
        preHead->next = head;
        ListNode* ph  = preHead;
        ListNode* afterNow = head;
        ListNode* tile = head;
        
        
        if(!head || !head->next)
            return head;
        ListNode* now = head->next;
        while(now){
            h  = preHead->next;
            ph = preHead;
            while(now->val > h->val && h != now){
                h = h->next;
                ph = ph->next;
            }
            if(tile->val < now->val)
                tile = now;
            if(h == now){
                now = now->next;
                continue;
            }
            ph->next = now;
            tile->next = now->next;
            afterNow = now->next;
            now->next = h;
            now = afterNow;
        }
        tile->next = nullptr;
        
        return preHead->next;
    }
};