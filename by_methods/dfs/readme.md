### 深度优先搜索

递归访问搜索某一个值或者得到某一个值，先搜索深度，递归深度越来越深

中间如果能够剪枝或者调换搜索顺序的话，可以让算法非常快的结束



##### leetcode题目（23题）

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



37题：解数独的题目，一个DFS就可以搞定，其中比较麻烦的一点就是要修改行，列，块的时候，在改回原样时是反过来的

51题：n皇后问题，一个dfs照样可以搞定，不过每行每列的时候，可以通过位运算来把每行每列都存下来，存到一个int数里面，如下方法：

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

105题：通过前序和中序来生成树：查找前序的值在中序数组中的位置，位置以前的都是左子树，位置异或的都是右子树：

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

106题：通过中序和后序来生成树，从后往前查找后序在中序中的位置，前面的都是左子树，右边的都是右子树

199题：从右往左看一个树，输出所有看到的第一个数：遍历的时候先遍历右子树，有的话就直接插入，没有的话就插入左边的，判断输出数组的大小和层级就行了

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

200题：算一个矩阵里面有多少个岛屿，直接拿#号替代掉对应位置的值就好了

210题：先构图，构完图以后再进行dfs或者bfs：

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

282题：一个类似于堆栈计算器的题目，dfs来做，不过要注意乘号和+-号的优先级不一样，所以这里的做法是：把上一次操作的数字和符号记录下来，如果这次遇到乘号，就回退上次操作，然后做乘法，保留上次的符号到下一次

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

312题：打气球问题，每打一次气球，都会把当前气球分数和两边的气球分数乘起来，求最大的分数，其实这是一道dp的问题，dp的公式是表示left到right中间这一段的最大值，其中要用for循环寻找每一个left到right中间的值，这样才能取到最大值

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

332题



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

337题:

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



399题：给出一组序列的比例关系，让你去递推其他序列的比例关系，先做图，然后递归进行递推

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

403题：







