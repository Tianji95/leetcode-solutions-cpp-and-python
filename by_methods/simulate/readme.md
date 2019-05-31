### 模拟

模拟这一类型的题目其实指的是模拟一些游戏，然后模拟题目中要求的样子



##### leetcode题目

146

202

289

371

412



146题，作为一个模拟LRU类型的题目，很具有代表性，数据结构使用一个used的链表，里面存的是所有的key，这里面的key可以对map做erase操作，map里面存着一个list的iterator，这个迭代器也很重要，因为可以直接把list里面的used删除掉，这样一个unordered_map和list的数据结构就能够实现O(1)的复杂度了，代码如下：

```
class LRUCache {
public:
    LRUCache(int capacity) : _capacity(capacity) {}
    
    int get(int key) {
        if(cache.find(key)!=cache.end()){
            update(key);
            return cache[key].first;
        }
        else{
            return -1;
        }

    }

    void put(int key, int value) {
        if(cache.find(key)!=cache.end()){
            update(key);
        }
        else{
            if(cache.size()==_capacity){
                cache.erase(used.back());
                used.pop_back();
            }
            used.push_front(key);
        }
        cache[key] = {value, used.begin()};
    }
    
private:

    void update(int key){
        auto iter = cache[key].second;
        used.erase(iter);
        used.push_front(key);
        cache[key].second = used.begin();
    }
    
    unordered_map<int, pair<int, list<int>::iterator>> cache;
    list<int> used;
    int _capacity;
};
```

289题，模拟game of life游戏，指定矩阵的规则，然后按照规则来写，游戏经常考这种类型的题目

```
class Solution {
public:
    int height;
    int width;
    int checkcount(vector<vector<int>>& board, int h, int w){
        int count = 0;
        if(h-1 >= 0 && w-1 >=0         && (board[h-1][w-1]==1||board[h-1][w-1]==2))
            count++;
        if(h-1 >= 0                    && (board[h-1][w]==1||board[h-1][w]==2))
            count++;
        if(h-1 >= 0 && w+1 < width     && (board[h-1][w+1]==1||board[h-1][w+1]==2))
            count++;
        
        if(w-1 >=0                     && (board[h][w-1]==1||board[h][w-1]==2))
            count++;
        if(w+1 < width                 && (board[h][w+1]==1||board[h][w+1]==2))
            count++;

        if(h+1 < height && w-1 >=0     && (board[h+1][w-1]==1||board[h+1][w-1]==2))
            count++;
        if(h+1 < height                && (board[h+1][w]==1||board[h+1][w]==2))
            count++;
        if(h+1 < height && w+1 < width && (board[h+1][w+1]==1||board[h+1][w+1]==2))
            count++;
        return count;
    }
    void gameOfLife(vector<vector<int>>& board) {
        height = board.size();
        if(height==0)
            return ;
        width  = board[0].size();
        if(width==0)
            return ;

        int count = 0;
        for(int h = 0; h < height; h++){
            for(int w = 0; w < width; w++){
                count = checkcount(board, h, w);
                if(board[h][w]==0){
                    if(count == 3)
                        board[h][w] = 3;
                }
                else{
                    if(count < 2 || count > 3){
                        board[h][w] = 2;
                    }

                }
            }
        }

        for(int h = 0; h < height; h++){
            for(int w = 0; w < width; w++){
                if(board[h][w]==3){
                    board[h][w] = 1;
                }
                else if(board[h][w]==2){
                    board[h][w] = 0;
                }
            }
        }
    }
};
```

371题：其实是一个位运算的题目，首先，两个数相加的时候，异或运算^会实现进位以后的运算，与运算&会计算出进位，，但是我们应该把进位左移一位，才能保证当前是进位而不只是与了一下

```
class Solution {
public:
    int getSum(int a, int b) {     
        return b==0? a:getSum(a^b, (a&b& 0xffffffff)<<1);
    }
};
```

