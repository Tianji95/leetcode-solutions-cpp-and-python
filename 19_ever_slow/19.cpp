class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* first = head;
        ListNode* second = head;
        
        for(int i = 0; i < n; i++){
            first = first->next;
        }
        
        while(first && first->next){
            first = first->next;
            second = second->next;
        }
        
        if(first){
            ListNode* delNode;
            delNode = second->next;
            second->next = second->next->next;
            delete delNode;
        }
        else{
            ListNode* delNode;
            delNode = second;
            head = second->next;
            delete delNode;
        }
        return head;
    }
};