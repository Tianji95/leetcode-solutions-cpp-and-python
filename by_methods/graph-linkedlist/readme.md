图和链表

这一部分主要是三个节点，前节点，后节点以及中间节点的操作

##### leetcode 题目（24）

2

19

21

23

24

25

61

82

86

92

109

127

133

138

142

143

147

148

200

207

210

328

445

430

457

第 2 题：这道题其实思路不难，主要是代码写的比较干净是稍微麻烦些的事情，这里面主要是把判断放到 while 里面了，看起来就很清楚很干净

```
class Solution{
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* head = new ListNode(0);
        ListNode* node= head;
        ListNode* newnode;
        int addi = 0;
        int val   = 0;

        while(l1 || l2 || addi){
             val = addi;
             if(l1){
                 val += l1->val;
                 l1 = l1->next;
             }
             if(l2){
                 val += l2->val;
                 l2 = l2->next;
             }
             addi = val / 10;
             newnode = new ListNode(val%10);
             node->next = newnode;
             node = node->next;
        }
        return head->next;
    }
};
```

第 19 题，主要是要添加一个 prehead，然后三个指针实现删除功能

```
class Solution {
public:
ListNode* removeNthFromEnd(ListNode* head, int n) {
    ListNode* prehead = new ListNode(0);
    prehead->next = head;
     ListNode* right = head;
     ListNode* left  = head;
     ListNode* prev  = prehead;
     ListNode* next  = head;
    for(int i = 0; i < n; i++){
        right = right->next;
    }
    while(right){
        prev = left;
        left = left->next;
        right = right->next;
    }
    prev->next = left->next;
    delete left;
    return prehead->next;
}
};
```

23 题，同时对多个链表进行排序，主要用 priority_queue 就好了

```
struct MyComp{
    bool operator()(const ListNode* left, const ListNode* right){
        return left->val > right->val;
    }
};
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<ListNode*, vector<ListNode*>, MyComp> Q;
        for(auto node : lists){
            if(node)
                Q.push(node);
        }
        ListNode prehead = ListNode(0);
        ListNode* now = &prehead;

        while(Q.size()!=0){
            now->next = Q.top();
            Q.pop();
            now = now->next;
            if(now->next){
                Q.push(now->next);
            }
        }
        return prehead.next;
    }
};
```

24 题，交换相邻两个指针，四个指针来操作就好

```
class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        ListNode prehead = ListNode(0);
        ListNode* prev = &prehead;
        ListNode* left;
        ListNode* right;
        ListNode* next;

        if(!head || !head->next)
            return head;

        left = head;
        right= head->next;
        next = right->next;

        while(left&&right){
            prev->next  = right;
            right->next = left;
            left->next  = next;
            prev = left;
            left = next;
            if(!left)
                break;
            right = left->next;
            if(!right)
                break;
            next = right->next;
        }
        return prehead.next;
    }
};
```

25 题，这道题是倒转任意个距离的 list，其实也是需要四个指针，然后按照 k 个完全倒转的子问题，依次进行倒转，子问题需要临时的三个指针

```
class Solution {
public:
    void reverseTotal(ListNode* prev, ListNode* left, ListNode*right, ListNode* next){
        ListNode* now = left->next;
        ListNode* nownext;
        ListNode* nowprev = left;
        left->next = next;
        while(now!=right){
            nownext = now->next;
            now->next = nowprev;
            nowprev = now;
            now = nownext;
        }
        now->next = nowprev;
        prev->next = now;
    }

    ListNode* reverseKGroup(ListNode* head, int k) {
        if(!head || !head->next || k==1)
            return head;

        ListNode prehead = ListNode(0);
        prehead.next = head;
        ListNode* prev = &prehead;
        ListNode* left = head;
        ListNode* right= head;
        ListNode* next = head->next;

        while(left&&right){
            right = left;
            for(int i = 0; i < k-1&&right; i++){
                right = right->next;
            }
            if(!right)
                break;
            next = right->next;
            reverseTotal(prev, left, right, next);
            prev = left;
            left = next;
        }
        return prehead.next;
    }
};
```

61 题，旋转整个链表的时候，也是需要三四个指针的，然后遍历两遍这样

```
class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if(!head || !head->next)
            return head;

        ListNode prehead=ListNode(0);
        prehead.next = head;

        ListNode* last = &prehead;
        ListNode* now  = head;
        ListNode* prev = &prehead;
        ListNode* next = now->next;
        int count = 0;
        while(now){
            last= last->next;
            now = now->next;
            count++;
        }
        k = k%count;

        int sc = 1;
        now = head;
        while(next&&sc!=count-k){
            prev = prev->next;
            now  = now->next;
            next = next->next;
            sc++;
        }
        last->next=prehead.next;
        prehead.next = now->next;
        now->next = nullptr;

        return prehead.next;
    }
};
```

86 题：是一个把小于某个数的所有数都放到前面来，

```
class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        ListNode prehead = ListNode(0);
        ListNode smprehead= ListNode(0);

        prehead.next    = head;
        ListNode* smnow = &smprehead;
        ListNode* prev  = &prehead;
        ListNode* now   = head;

        while(now){
            if(now->val < x){
                smnow->next = now;
                smnow = smnow->next;
                prev->next = now->next;
            }
            else{
                prev = prev->next;
            }
            now = now->next;
        }
        if(!smprehead.next){
            return prehead.next;
        }
        else{
            smnow->next = prehead.next;
            return smprehead.next;
        }
    }
};
```

**109 题，这道题还是很典型的**因为可以把链表弄成平衡二叉树结构，使用分治的方法，对单个节点进行不断更新和迭代，算法不难想，但是代码不是很好写

```
class Solution {
public:
    ListNode* now;

    TreeNode* dfs(int begin, int end){
        if(begin>end)
            return nullptr;

        int mid = (begin+end)/2;
        TreeNode* left = dfs(begin, mid-1);
        TreeNode* nownode = new TreeNode(now->val);
        nownode->left = left;

        now = now->next;

        TreeNode* right = dfs(mid+1, end);
        nownode->right = right;

        return nownode;
    }

    TreeNode* sortedListToBST(ListNode* head) {
        if(!head)
            return nullptr;

        int count = 0;
        now = head;
        while(now){
            now = now->next;
            count++;
        }
        now = head;
        return dfs(0, count-1);
    }
};
```

**127 题**

```
class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> dict(wordList.begin(), wordList.end()), head, tail, *phead, *ptail;
        if (dict.find(endWord) == dict.end()) {
            return 0;
        }
        head.insert(beginWord);
        tail.insert(endWord);
        int ladder = 2;
        while (!head.empty() && !tail.empty()) {
            if (head.size() < tail.size()) {
                phead = &head;
                ptail = &tail;
            } else {
                phead = &tail;
                ptail = &head;
            }
            unordered_set<string> temp;
            for (auto it = phead -> begin(); it != phead -> end(); it++) {
                string word = *it;
                for (int i = 0; i < word.size(); i++) {
                    char t = word[i];
                    for (int j = 0; j < 26; j++) {
                        word[i] = 'a' + j;
                        if (ptail -> find(word) != ptail -> end()) {
                            return ladder;
                        }
                        if (dict.find(word) != dict.end()) {
                            temp.insert(word);
                            dict.erase(word);
                        }
                    }
                    word[i] = t;
                }
            }
            ladder++;
            phead -> swap(temp);
        }
        return 0;
    }
};
```

133 题：无向图的深度拷贝问题，其实只是需要用一个队列加一个 unordered_map

```
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {}

    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
class Solution {
public:
    Node* cloneGraph(Node* node) {
        if(!node)
            return nullptr;

        unordered_map<Node*, Node*> mp;
        queue<Node*> Q;

        Node* root = new Node(node->val, vector<Node*>());
        mp[node] = root;
        for(Node* child : node->neighbors){
            Node* copychild = new Node(child->val, vector<Node*>());
            root->neighbors.push_back(copychild);
            mp[child] = copychild;
            Q.push(child);
        }
        while(Q.size()!=0){
            Node* now = Q.front();
            Q.pop();
            Node* copy = mp[now];

            for(Node* child : now->neighbors){
                if(mp.find(child)!=mp.end()){
                    copy->neighbors.push_back(mp[child]);
                }
                else{
                    Node* copychild = new Node(child->val, vector<Node*>());
                    copy->neighbors.push_back(copychild);
                    mp[child] = copychild;
                    Q.push(child);
                }
            }
        }
        return root;
    }
};
```

138 题，和上面那道题一样，也是链表的深度拷贝问题

```
class Node {
public:
    int val;
    Node* next;
    Node* random;
    Node() {}

    Node(int _val, Node* _next, Node* _random) {
        val = _val;
        next = _next;
        random = _random;
    }
};
class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(!head)
            return nullptr;

        unordered_map<Node*, Node*> mp;
        Node* root = new Node(head->val, nullptr, nullptr);
        Node* copynow = root;
        Node* now = head;
        mp[now] = copynow;

        while(now->next){
            copynow->next = new Node(now->next->val, nullptr, nullptr);
            mp[now->next] = copynow->next;
            now = now->next;
            copynow = copynow->next;
        }
        now = head;
        copynow = root;
        while(now){
            copynow->random = mp[now->random];
            copynow = copynow->next;
            now = now->next;
        }

        return root;
    }
};
```

143 题，题目属于那种如果用O(n)空间复杂度和O(n)时间复杂度就很简单，但是如果扣到O(1)的空间复杂度的话就有些麻烦了，首先要找到链表的中间节点，然后要对后面半段做翻转链表操作，然后再进行合并，是有些麻烦的

```
class Solution {
public:
    void reorderList(ListNode* head) {
            ListNode* next = nullptr;
            ListNode* prev = nullptr;
            ListNode* mid = head;
            ListNode* fast= head;
            ListNode* now = head;
            if(!head || !head->next)
                return ;

            while(fast&&fast->next){
                prev = mid;
                mid  = mid->next;
                fast = fast->next->next;
            }
            prev->next = nullptr;
            next = mid->next;
            prev = nullptr;

            while(mid){
                next = mid->next;
                mid->next = prev;
                prev = mid;
                mid = next;
            }
            mid = prev;

            while(mid&&now){
                next = now->next;
                now->next = mid;
                now = now->next;
                mid = mid->next;
                now->next = next;
                prev = now;
                now = now->next;

            }
        if(mid)
            prev->next = mid;
    }
 };
```

147题，也是比较经典的一个题目，使用插入排序的方法对链表进行排序，中间两个for循环，比较灵性

```
class Solution
{
public:
	ListNode* insertionSortList(ListNode* head) {
		if (!head || !head->next)
			return head;

        ListNode  prehead = ListNode(0);
        prehead.next = head;

        ListNode* now = head->next;
        ListNode* prevnow = head;
        ListNode* nextnow = now->next;

        ListNode* pos = head;
        ListNode* prevpos = &prehead;

        while (now)
        {
            nextnow = now->next;

            pos = prehead.next;
            prevpos = &prehead;
            while (pos && pos->val <= now->val && now->next != pos)
            {
                prevpos = prevpos->next;
                pos = pos->next;
            }
            if (now->next != pos)
            {
                prevpos->next = now;
                now->next = pos;
                prevnow->next = nextnow;
                now = nextnow;
            }
            else
            {
                prevnow = now;
                now = now->next;
            }

        }
        return prehead.next;
    }
};
```

148题，也是链表的排序问题，只不过是快速排序，然后复杂度是nlogn的，那么用归并排序是比较方便的

```
class Solution {
public:
    ListNode* sortList(ListNode* head) {
        if(!head || !head->next)
            return head;

        ListNode* fast = head;
        ListNode* slow = head;
        ListNode* prev;

        while(fast&&fast->next){
            prev = slow;
            slow = slow->next;
            fast = fast->next->next;
        }

        prev->next = nullptr;

        ListNode* p1 = sortList(head);
        ListNode* p2 = sortList(slow);
        ListNode prehead = ListNode(0);
        ListNode* now= &prehead;
        while(p1 && p2){
            if(p1->val < p2->val){
                now->next = p1;
                p1 = p1->next;
            }
            else{
                now->next = p2;
                p2 = p2->next;
            }
            now = now->next;
        }
        while(p1){
            now->next = p1;
            p1 = p1->next;
            now = now->next;
        }
        while(p2){
            now->next = p2;
            p2 = p2->next;
            now = now->next;
        }

        return prehead.next;
    }
};
```

207题/210题，典型的BFS，用degrees和unordered_map的BFS搜索

```
class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        unordered_map<int, vector<int>> graph;
        vector<int> degrees(numCourses, 0);
        queue<int> Q;
        vector<int> out;
        
        for(auto& iter : prerequisites){
            graph[iter[1]].push_back(iter[0]);
            degrees[iter[0]]++;
        }

        for(int i = 0; i < numCourses; i++){
            if(degrees[i]==0){
                Q.push(i);
                out.push_back(i);
            }
                
        }
        while(Q.size()!=0){
            int now = Q.front();
            Q.pop();
            if(graph.find(now)!=graph.end()){
                for(auto& iter: graph[now]){
                    degrees[iter]--;
                    if(degrees[iter]==0){
                        Q.push(iter);
                        out.push_back(iter);
                    }  
                }
            }
            else{
                continue;
            }
        }

        for(int i = 0; i < numCourses; i++){
            if(degrees[i]!=0)
                return vector<int>();
        }
        return out;
        
    }
};
```

430题，是一个拥有另外child的双线链表，有点像树的数据结构，把这个树弄平其实只需要一个stack，把后面的节点存到stack里面就好了

```
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
    
    Node() {}

    Node(int _val, Node* _prev, Node* _next, Node* _child) {
        val = _val;
        prev = _prev;
        next = _next;
        child = _child;
    }
};
class Solution {
public:
    Node* flatten(Node* head) {
        if(!head)
            return head;
        
        stack<Node*> stk;
        Node prehead = Node(0);
        prehead.next = head;

        Node* pre = &prehead;
        Node* now = head;

        while(now){
            while(now){
                if(now->child){
                    if(now->next)
                        stk.push(now->next);
                    pre = now;
                    now = now->child;
                    pre->child = nullptr;
                    now->prev = pre;
                    pre->next = now;
                }
                else{
                    pre = now;
                    now = now->next;
                }
            }
            if(stk.size()!=0){
                now = stk.top();
                pre->next = now;
                now->prev = pre;
                stk.pop();
                now = pre->next;
            }
        }

        return prehead.next;
    }
};
```

445题，主要是一开始在考虑O(1)空间复杂度的情况，浪费了比较多的时间，后来用一个stack就好了

```
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        if(!l1)
            return l2;
        if(!l2)
            return l1;
        
        int cnt1 = 0;
        int cnt2 = 0;
        stack<int> stk1;
        stack<int> stk2;

        ListNode* now1 = l1;
        ListNode* now2 = l2;

        while(now1){
            stk1.push(now1->val);
            cnt1++;
            now1 = now1->next;
        }
        while(now2){
            stk2.push(now2->val);
            cnt2++;
            now2 = now2->next;
        }

        int extra = 0;
        ListNode* prev = nullptr;
        ListNode* now;
        int nowval = 0;
        while(stk1.size() != 0 || stk2.size()!=0 || extra==1){
            nowval = 0;
            if(stk1.size()!=0){
                nowval += stk1.top();
                stk1.pop();
            }
            if(stk2.size()!=0){
                nowval += stk2.top();
                stk2.pop();
            }
            nowval += extra;
            extra = nowval / 10;
            nowval = nowval%10;
            now = new ListNode(nowval);
            now->next = prev;
            prev = now;
        }
        return now;
    }
};
```

457题，**是比较经典的一道题**，因为他是让某一个数字前后移动，直到找到一个环为止。这种类型的题目不太多见，不过思路还是很明确的

```
class Solution {
public:
    bool circularArrayLoop(vector<int>& nums) {
        int n = nums.size();
        vector<bool> visited(n);
        for (int i = 0; i < n; ++i) {
            if (visited[i]) continue;
            visited[i] = true;
            unordered_map<int, int> m;
            int cur = i;
            while (true) {
                int next = ((cur + nums[cur]) % n + n) % n;
                if (next == cur || nums[next] * nums[cur] < 0) break;
                if (m.count(next)) return true;
                m[cur] = next;
                cur = next;
                visited[next] = true;
            }
        }
        return false;
    }
};
```

