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
    ListNode* mergeSort(ListNode* innode, int len){
        if(len == 1){
            innode->next = nullptr;
            return innode;
        }
            
        
        int middle = len / 2;
        ListNode* tmpnow = innode;
        while(tmpnow && middle > 0){
            tmpnow = tmpnow->next;
            middle--;
        }
        ListNode* node = mergeSort(innode, len/2);
        ListNode* now  = mergeSort(tmpnow, len - len/2);
        ListNode* returnhead;
        ListNode* head;
        if(node->val > now->val){
            head = now;
            now = now->next;
        }
        else{
            head = node;
            node = node->next;
        }
        returnhead = head;
        while(node && now){
            if(node->val > now->val){
                head->next = now;
                head = head->next;
                now = now->next;
            }
            else{
                head->next = node;
                head = head->next;
                node = node->next;
            }
        }
        while(node){
            head->next = node;
            head = head->next;
            node = node->next;
        }
        while(now){
            head->next = now;
            head = head->next;
            now = now->next;
        }
        head->next = nullptr;
        return returnhead;
            

    }
    
    ListNode* sortList(ListNode* head) {
        int len = 0;
        ListNode* now = head;
        if(!head)
            return head;
        while(now){
            len++;
            now = now->next;
        }
        return mergeSort(head, len);
        
    }
};