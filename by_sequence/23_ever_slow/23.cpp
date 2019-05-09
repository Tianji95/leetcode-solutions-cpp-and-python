/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
bool compareFunc(ListNode* left, ListNode* right){
    return left->val < right->val;
}
class Solution {
public:

    ListNode* mergeKLists(vector<ListNode*>& lists) {
        vector<ListNode*> sortedNode;
        int len = lists.size();
        ListNode *head;
        ListNode *now;
        ListNode *tmpFirst;
        if(len == 0)
            return NULL;
        if(len == 1)
            return lists[0];
        
        for(int i = 0; i < len; i++){
            if(lists[i])
                sortedNode.push_back(lists[i]);
        }
        if(sortedNode.size() == 0)
            return NULL;
        std::sort(sortedNode.begin(), sortedNode.end(), compareFunc);
        tmpFirst = sortedNode[0];
        sortedNode.erase(sortedNode.begin());
        head = now = tmpFirst;
        if(tmpFirst->next){
            sortedNode.push_back(tmpFirst->next);
            std::sort(sortedNode.begin(), sortedNode.end(), compareFunc);
        }

        
        while(sortedNode.size()){
            tmpFirst = sortedNode[0];
            sortedNode.erase(sortedNode.begin());
            now->next = tmpFirst;
            now = now->next;
            if(tmpFirst->next){
                sortedNode.push_back(tmpFirst->next);
                std::sort(sortedNode.begin(), sortedNode.end(), compareFunc);
            }
                
            
        }
        return head;
    }
};