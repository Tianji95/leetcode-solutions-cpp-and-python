### **KMP算法**

<https://blog.csdn.net/v_july_v/article/details/7041827>

28题，查找一个字符串是否是另外一个字符串的子字符串，用KMP算法会非常的快

另外，这里面遇到一个size的坑，如果一个负数和一个string.size()作比较的话，可能会出现问题，因为string.size()返回的数据类型是size_t，是无符号整数，所以比较起来会出现问题，

```
class Solution {
public:
    void makeNext(vector<int>& next, string& needle){
        int len = needle.size();
        int left = -1;
        int right = 0;
        next[0] = -1;
        while(right<len-1){
            if(left<0 || needle[left]==needle[right]){
                left++;
                right++;
                next[right] = left;
            }
            else{
                left = next[left];
            }
        }
    }

    int strStr(string haystack, string needle) {
        if(needle.size()==0)
            return 0;

        int lenh = haystack.size();
        int lenn = needle.size();
        vector<int> next(lenn, 0);
        makeNext(next, needle);

        int h = 0;
        int n = 0;

        while(h < lenh && n < lenn){
            if(n<0||haystack[h]==needle[n]){
                h++;
                n++;
            }
            else{
                n = next[n];
            }
        }
        if(n!=lenn){
            return -1;
        }
        return h-n;
    }
};
```

### Dijkstra算法

```CPP
/*Dijkstra算法解决的是单源最短路径问题，即给定图G(V,E)和起点s(起点又称为源点),
求从起点s到达其它顶点的最短距离，并将最短距离存储在矩阵d中*/
void Dijkstra(int n, int s, vector<vector<int>> G, vector<bool>& vis, vector<int>& d)
{
       /*
       param
       n：           顶点个数
       s：           源点
       G：           图的邻接矩阵
       vis：         标记顶点是否已被访问
       d：           存储源点s到达其它顶点的最短距离
       */
       fill(d.begin(), d.end(), INF);                         //初始化最短距离矩阵，全部为INF
       d[s] = 0;                                              //起点s到达自身的距离为0
       for (int i = 0; i < n; ++i)
       {
              int u = -1;                                     //找到d[u]最小的u
              int MIN = INF;                                  //记录最小的d[u]
              for (int j = 0; j < n; ++j)                     //开始寻找最小的d[u]
              {
                     if (vis[j] == false && d[j] < MIN)
                     {
                           u = j;
                           MIN = d[j];
                     }
              }
              //找不到小于INF的d[u]，说明剩下的顶点和起点s不连通
              if (u == -1)
                     return;
              vis[u] = true;                                  //标记u已被访问
              for (int v = 0; v < n; ++v)
              {
                     //遍历所有顶点，如果v未被访问&&u能够到达v&&以u为中介点可以使d[v]更优
                     if (vis[v] == false && d[u] + G[u][v] < d[v])
                           d[v] = d[u] + G[u][v];             //更新d[v]
              }
       }
}
```

### Bellman-Ford算法

```cpp
// 松弛计算
void relax(int u, int v, int weight)
{
    if(dist[v] > dist[u] + weight)
        dist[v] = dist[u] + weight;
}

bool Bellman_Ford()
{
    for(int i=1; i<=nodenum-1; ++i)
        for(int j=1; j<=edgenum; ++j)
            relax(edge[j].u, edge[j].v, edge[j].weight);
    bool flag = 1;
    // 判断是否有负环路
    for(int i=1; i<=edgenum; ++i)
        if(dist[edge[i].v] > dist[edge[i].u] + edge[i].weight)
        {
            flag = 0;
            break;
        }
    return flag;
}
```

### 二叉堆

```
typedef struct _BinomialNode{
    Type   key;                     // 关键字(键值)
    int degree;                     // 度数
    struct _BinomialNode *child;    // 左孩子
    struct _BinomialNode *parent;   // 父节点
    struct _BinomialNode *next;     // 兄弟
}BinomialNode, *BinomialHeap;


/*
 * 将h1, h2中的根表合并成一个按度数递增的链表，返回合并后的根节点
 */
static BinomialNode* binomial_merge(BinomialHeap h1, BinomialHeap h2) 
{
    BinomialNode* head = NULL; //heap为指向新堆根结点
    BinomialNode** pos = &head;

    while (h1 && h2)
    {
        if (h1->degree < h2->degree)
        {
            *pos = h1;
            h1 = h1->next;
        } 
        else 
        {
            *pos = h2;
            h2 = h2->next;
        }
        pos = &(*pos)->next;
    }
    if (h1)
        *pos = h1;
    else
        *pos = h2;

    return head;
}
```



### 斐波那契堆

### 