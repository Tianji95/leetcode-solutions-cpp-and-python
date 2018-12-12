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
    void reorderList(ListNode* head) {
        if(!head)
            return ;
        vector<ListNode*> listVector;
        ListNode* now = head;
        
        while(now){
            listVector.push_back(now);
            now = now->next;
        }
        int len = listVector.size();
        int font = 1;
        int back = len - 1;
        now = listVector[0];
        while(font <= back){
            now->next = listVector[back--];
            now = now->next;
            if(font <= back){
                now->next = listVector[font++];
                now = now->next;
            }
        }
        now->next = nullptr;
    }
};