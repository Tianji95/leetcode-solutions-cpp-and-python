### 图和链表

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

第2题：这道题其实思路不难，主要是代码写的比较干净是稍微麻烦些的事情，这里面主要是把判断放到while里面了，看起来就很清楚很干净

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

第19题，主要是要添加一个prehead，然后三个指针实现删除功能

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

23题，同时对多个链表进行排序，主要用priority_queue就好了

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

24题，交换相邻两个指针，四个指针来操作就好



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

25题，这道题是倒转任意个距离的list，其实也是需要四个指针，然后按照k个完全倒转的子问题，依次进行倒转，子问题需要临时的三个指针

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

61题，旋转整个链表的时候，也是需要三四个指针的，然后遍历两遍这样

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

86题：是一个把小于某个数的所有数都放到前面来，

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

**109题，这道题还是很典型的**因为可以把链表弄成平衡二叉树结构，使用分治的方法，对单个节点进行不断更新和迭代，算法不难想，但是代码不是很好写

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

