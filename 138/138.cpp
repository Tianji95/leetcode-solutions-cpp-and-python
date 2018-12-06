/**
 * Definition for singly-linked list with a random pointer.
 * struct RandomListNode {
 *     int label;
 *     RandomListNode *next, *random;
 *     RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
 * };
 */
class Solution {
public:
    RandomListNode *copyRandomList(RandomListNode *head) {
        if(!head)
            return nullptr;
        RandomListNode* out = new RandomListNode(head->label);
        nodeMap[head] = out;
        RandomListNode* now = out;
        RandomListNode* oldHead = head;
        
        while(head->next){
            now->next = new RandomListNode(head->next->label);
            nodeMap[head->next] = now->next;
            now = now->next;
            head = head->next;
        }
        
        head = oldHead;
        now  = out;
        while(head){
            now->random = nodeMap[head->random];
            head = head->next;
            now  = now->next;
        }
        return out;
    }
    unordered_map<RandomListNode*, RandomListNode*> nodeMap;
};