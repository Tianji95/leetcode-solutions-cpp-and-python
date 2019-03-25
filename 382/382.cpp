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
    ListNode* m_head;
    /** @param head The linked list's head.
        Note that the head is guaranteed to be not null, so it contains at least one node. */
    Solution(ListNode* head) {
        m_head = head;
    }
    
    /** Returns a random node's value. */
    int getRandom() {
        
        ListNode* node = m_head;
        int outVal = 0;
        int i = 1;
        while(node){
            if(rand() % i++ == 0){
                outVal = node->val;
            }
            node = node->next;
        }
        return outVal;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution obj = new Solution(head);
 * int param_1 = obj.getRandom();
 */