### 深度优先搜索

递归访问搜索某一个值或者得到某一个值，先搜索深度，递归深度越来越深

中间如果能够剪枝或者调换搜索顺序的话，可以让算法非常快的结束

##### leetcode 题目（23 题）

37

51

105

106

110

199

200

210

282

312

332

337

399

403

417

425

464

465

472

473

488

489

491

546

37 题：解数独的题目，一个 DFS 就可以搞定，其中比较麻烦的一点就是要修改行，列，块的时候，在改回原样时是反过来的

51 题：n 皇后问题，一个 dfs 照样可以搞定，不过每行每列的时候，可以通过位运算来把每行每列都存下来，存到一个 int 数里面，如下方法：

```
class Solution
{
    int n;
    string getNq(int p)
    {
        string s(n, '.');
        s[p] = 'Q';
        return s;
    }
    void nQueens(int p, int l, int m, int r, vector<vector<string>> &res)
    {
        static vector<string> ans;
        if (p >= n)
        {
            res.push_back(ans);
            return ;
        }
        int mask = l | m | r;
        for (int i = 0, b = 1; i < n; ++ i, b <<= 1)
            if (!(mask & b))
            {
                ans.push_back(getNq(i));
                nQueens(p + 1, (l | b) >> 1, m | b, (r | b) << 1, res);
                ans.pop_back();
            }
    }
public:
    vector<vector<string> > solveNQueens(int n)
    {
        this->n = n;
        vector<vector<string>> res;
        nQueens(0, 0, 0, 0, res);
        return res;
    }
};
```

105 题：通过前序和中序来生成树：查找前序的值在中序数组中的位置，位置以前的都是左子树，位置异或的都是右子树：

```
class Solution {
public:
    unordered_map<int, int> mp;
    int len;
    TreeNode* build(vector<int>& preorder, vector<int>& inorder, int ps, int is, int ie){
        if(ps>=len||is>ie)
            return nullptr;
        TreeNode* node = new TreeNode(preorder[ps]);
        int idx = mp[preorder[ps]];

        node->left = build(preorder, inorder, ps+1, is, idx-1);
        node->right = build(preorder, inorder, ps+idx-is+1, idx+1, ie);

        return node;

    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        len = preorder.size();
        if(len == 0)
            return nullptr;
        for(int i = 0; i < len; i++){
            mp[inorder[i]] = i;
        }
        return build(preorder, inorder, 0, 0, len-1);
    }
};
```

106 题：通过中序和后序来生成树，从后往前查找后序在中序中的位置，前面的都是左子树，右边的都是右子树

199 题：从右往左看一个树，输出所有看到的第一个数：遍历的时候先遍历右子树，有的话就直接插入，没有的话就插入左边的，判断输出数组的大小和层级就行了

```
class Solution {
public:
	vector<int> out;
    void dfs(TreeNode* node, int depth){
        if(!node)
            return ;
        if(out.size()==depth){
            out.push_back(node->val);
        }
        dfs(node->right, depth+1);
        dfs(node->left, depth+1);
    }

    vector<int> rightSideView(TreeNode* root) {
        dfs(root, 0);
        return out;
    }
};
```

200 题：算一个矩阵里面有多少个岛屿，直接拿#号替代掉对应位置的值就好了

210 题：先构图，构完图以后再进行 dfs 或者 bfs：

```
class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> degree(numCourses, 0);
        vector<int> out;
        if(numCourses==1){
            out.push_back(0);
            return out;
        }
        unordered_map<int, vector<int>> mp;
        for(auto iter : prerequisites){
            degree[iter[0]]++;
            mp[iter[1]].push_back(iter[0]);
        }

        for (int i = 0; i < numCourses; i++) {
            int j = 0;
            for (; j < numCourses; j++) {
                if (!degree[j]) {
                    out.push_back(j);
                    break;
                }
            }
            if (j == numCourses) {
                return {};
            }
            degree[j]--;
            for (int v : mp[j]) {
                degree[v]--;
            }
        }
        return out;
    }

};
```

282 题：一个类似于堆栈计算器的题目，dfs 来做，不过要注意乘号和+-号的优先级不一样，所以这里的做法是：把上一次操作的数字和符号记录下来，如果这次遇到乘号，就回退上次操作，然后做乘法，保留上次的符号到下一次

```
class Solution {
public:
    vector<string> out;
    void dfs(int idx, string num, int target, string curstr, long value, long prev, char op){
        if(idx==num.size() && value == target){
            out.push_back(curstr);
            return ;
        }
        for(int i = idx+1; i <= num.size(); i++){
            string s = num.substr(idx, i-idx);
            long now = stol(s);
            if (to_string(now).size() != s.size()) continue;
            dfs(i, num, target, curstr+"-"+s, value-now, now, '-');
            dfs(i, num, target, curstr+"+"+s, value+now, now, '+');
            if(op=='+'){
                dfs(i, num, target, curstr+"*"+s, value-prev+(prev*now), prev*now, op);
            }
            else if(op=='-'){
                dfs(i, num, target, curstr+"*"+s, value+prev-(prev*now), prev*now, op);
            }
            else{
                dfs(i, num, target, curstr+"*"+s, prev*now, prev*now, op);
            }
        }

    }

    vector<string> addOperators(string num, int target) {

        for(int i = 0; i < num.size(); i++){
            string s = num.substr(0, i+1);
            long now = stol(s);
            if (to_string(now).size() != s.size()) continue;
            dfs(i+1, num, target, s, now, now, '#');
        }
        return out;
    }

};
```

312 题：打气球问题，每打一次气球，都会把当前气球分数和两边的气球分数乘起来，求最大的分数，其实这是一道 dp 的问题，dp 的公式是表示 left 到 right 中间这一段的最大值，其中要用 for 循环寻找每一个 left 到 right 中间的值，这样才能取到最大值

```
class Solution {
public:
    int out;
    int maxCoins(vector<int>& inums) {
        out = 0;
        vector<int> nums(inums.size()+2, 1);

        for(int i = 0; i < inums.size(); i++){
            nums[i+1] = inums[i];
        }
        int len = nums.size();
        vector<vector<int>> dp(len, vector<int>(len, 0));

        for(int i = 2; i < nums.size(); i++){
            for(int left = 0; left < len - i; left++){
                int right = left+i;
                for(int j = left+1; j < right; j++)
                    dp[left][right] = max(dp[left][right], nums[left]*nums[j]*nums[right]+dp[left][j]+dp[j][right]);
            }
        }
        return dp[0][len-1];
    }

};
```

332 题

```
bool mycomp(const std::string& first, const std::string& second)
{
	unsigned int i = 0;
	while ((i < first.length()) && (i < second.length()))
	{
		if (first[i] < second[i]) return true;
		else if (first[i]> second[i]) return false;
		++i;
	}
	return (first.length() < second.length());
}

class Solution
{
public:
    vector<string> out;
	unordered_map<string, list<string>> mp;

    void dfs(string& now){
        while(true){
            if(mp.find(now)==mp.end() || mp[now].size()==0){
                break;
            }
            string next = mp[now].front();
            mp[now].pop_front();
            dfs(next);
        }
        out.push_back(now);
    }

    vector<string> findItinerary(vector<vector<string>> tickets) {

        string now = "JFK";

        for (auto& iter : tickets)
        {
            mp[iter[0]].push_back(move(iter[1]));
        }
        for (auto& iter : mp)
        {
            iter.second.sort(mycomp);
        }
        dfs(now);
        reverse(out.begin(), out.end());
        return out;
    }

};
```

337 题:

```
class Solution {
public:
    int dfs(TreeNode* node, int& l, int& r){
        int ll = 0;
        int lr = 0;
        int rl = 0;
        int rr = 0;
        if(node->left){
            l = dfs(node->left, ll, lr);
        }
        if(node->right){
            r = dfs(node->right, rl, rr);
        }
        return max(node->val+ll+lr+rl+rr, l+r);
    }
    int rob(TreeNode* root) {
        if(!root)
            return 0;
        int r = 0;
        int l = 0;
        return dfs(root, l, r);
    }
};
```

399 题：给出一组序列的比例关系，让你去递推其他序列的比例关系，先做图，然后递归进行递推

```
class Solution {
public:

    unordered_map<string, unordered_map<string, double>> mp;
    double dfs(string in, string out, double now, unordered_set<string>& isvisit){
        if(mp.find(in)!=mp.end()){

            auto findout = mp[in].find(out);
            if(findout!=mp[in].end()){
                return now*mp[in][out];
            }
            if(in == out)
                return 1.0;
            isvisit.insert(in);
            for(auto next : mp[in]){
                if(isvisit.find(next.first)==isvisit.end()){
                    double tmpout = dfs(next.first, out, now*next.second, isvisit);
                    if(tmpout!=-1)
                        return tmpout;
                }
            }
        }
        return -1;
    }

    vector<double> calcEquation(vector<vector<string>> equations, vector<double>& values, vector<vector<string>> queries) {
        vector<double> out;
        for(int i = 0; i < equations.size(); i++){
            mp[equations[i][0]][equations[i][1]] = values[i];
            mp[equations[i][1]][equations[i][0]] = 1.0/values[i];
        }

        double now = 0.0;
        for(int i = 0; i < queries.size(); i++){
            unordered_set<string> isvisit;
            now = dfs(queries[i][0], queries[i][1], 1, isvisit);
            out.push_back(now);
        }

        return out;
    }
};
```

403 题： 青蛙跳石头，排过序的 DFS，剪枝操作对于 dfs 是非常重要的，以及对于这些排过序的数组，从前往后和从后往前遍历的效果是不一样的

417 题：大西洋和太平洋, 其实思路不难，主要是通过位运算来对每一个单元来进行标记，标记是否流到大西洋或者太平洋，位运算在这里非常重要，存到一个 cache（或者 dp）里面

```C++
class Solution {
public:
    void dfs(vector<vector<int>>& matrix, vector<vector<int>>& dp, int h, int w, int label){
        dp[h][w] |= label;
        if(h+1<height&&(dp[h+1][w]&label)!=label&&matrix[h+1][w]>=matrix[h][w]){
            dfs(matrix, dp, h+1, w, label);
        }
        if(h-1>=0&&(dp[h-1][w]&label)!=label&&matrix[h-1][w]>=matrix[h][w]){
            dfs(matrix, dp, h-1, w, label);
        }
        if(w-1>=0&&(dp[h][w-1]&label)!=label&&matrix[h][w-1]>=matrix[h][w]){
            dfs(matrix, dp, h, w-1, label);
        }
        if(w+1<width&&(dp[h][w+1]&label)!=label&&matrix[h][w+1]>=matrix[h][w]){
            dfs(matrix, dp, h, w+1, label);
        }
    }
    int height;
    int width;
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& matrix) {
        vector<vector<int>> out;

        height = matrix.size();
        if(height == 0)
            return out;
        width  = matrix[0].size();
        if(width == 0)
            return out;

        vector<vector<int>> dp(height, vector<int>(width, 0));

        for(int h = 0; h < height; h++){
            dfs(matrix, dp, h, 0, 1);
            dfs(matrix, dp, h, width-1, 2);
        }

        for(int w = 0; w < width; w++){
            dfs(matrix, dp, 0, w, 1);
            dfs(matrix, dp, height-1, w, 2);
        }

        for(int h = 0; h < height; h++){
            for(int w = 0; w < width; w++){
                if(dp[h][w]==3){
                    vector<int> tmp;
                    tmp.push_back(h);
                    tmp.push_back(w);
                    out.push_back(move(tmp));
                }

            }
        }
        return out;
    }
};
```

464题：两个人相互报数，最先加到一个数的人先赢，这里也是用的dfs，不过这里面

```
class Solution {
public:
    unordered_map<int, bool> cache;
    bool dfs(vector<int>& visit, int maxChoosableInteger, int last){
        if(last<=0)
            return false;
            
        int choosen = 0;
        for(int i = 0; i < visit.size(); i++){
            if(visit[i]==1)
                choosen |= (1<<i);
        }
        if(cache.find(choosen)!=cache.end()){
            return cache[choosen];
        }

        for(int i = 1; i <= maxChoosableInteger; i++){
            if(visit[i-1])
                continue;
            visit[i-1] = 1;
            if(!dfs(visit, maxChoosableInteger, last-i)){
                visit[i-1] = 0;
                cache[choosen] = true;
                return true;
            }
            visit[i-1] = 0;
        }
        cache[choosen] = false;
        return false;

    }

    bool canIWin(int maxChoosableInteger, int desiredTotal) {
        vector<int> visit(maxChoosableInteger, 0);

        if (desiredTotal <= maxChoosableInteger) 
            return true;
        if (((1 + maxChoosableInteger) / 2 * maxChoosableInteger) < desiredTotal)
            return false;

        return dfs(visit, maxChoosableInteger, desiredTotal);
    }
};
```



472题：查找子串的问题

```
bool mycomp(const string& l, const string& r){
    return l.size() < r.size();
}

class Solution {
public:
    bool dfs(string& word, unordered_set<string>& wordset){
        if(word.size()==0)
            return false;
        vector<bool> dpArray(word.size()+1, false);
        dpArray[0] = true;
        for(int i = 1; i <= word.size(); i++){
            for(int j = i-1; j >= 0; j--){
                string subS = word.substr(j, i-j);
                if(dpArray[j] && wordset.find(subS)!=wordset.end()){
                    dpArray[i] = true;
                    break;
                }
            }
        }
        return dpArray[word.size()];
    }
    
    vector<string> findAllConcatenatedWordsInADict(vector<string>& words) {
        sort(words.begin(), words.end(), mycomp);
        vector<string> out;
        unordered_set<string> wordset;

        for(int i = 0; i < words.size(); i++){
            if(dfs(words[i], wordset)){
                out.push_back(words[i]);
            }
            wordset.insert(words[i]);
        }
        return out;
    }
};
```

488题：祖玛游戏，祖玛游戏这个题目，是把字符串最后加了一个#号，然后把问题分解成，迭代删除相同颜色的球，以及从左往右依次插入球

```
class Solution {
public:
    int counts[5];
    int MAX_COUNT = 6;
    string removeDup(string s){
        int len = s.size();
        int left = 0;
        int right = 0;
        for(; left < len && right < len; right++){
            if(s[left]==s[right])
                continue;
            if(right-left>=3)
                return removeDup(s.substr(0, left)+s.substr(right, len-right));
            else
                left = right;
        }
        return s;
    }
    
    int dfs(string s){
        s = removeDup(s);
        if(s=="#"){
            return 0;
        }
        int out = MAX_COUNT;
        int left = 0;
        int right = 0;
        int len = s.size();

        for(; left < len && right < len; right++){
            if(s[left]==s[right])
                continue;
            int need = 3-(right-left);
            if(s[left]=='R' && counts[0]>=need){
                counts[0]-=need;
                out = min(out, need+dfs(s.substr(0, left)+s.substr(right, len-right)));
                counts[0]+=need;
            }
            else if(s[left]=='Y' && counts[1]>=need){
                counts[1]-=need;
                out = min(out, need+dfs(s.substr(0, left)+s.substr(right, len-right)));
                counts[1]+=need;
            }
            else if(s[left]=='B' && counts[2]>=need){
                counts[2]-=need;
                out = min(out, need+dfs(s.substr(0, left)+s.substr(right, len-right)));
                counts[2]+=need;
            }
            else if(s[left]=='G' && counts[3]>=need){
                counts[3]-=need;
                out = min(out, need+dfs(s.substr(0, left)+s.substr(right, len-right)));
                counts[3]+=need;
            }            
            else if(s[left]=='W' && counts[4]>=need){
                counts[4]-=need;
                out = min(out, need+dfs(s.substr(0, left)+s.substr(right, len-right)));
                counts[4]+=need;
            }
            left = right;
        }
        return out;
    }

    int findMinStep(string board, string hand) {

        memset(counts, 0, sizeof(counts));
        for(auto c : hand){
            switch(c){
                case 'R': counts[0]++;break;
                case 'Y': counts[1]++;break;
                case 'B': counts[2]++;break;
                case 'G': counts[3]++;break;
                case 'W': counts[4]++;break;
            }
        }

        int out = dfs(board+"#");
        return out==MAX_COUNT?-1:out;
    }
};
```

546题：开心消消乐

```
class Solution {
public:
    int dfs(vector<vector<vector<int>>>& dp, vector<int>& boxes, int l, int r, int k){
        if(l > r) return 0;
        if(dp[l][r][k] > 0) return dp[l][r][k];
        
        for(; l+1 <= r && boxes[l+1] == boxes[l]; l++, k++);
        int out = (k+1)*(k+1) + dfs(dp, boxes, l+1, r, 0);

        for(int i = l+1; i <= r; i++){
            if(boxes[l]==boxes[i]){
                out = max(out, dfs(dp, boxes, l+1, i-1, 0) + dfs(dp, boxes, i, r, k+1));
            }
        }
        dp[l][r][k] = out;
        return out;
    }

    int removeBoxes(vector<int>& boxes) {
        int len = boxes.size();
        vector<vector<vector<int>>> dp(len, vector<vector<int>>(len, vector<int>(len, 0)));

        return dfs(dp, boxes, 0, len-1, 0);
    }
};
```

