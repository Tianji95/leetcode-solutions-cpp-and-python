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

97题：计算两个字符串是否能拼成第三个字符串

```
class Solution
{
public:
	bool isInterleave(string s1, string s2, string s3) {
		int len1 = s1.size();
		int len2 = s2.size();
        if(len1+len2 != s3.size())
            return false;
		vector<vector<int>> dp(len1 + 1, vector<int>(len2 + 1, 0));

        dp[0][0] = 1;

        for (int i = 1; i <= len1; i++)
        {
            if (s1[i - 1] == s3[i - 1])
            {
                dp[i][0] = dp[i-1][0];
                if (dp[i][0] == 0)
                    break;
            }
            else
            {
                break;
            }
        }

        for (int i = 1; i <= len2; i++)
        {
            if (s2[i - 1] == s3[i - 1])
            {
                dp[0][i] = dp[0][i - 1];
                if (dp[0][i] == 0)
                    break;
            }
            else
            {
                break;
            }
        }

        for (int i = 1; i <= len1; i++)
        {
            for (int j = 1; j <= len2; j++)
            {
                if (s1[i - 1] == s3[i + j - 1])
                {
                    dp[i][j] |= dp[i - 1][j];
                }
                if (s2[j - 1] == s3[i + j - 1])
                {
                    dp[i][j] |= dp[i][j - 1];
                }
            }
        }

        return dp[len1][len2] > 0;
    }
};
```

115题，字符串的题目，查找一个字符串从另一个字符串中提取出来的数量

```
class Solution {
public:
    int numDistinct(string s, string t) {
        int lens = s.size();
        int lent = t.size();
        vector<vector<long>> dp(lens+1, vector<long>(lent+1, 0));

        dp[0][0] = 1;
        for(int i = 0; i <= lens; i++){
            dp[i][0] = 1;
        }
        for(int i = 0; i < lens; i++){
            for(int j = 0; j < lent; j++){
                if(s[i]==t[j]){
                    dp[i+1][j+1] = dp[i][j] + dp[i][j+1];
                }
                else{
                    dp[i+1][j+1] = dp[i][j+1];
                }
            }
        }

        return dp[lens][lent];
    }
};
```

·123题，有两次买卖的机会，求出最大的收益，这里面设定两个值就好了，如果是两个以上的话，应该可以弄一个数组一类的东西来存当前的收益

188题，有多次买卖的机会，弄一个数组来处理最大收益，不过还要考虑K很大的极端情况，这个时候就需要用到前面两个easy的方法了

```
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int len = prices.size();
        if(len == 1 || len == 0)
            return 0;
        int sel1 = 0;
        int buy1 = INT_MIN;
        int sel2 = 0;
        int buy2 = INT_MIN;
        
        for(int i = 0; i < len; i++){
            buy1 = max(buy1, -prices[i]);
            sel1 = max(prices[i]+buy1, sel1);
            buy2 = max(sel1-prices[i], buy2);
            sel2 = max(prices[i]+buy2, sel2);
        }
        return sel2;
    }
};

```

```
class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {

        int len = prices.size();

        if(k>len/2){
            int out = 0;
            int buy = INT_MAX;
            for(int i = 0; i < len; i++){
                if(prices[i] > buy){
                    out += prices[i]-buy;
                    buy = prices[i];
                }
                else{
                    buy = prices[i];
                }
            }
            return out;
        }

        vector<int> buys(k+1, INT_MIN);
        vector<int> sels(k+1, 0);
        int out = INT_MIN;
        for(int i = 0; i < len; i++){
            for(int j = 1; j <= k; j++){
                buys[j] = max(buys[j], sels[j-1]-prices[i]);
                sels[j] = max(prices[i]+buys[j], sels[j]);
                out = max(out, sels[j]);
            }
        }
        return max(out, 0);
    }
};
```



132题：给一串字符串，求这个字符串全部拆分成回文子串需要的最小次数。解题思路是用动态规划数组存储每一个idx为止字符串的最小切分次数，，然后以一个变量来存储最大回文串的长度，不断向前递归，求解最小值，代码如下：

```
class Solution {
public:
    bool ispali(string s){
        int len = s.size();
        int left = 0;
        int right = len-1;
        while(left < right){
            if(s[left++]!=s[right--])
                return false;
        }
        return true;
    }
    
    int minCut(string s) {

        int len = s.size();
        vector<int> dp(len+1, 0);

        for(int i = 0; i <= len; i++){
            dp[i] = i-1;
        }
        for(int i = 1; i < len; i++){
            for(int j = 0; j <= i && i+j<len && s[i-j]==s[i+j]; j++){ // 偶数
                dp[i+j+1] = min(dp[i+j+1], 1+dp[i-j]);
            }
            for(int j = 0; j <=i-1 && i+j<len && s[i-j-1]==s[i+j]; j++){ //奇数
                dp[i+j+1] = min(dp[i+j+1], 1+dp[i-j-1]);
            }
        }
        return dp[len];
    }

};
```

213题：中间不能有相邻两个数相加，收尾不能同时相加，其实只要两个dp就可以解决了。。。代码如下：

```
class Solution {
public:
    int rob(vector<int>& nums) {
        int len = nums.size();
        if(len == 0)
            return 0;
        if(len == 1)
            return nums[0];
        
        len = nums.size();
        int out = 0;
        vector<int> dp1(len+1, 0);
        vector<int> dp2(len+1, 0);
        dp1[0] = 0;
        dp1[1] = nums[0];

        for(int i = 2; i <= len; i++){
            dp1[i] = max(dp1[i-1], dp1[i-2]+nums[i-1]);
            dp2[i] = max(dp2[i-1], dp2[i-2]+nums[i-1]);
        }
        return max(dp1[len-1],dp2[len]);
    }
};
```

264题：找到按照顺序的ugly number， uglynumber值得是所有的最小公约数可以分解成2,3,5，题目主要是需要用三个索引分别指向2,3,5

```
class Solution {
public:
    int nthUglyNumber(int n) {
        
        vector<int> dp(n+1, 0);

        dp[0] = 1;
        int idx1 = 0;
        int idx2 = 0;
        int idx3 = 0;
        int num1,num2,num3;
        num1 = num2 = num3 = 1;

        for(int i = 1; i <= n; i++){

            dp[i] = min(num1, min(num2, num3));
            if(dp[i]==num1){
                idx1++;
                num1 = dp[idx1]*2;
            }
            if(dp[i]==num2){
                idx2++;
                num2 = dp[idx2]*3;
            }
            if(dp[i]==num3){
                idx3++;
                num3 = dp[idx3]*5;
            }
        }
        return dp[n];
    }
};
```

322题：这道题是给一组硬币的面额，然后给一个目标数字，求出最小需要多少枚硬币，具体方法就是按照目标数字建立dp数组，然后再在里面遍历所有硬币，判断是否存在减去这个硬币以后的数值

```
class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int Max = amount + 1;
        vector<int> dp(amount + 1, Max);
        dp[0] = 0;
        for (int i = 1; i <= amount; i++) {
            for (int j = 0; j < coins.size(); j++) {
                if (coins[j] <= i) {
                    dp[i] = min(dp[i], dp[i - coins[j]] + 1);
                }
            }
        }
        return dp[amount] > amount ? -1 : dp[amount];
    }
};
```

368题：这道题开了两个动态规划数组，一个是用来存个数的，另一个是用来存数字链的，其中parent表示比他大的数字链最多的那个数的索引

```
class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        
        vector<int> T(nums.size(), 0);
        vector<int> parent(nums.size(), 0);

        int m = 0;
        int mi = 0;

        for(int i = nums.size() - 1; i >= 0; --i)
        {
            for(int j = i; j < nums.size(); ++j)
            {
                if(nums[j] % nums[i] == 0 && T[i] < 1 + T[j])
                {
                    T[i] = 1 + T[j];
                    parent[i] = j;

                    if(T[i] > m)
                    {
                        m = T[i];
                        mi = i;
                    }
                }
            }
        }

        vector<int> out;

        for(int i = 0; i < m; ++i)
        {
            out.push_back(nums[mi]);
            mi = parent[mi];
        }

        return out;
    }

};
```

375题：这一题和上面有一题非常的类似，都是最外面一层for循环表示长度，然后中间一层表示左边，最后一层表示在左和右之间的区间内进行循环遍历，查找最大的值，从而不断迭代dp中某一个元素的值，代码如下：

```
class Solution {
public:
    int getMoneyAmount(int n) {
        vector<vector<int>> dp(n+1, vector<int>(n+1, 0));
        
        for(int len = 2; len <= n; len++){
            for(int left = 1; left <= n-len+1; left++){
                dp[left][left+len-1]=INT_MAX;
                for(int right=left; right < left+len-1;right++){
                    int costForThisGuess = 0;
                    if(right==n){
                        costForThisGuess = dp[left][right-1]+right;
                    }
                    else{
                        costForThisGuess = max(dp[left][right-1], dp[right+1][left+len-1]) + right;
                    }
                    dp[left][left+len-1] = min(dp[left][left+len-1], costForThisGuess);
                }
            }
        }
        return dp[1][n];
    }
};
```

494题：

```
class Solution {
public:
    int subset(vector<int>&nums, int s){
        vector<int> dp(s+1, 0);
        dp[0] = 1;
        for(int j = 0; j < nums.size();j++){
            for(int i = s; i >= nums[j]; i--){
                dp[i] += dp[i-nums[j]];
            }
        }
        return dp[s];
    }
    int findTargetSumWays(vector<int>& nums, int S) {

        int sum = accumulate(nums.begin(), nums.end(), 0);
        if(sum<S){
            return 0;
        }
        if((sum+S)%2==1){
            return 0;
        }
        return subset(nums, (sum+S)>>1);
    }
};
```

