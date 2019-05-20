### 动态规划

动态规划比较适合那些有重叠子问题，有重复计算的题目类型

大部分情况下，dfs 可以用 dp 来代替

dp 的最关键的地方在于递归公式，同城递归公式是通过寻找最优解的结构特征来的

##### leetcode 题目（44 题）

10

44

53

55

62

63

64

70

72

91

97

115

121

122

123

132

139

152

188

213

221

264

265

276

309

312

322

368

375

376

377

410

446

474

487

494

516

518

546

552

576

583

600



第10题/44题，字符串的正则匹配实现，主要是使用动态规划来保存两个字符串相对位置时的true和false

```
class Solution
{
public:
	bool isMatch(string s, string p) {
		int slen = s.size();
		int plen = p.size();
		
        vector<vector<int>> dp(slen + 1, vector<int>(plen + 1, 0));

        dp[0][0] = 1;

        for (int i = 0; i < plen; i++)
        {
            if (p[i] == '*')
                dp[0][i + 1] = dp[0][i];
        }

        for (int sidx = 0; sidx < slen; sidx++)
        {
            for (int pidx = 0; pidx < plen; pidx++)
            {
                if (p[pidx] == '?')
                {
                    dp[sidx + 1][pidx + 1] = dp[sidx][pidx];
                }
                else if (p[pidx] == s[sidx])
                {
                    dp[sidx + 1][pidx + 1] = dp[sidx][pidx];
                }
                else if (p[pidx] == '*')
                {
                    dp[sidx + 1][pidx + 1] = dp[sidx][pidx] || dp[sidx + 1][pidx] || dp[sidx][pidx + 1];
                }
            }
        }

        return dp[slen][plen];
    }
};
```

55题，给一排数据，每一个数表示下次能到的最大距离，求是否能到最后，依次往后走就好了：

```
class Solution {
public:
    bool canJump(vector<int>& nums) {
        int len = nums.size();
        int now = 0;
        
        for(int i = 0; i < len-1; i++){
            now = max(now, nums[i]);
            if(now<=0)
                return false;
            now--;
        }
        return true;
    }
};
```

62/63/64题，从左上角往右下角走，中间会有石头，输出路径的个数

```
class Solution
{
public:
	int uniquePathsWithObstacles(vector<vector<int>>& input) {
		int height = input.size();
		if (height == 0)
			return 1;
		int width = input[0].size();
		if (width == 0)
			return 1;

        vector<vector<int>> dp(height, vector<int>(width, 0));

        dp[0][0] = 1;

        for (int h = 0; h < height; h++)
        {
            if (input[h][0] == 1)
                break;
            dp[h][0] = 1;
        }
        for (int w = 0; w < width; w++)
        {
            if (input[0][w] == 1)
                break;
            dp[0][w] = 1;
        }
        for (int h = 1; h < height; h++)
        {
            for (int w = 1; w < width; w++)
            {
                if (input[h][w] != 1)
                {
                    dp[h][w] = dp[h - 1][w] + dp[h][w - 1];
                }
            }
        }
        return dp[height - 1][width - 1];
    }
};
```

72题，字符串之间的“距离”问题，这个问题主要是要想好递推公式怎么用在“距离”这个概念上面，“距离”其实就是dp\[i-1\]\[j\]就是第二个字母删除一个字母的操作，dp\[i]\[j-1]就是第二个字符串增加一个字母的操作，dp\[i]\[j]就是修改一个字母的操作，具体代码如下：

```
class Solution {
public:
    int minDistance(string word1, string word2) {
        int m = word1.size();
        int n = word2.size();
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
        for(int i = 0; i <= m; i++)
            dp[i][0] = i;
        for(int j = 0; j <= n; j++)
            dp[0][j] = j;
        for(int i = 1; i <= m; i++){
            for(int j = 1; j <= n; j++){
                if(word1[i - 1] == word2[j - 1]){
                    dp[i][j] = dp[i - 1][j - 1];
                }
                else{
                    int opt1 = dp[i - 1][j]; // delete
                    int opt2 = dp[i][j - 1]; // insert
                    int opt3 = dp[i - 1][j - 1]; // replace
                    dp[i][j] = min(opt1, min(opt2, opt3)) + 1;
                }
            }
        }
        return dp[m][n];
    }
};
```

91题：将数字转换成对应字母，查看有多少种方法的题目，题目难度主要集中在对数字的判断上面，判断是否在1-26之间，如果是1-9就加上上一个dp，如果是10-26就加上上上一个dp，代码如下：

```
class Solution {
public:
    int numDecodings(string s) {
        if(s.size()==0)
            return 0;
        
        vector<long> dp(s.size()+1, 0);
        dp[0] = 1;
        dp[1] = s[0]=='0'?0:1;
        for(int i = 1; i < s.size(); i++){
            if(s[i] >= '1' && s[i] <= '9') {
               dp[i+1] += dp[i];  
            }
            if((s[i-1]=='1'&&s[i]<='9') ||(s[i-1]=='2'&&s[i]<='6')) {
                dp[i+1] += dp[i-1];
            }
        }
        return dp[s.size()];
    }
};
```

