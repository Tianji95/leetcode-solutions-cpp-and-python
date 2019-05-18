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

