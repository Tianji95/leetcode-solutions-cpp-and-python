### 广度优先搜索

从根节点开始，然后横向进行搜索，一般使用queue来实现或者用链表来实现，例如树的层次遍历



##### leetcode题目(11题)

126

130

133

200

269

310

378

407

529

637

675



126题：主要思路是创建一个图，dfs和bfs创建一个图是非常重要的，然后遍历所有的字母，修改当前字母，查找是否有这个单词，创建好图以后，再来遍历图，放到结果里面

```
class Solution
{
public:
	vector<vector<string>> out;
	unordered_map<string, list<string>> graph;

    void dfs(vector<string>& now, string start, string end) {
        if (end == start)
        {
            now.push_back(end);
            out.push_back(now);
            now.pop_back();
            return;
        }
        now.push_back(start);
        if (graph.find(start) != graph.end())
        {
            for (auto s : graph[start])
            {
                dfs(now, s, end);
            }
        }
        now.pop_back();
    }

    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        int len = wordList.size();
        queue<string> Q;
        unordered_map<string, int> distmp;
        string now;
        string newword;
        char old;
        int distance = 0;
        int minstep = INT_MAX;
        
        for (auto word : wordList)
        {
            distmp[word] = INT_MAX;
        }
        distmp[beginWord] = 0;
        Q.push(beginWord);

        while (Q.size())
        {
            now = Q.front();
            Q.pop();
            distance = distmp[now] + 1;
            newword = now;
            if (minstep < distance)
                break;

            for (int i = 0; i < newword.size(); i++)
            {
                newword = now;
                for (char ch = 'a'; ch <= 'z'; ch++)
                {
                    newword[i] = ch;
                    if (distmp.find(newword) != distmp.end())
                    {
                        if (distance > distmp[newword])
                            continue;
                        else if (distance < distmp[newword])
                        {
                            distmp[newword] = distance;
                            Q.push(newword);
                        }
                        if (graph.find(now) != graph.end())
                            graph[now].push_back(newword);
                        else
                        {
                            graph[now] = list<string>();
                            graph[now].push_back(newword);
                        }
                        if (newword == endWord)
                            minstep = distance;
                    }
                }
            }
        }
        vector<string> nowlist;
        dfs(nowlist, beginWord, endWord);
        return out;
    }

};


```

130题，典型的修改矩阵的题目，不过这个代码写的有些冗余了：

```
class Solution {
public:
    int height;
    int width ;
    
    void setdfs(vector<vector<char>>& board, int h, int w){
        board[h][w] = '$';
        if(h-1>=0&&board[h-1][w]=='O'){
            setdfs(board, h-1, w);
        }
        if(h+1<height && board[h+1][w]=='O'){
            setdfs(board, h+1, w);
        }
        if(w-1>=0 && board[h][w-1]=='O'){
            setdfs(board, h, w-1);
        }
        if(w+1<width && board[h][w+1]=='O'){
            setdfs(board, h, w+1);
        }
    }

    bool dfs(vector<vector<char>>& board, int h, int w){
        board[h][w] = '$';
        if(h==0 || h==height-1 || w==0 || w==width-1){
            return false;
        }
        if(h-1>=0&&board[h-1][w]=='O'){
            if(!dfs(board, h-1, w))
                return false;
        }
        if(h+1<height && board[h+1][w]=='O'){
            if(!dfs(board, h+1, w))
                return false;
        }
        if(w-1>=0 && board[h][w-1]=='O'){
            if(!dfs(board, h, w-1))
                return false;
        }
        if(w+1<width && board[h][w+1]=='O'){
            if(!dfs(board, h, w+1))
                return false;
        }
        board[h][w] = '#';
        return true;
    }

    void solve(vector<vector<char>>& board) {
        height = board.size();
        if(height==0) return ;

        width  = board[0].size();
        if(width == 0) return ;
        
        for(int h = 0; h < height; h++){
            if(board[h][0]=='O'){
                setdfs(board, h, 0);
            }
            if(board[h][width-1]=='O'){
                setdfs(board, h, width-1);
            }
        }
        for(int w = 0; w < width; w++){
            if(board[0][w]=='O'){
                setdfs(board, 0, w);
            }
            if(board[height-1][w]=='O'){
                setdfs(board, height-1, w);
            }
        }

        for(int h = 0; h < height; h++){
            for(int w = 0; w < width; w++){
                if(board[h][w]=='O'){
                    dfs(board, h, w);
                }
            }
        }

        for(int h = 0; h < height; h++){
            for(int w = 0; w < width; w++){
                if(board[h][w]=='#'){
                    board[h][w]='X';
                }
                if(board[h][w]=='$'){
                    board[h][w]='O';
                }
            }
        }
    }

};
```

378题：找到一个排过序的数组中第k个小的数，二分查找法

```
class Solution {
public:
    int height;
    int width;
    int count(vector<vector<int>>& matrix, int target){
        int out = 0;
        int w = width-1;
        int h = 0;
        while(h<height && w >=0){
            if(matrix[h][w] <= target){
                out+=w+1;
                h++;
            }
            else{
                w--;
            }
        }
        return out;
    }
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        height = matrix.size();
        width  = matrix[0].size();
        
        
        int right = matrix[height-1][width-1];
        int left  = matrix[0][0];
        int mid;
        while(left < right){
            mid = (right+left)/2;
            if(count(matrix, mid)<k){
                left = mid+1;
            }
            else{
                right = mid;
            }
        }
        return left;
    }
};
```

407题：一个二维的，收集雨水的问题，问题的关键在于，要先从四个边开始push到优先队列里面，然后每次都找到最小的那个边，并且计算往里走能收集多少雨水

```
class MY{
public:
    int val;
    int h;
    int w;
    MY(int v, int h, int w):val(v), h(h), w(w){}
};

class mycomp{
public:
    bool operator() (const MY& left, const MY&right){
        return left.val >= right.val;
    }
};

class Solution {
public:
    int height;
    int width;
    int trapRainWater(vector<vector<int>>& heightMap) {
        height = heightMap.size();
        if(height==0)
            return 0;
        width  = heightMap[0].size();
        if(width==0)
            return 0;
        priority_queue<MY, vector<MY>, mycomp> Q;
        vector<vector<bool>> isvisit(height, vector<bool>(width, false));
        MY now(0, 0, 0);
        int out = 0;
        
        for(int w = 0; w < width; w++){
            isvisit[0][w] = true;
            isvisit[height-1][w] = true;
            Q.push(MY(heightMap[0][w], 0, w));
            Q.push(MY(heightMap[height-1][w], height-1, w));
        }
        for(int h = 0; h < height; h++){
            isvisit[h][0] = true;
            isvisit[h][width-1] = true;
            Q.push(MY(heightMap[h][0], h, 0));
            Q.push(MY(heightMap[h][width-1], h, width-1));
        }

        vector<vector<int>> dirs = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        while(Q.size()!=0){
            now = Q.top();
            Q.pop();
            for (auto& dir : dirs) {
                int ht = now.h+dir[0];
                int wd = now.w+dir[1];
                if(ht>=0 && ht<height && wd>=0 && wd<width && !isvisit[ht][wd]){
                    isvisit[ht][wd] = true;
                    out += max(0, now.val - heightMap[ht][wd]);
                    Q.push(MY(max(heightMap[ht][wd], now.val), ht, wd));
                }

            }
        }
        return out;
    }

};
```

675题：一个需要自定义类，同时需要向队列里面push元素的题目，不过这里面需要用到优先队列，从而查找到最小那棵树的位置，然后每次迭代都需要计算最小的步数，这是一类比较典型的题目

```
class TreeClass
{
public:
	int h;
	int w;
	int value;
	TreeClass(int h, int w, int value) :h(h), w(w), value(value) {}
};

class mycomp
{
public:
	bool operator() (const TreeClass& left, const TreeClass& right) {
		return left.value > right.value;
	}
};

class Solution
{
public:
	int width;
	int height;

	vector<vector<int>> dirs = { {-1, 0}, {1, 0}, {0, -1}, {0, 1} };

	int CalculStep(vector<vector<int>>& forest, TreeClass& start, TreeClass& end) {
		if (start.h == end.h&&start.w == end.w)
			return 0;
		queue<TreeClass> Q;
		TreeClass now(0, 0, 0);
		Q.push(move(TreeClass(start.h, start.w, 0)));
		vector<vector<int>> isvisit(height, vector<int>(width, 0));
		isvisit[start.h][start.w] = 1;
		while (Q.size())
		{
			now = Q.front();
			Q.pop();
			for (auto& dir : dirs)
			{
				int nowh = now.h + dir[0];
				int noww = now.w + dir[1];
				if (nowh == end.h && noww == end.w) return now.value + 1;
				if (nowh >= 0 && nowh < height && noww < width && noww >= 0 && forest[nowh][noww] != 0 && !isvisit[nowh][noww])
				{
					Q.push(move(TreeClass(nowh, noww, now.value + 1)));
					isvisit[nowh][noww] = 1;
				}
			}
		}

		return -1;
	}

	int cutOffTree(vector<vector<int>>& forest) {
		height = forest.size();
		if (height == 0)
			return 0;
		width = forest[0].size();
		if (width == 0)
			return 0;
		priority_queue<TreeClass, vector<TreeClass>, mycomp> Q;

		for (int h = 0; h < height; h++)
		{
			for (int w = 0; w < width; w++)
			{
				if (forest[h][w] > 1)
				{

					Q.push(move(TreeClass(h, w, forest[h][w])));
				}
			}
		}

		int out = 0;
		int step = 0;
		TreeClass start(0, 0, forest[0][0]);
		TreeClass target(0, 0, forest[0][0]);

		while (Q.size())
		{
			target = move(Q.top());
			Q.pop();
			step = CalculStep(forest, start, target);
			if (step < 0)
				return -1;
			out += step;
			start = move(target);
		}

		return out;
	}
};
```

