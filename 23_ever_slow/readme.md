虽然算法都一样，但是vector用的实在是太糟糕了，应该用优先队列（priority_queue）的：
    
    class Solution {
    public:
        ListNode* mergeKLists(vector<ListNode*>& lists) {
            auto comp = [](ListNode* l1, ListNode* l2) {return l1->val > l2->val;};
            priority_queue<ListNode*, vector<ListNode*>, decltype(comp)> Q(comp);
            for(auto l:lists)
                if(l) Q.push(l);
            ListNode dummy(0);
            ListNode* pt = &dummy;
            while(Q.size() >= 1) {
                pt->next = Q.top();
                Q.pop();
                pt = pt->next;
                if(pt->next && !Q.empty())
                    Q.push(pt->next);
            }
            return dummy.next;
        }
    };