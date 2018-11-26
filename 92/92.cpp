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
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        int count = 1;
        ListNode* tmpHead;
        ListNode* left = new ListNode(-1);
        ListNode* oriLeft = left;
        left->next = head;
        ListNode* now = head;
        ListNode* right;
        bool isRever = false;
        
        while(now){
            if(m == count){
                tmpHead = left;
                isRever = true;
            }
            
            if(isRever){
                right = now->next;
                now->next = left;
                left = now;
                now = right;
                if(now)
                    right = now->next;
            }
            else{
                left = now;
                now = now->next;
                if(now)
                    right = now->next;
            }
            if(n == count){
                if(tmpHead->next)
                    tmpHead->next->next = now;
                tmpHead->next = left;
                isRever = false;
            }
            count++;
        }
        return oriLeft->next;
        
        
    }
};