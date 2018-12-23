class LRUCache {
public:
    //两个双链表+一个哈希表
    //使用双链表便于调整节点位置
    //第一个双链表存储未被使用的位置
    //第二个双链表存储已被使用的位置，且按最近使用时间从右到左排好序
    //哈希表存储key对应的链表中的节点地址
    //关键是put操作 缓存满后删除上次使用时间最老的key，即第二个链表最左侧节点
    struct Node
    {
        int val, key;
        Node *left, *right;
        Node() : key(0), val(0), left(NULL), right(NULL) {}
    };
    //定义两个链表的头尾指针
    Node *first_s,*first_e;
    Node *second_s,*second_e;
    //hash表
    int n;
    unordered_map<int,Node*> hash;
    void insert_node(Node* h,Node* p)
    {
        //头插法
         p->right = h->right, h->right = p;
        p->left = h, p->right->left = p;
    }
    void delete_node(Node *p)
    {
        p->left->right=p->right;
        p->right->left=p->left;
    }
    LRUCache(int capacity) {
        //初始化
        //第一个链表插入n个节点。n为缓存大小
        //第二个双链表和哈希表都为空
        n=capacity;
        first_s=new Node(),first_e=new Node();
        second_s=new Node(),second_e=new Node();
        first_s->right=first_e, first_e->left=first_s;
        second_s->right=second_e, second_e->left=second_s;
        for(int i=0;i<n;i++)
        {
            Node* p=new Node();
            //插入节点
            insert_node(first_s,p);
        }
        
    }
    
    int get(int key) {
        //先用hash表判断key是否存在
        //若存在，则返回对应的value,同时将key对应的节点放入第二个链表的右侧；
        //若不存在，则返回-1；
        if(hash[key])
        {
            Node *p=hash[key];
            //第一个链表删除p
            delete_node(p);
            //第二个链表插入最左侧
            insert_node(second_e->left,p);
            //insert_node(second_s,p);

            return p->val;
        }
        return -1;
    }
    
    void put(int key, int value) {
        //若key存在，则修改相应的value,同时将key对应的节点放入到第二个双链表的最右侧
        //若不存在
        //若缓存已满，则删除第二个双链表最左侧的节点（上次使用时间最老的节点），同时更新三个数据结构(相当于访问了一次)；
        //插入（key,value）:从第一个双链表中随便找一个节点，修改节点权值，然后将节点从第一个双链表删除，插入第二个链表最右侧，同时更新hash表
        if(hash[key])
        {
            Node* p=hash[key];
            delete_node(p);
            insert_node(second_e->left,p);
            p->val=value;
            return;
        }
        //缓存已满 n从capacity降为0！！！！！！
        if(!n)
        {
            n++;
            Node* p=second_s->right;
            hash[p->key]=0;
            delete_node(p);
            insert_node(first_s,p);
        }
        n--;
        Node* p=first_s->right;
        p->key=key,p->val=value,hash[key]=p;
        delete_node(p);
        insert_node(second_e->left,p);
        
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache obj = new LRUCache(capacity);
 * int param_1 = obj.get(key);
 * obj.put(key,value);
 */