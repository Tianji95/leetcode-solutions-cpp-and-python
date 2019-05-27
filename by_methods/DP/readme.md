### 动态规划

动态规划比较适合那些有重叠子问题，有重复计算的题目类型

大部分情况下，dfs 可以用 dp 来代替

dp 的最关键的地方在于递归公式，同城递归公式是通过寻找最优解的结构特征来的

背包问题九讲 https://www.kancloud.cn/kancloud/pack/70125

里面提到的搜索和剪枝的算法，以及 01 背包问题，完全背包问题，以及多重背包问题的优化是非常重要的，需要彻底吃透

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

第 10 题/44 题，字符串的正则匹配实现，主要是使用动态规划来保存两个字符串相对位置时的 true 和 false

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

55 题，给一排数据，每一个数表示下次能到的最大距离，求是否能到最后，依次往后走就好了：

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

62/63/64 题，从左上角往右下角走，中间会有石头，输出路径的个数

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

72 题，字符串之间的“距离”问题，这个问题主要是要想好递推公式怎么用在“距离”这个概念上面，“距离”其实就是 dp\[i-1\]\[j\]就是第二个字母删除一个字母的操作，dp\[i]\[j-1]就是第二个字符串增加一个字母的操作，dp\[i]\[j]就是修改一个字母的操作，具体代码如下：

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

91 题：将数字转换成对应字母，查看有多少种方法的题目，题目难度主要集中在对数字的判断上面，判断是否在 1-26 之间，如果是 1-9 就加上上一个 dp，如果是 10-26 就加上上上一个 dp，代码如下：

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

97 题：计算两个字符串是否能拼成第三个字符串

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

115 题，字符串的题目，查找一个字符串从另一个字符串中提取出来的数量

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

·123 题，有两次买卖的机会，求出最大的收益，这里面设定两个值就好了，如果是两个以上的话，应该可以弄一个数组一类的东西来存当前的收益

188 题，有多次买卖的机会，弄一个数组来处理最大收益，不过还要考虑 K 很大的极端情况，这个时候就需要用到前面两个 easy 的方法了

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

132 题：给一串字符串，求这个字符串全部拆分成回文子串需要的最小次数。解题思路是用动态规划数组存储每一个 idx 为止字符串的最小切分次数，，然后以一个变量来存储最大回文串的长度，不断向前递归，求解最小值，代码如下：

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

213 题：中间不能有相邻两个数相加，收尾不能同时相加，其实只要两个 dp 就可以解决了。。。代码如下：

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

264 题：找到按照顺序的 ugly number， uglynumber 值得是所有的最小公约数可以分解成 2,3,5，题目主要是需要用三个索引分别指向 2,3,5

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

322 题：这道题是给一组硬币的面额，然后给一个目标数字，求出最小需要多少枚硬币，具体方法就是按照目标数字建立 dp 数组，然后再在里面遍历所有硬币，判断是否存在减去这个硬币以后的数值

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

368 题：这道题开了两个动态规划数组，一个是用来存个数的，另一个是用来存数字链的，其中 parent 表示比他大的数字链最多的那个数的索引

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

375 题：这一题和上面有一题非常的类似，都是最外面一层 for 循环表示长度，然后中间一层表示左边，最后一层表示在左和右之间的区间内进行循环遍历，查找最大的值，从而不断迭代 dp 中某一个元素的值，代码如下：

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

410 题：更像是一个二分检索方法，以后注意二分检索的用法，要在任何时候，想到用一个 left 和 right 两个数字，然后每次找数的时候都取中值，不断迭代出最后的结果

```
class Solution {
public:
    bool check(vector<int>& nums, int cut, long long maxtarget){
        long long acc = 0;
        for(auto& num : nums){
            if(num+acc<=maxtarget){
                acc += num;
            }
            else{
                cut--;
                acc = num;
                if(cut<0)
                    return false;
            }
        }
        return true;
    }

    int splitArray(vector<int>& nums, int m) {
        int len = nums.size();
        if(len==0)
            return 0;

        int left  = 0;
        long long right = 0;
        long long mid = 0;

        for(int i = 0; i < nums.size(); i++){
            if(nums[i]>left){
                left = nums[i];
            }
            right += nums[i];
        }

        while(left < right){
            mid = (left+right)/2;
            if(check(nums, m-1, mid)){
                right = mid;
            }
            else{
                left  = mid+1;
            }
        }
        return left;
    }
};
```

446 题：用一个嵌套 map 来写这道题，一个保存 index，另一个保存 diff，但是加的时候，只加后面那个值，没搞太明白为什么，代码如下：

```
class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& A) {
        vector<unordered_map<int, int>> dp(A.size());
        int out = 0;

        for(int i = 0; i < A.size(); i++){
            for(int j = 0; j < i; j++){
                if((long)A[i] - (long)A[j] > INT_MAX || (long)A[i] - (long)A[j] < INT_MIN) continue;
                int diff = A[i]-A[j];
                dp[i][diff] += 1;
                if(dp[j].find(diff)!=dp[j].end()){
                    dp[i][diff]+=dp[j][diff];
                    out+=dp[j][diff];
                }
            }
        }
        return out;
    }
};
```

474 题：多重背包问题，直接放代码，和下面 494 题的思路是差不多的

```
class Solution {



public:
    int findMaxForm(vector<string>& strs, int m, int n) {

        int out = 0;
        int len = strs.size();

        vector<vector<int>> nums(len, vector<int>(2, 0));

        for(int i = 0; i < len; i++){
            for(int j = 0; j < strs[i].size(); j++){
                nums[i][strs[i][j]-'0']++;
            }
        }

        vector<vector<int>> dp(m+1, vector<int>(n+1, 0));
        for(int i = 0; i < len; i++){
            for(int j = m; j >= nums[i][0]; j--){
                for(int k = n; k >= nums[i][1]; k--){
                    dp[j][k] = max(dp[j][k], dp[j-nums[i][0]][k-nums[i][1]]+1);
                }
            }
        }

        return dp[m][n];
    }

};
```

494 题：这一段 subset 的代码非常重要，dp 里面的内容指的是，在一串数组中，加起来得到 i 的可能性的个数，下面这个图片非常重要，也非常清晰，图片中的数组是\[1,1,1,1,1],最左边的 1 应该是 0。而且一定要有 dp\[0]=1，因为这个表示当相加都等于 0 的时候，有一种情况，就是什么都不选![0_1485048724190_Screen Shot 2017-01-21 at 8.31.48 PM.jpg](https://leetcode.com/uploads/files/1485048726667-screen-shot-2017-01-21-at-8.31.48-pm.jpg)

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

516 题：查找最长子字符串的问题，在一个字符串中找到存在的最长的子字符串，子字符串各个字母之间可以跳着

```
class Solution {
public:
    int longestPalindromeSubseq(string s) {
        int len = s.size();
        vector<vector<int>> dp(len, vector<int>(len, 0));

        for(int i = 0; i < len; i++){
            dp[i][i] = 1;
        }

        for(int l = 2; l <= len; l++){
            for(int left = 0; left < len-l+1; left++){
                int right = left + l-1;
                if(s[left]==s[right]){
                    dp[left][right] = dp[left+1][right-1]+2;
                }
                else{
                    dp[left][right] = max(dp[left+1][right], dp[left][right-1]);
                }
            }
        }
        return dp[0][len-1];
    }
};
```

518 题，硬币的问题，给一组硬币和一个目标值，输出有多少种方法：

```
class Solution {
public:
    int change(int amount, vector<int>& coins) {
        vector<int> dp(amount+1, 0);

        dp[0] = 1;
        for(int i = 0; i < coins.size(); i++){
            for(int j = coins[i]; j <= amount; j++){
                dp[j] += dp[j-coins[i]];
            }
        }
        return dp[amount];
    }
};
```

546 题：给一串数组，相同颜色的可以消除，得到共计 K\*K 分，和 zuma 游戏有些像，具体的方法是把消除的个数存起来，然后拆分成两半，，其中 K 指的是 right 右边有一串 k 个相同颜色的数组，同时 right 和后面的这几个颜色相同的数字颜色一样，分别计算：

````
class Solution {
public:
    int dfs(vector<int>& boxes, vector<vector<vector<int>>>& dp, int left, int right, int K){


    ```
        if(left > right)
            return 0;

        if(dp[left][right][K]!=0)
            return dp[left][right][K];

        //循环找到最小的right
        for( ; left<right&&boxes[right]==boxes[right-1]; right--, K++);

        dp[left][right][K] = (K+1)*(K+1) + dfs(boxes, dp, left, right-1, 0);

        for(int i = left; i < right; i++){
            if(boxes[right]==boxes[i]){
                dp[left][right][K] = max(dp[left][right][K], dfs(boxes, dp, left, i, K+1)+dfs(boxes, dp, i+1, right-1, 0));
            }
        }

        return dp[left][right][K];
    }

    int removeBoxes(vector<int>& boxes) {
        int len = boxes.size();
        vector<vector<vector<int>>> dp(len, vector<vector<int>>(len, vector<int>(len, 0)));
        return dfs(boxes, dp, 0, len-1, 0);
    }
    ```

};


````

552 题：连续字符串问题，有一个字符最多只能出现一次，有一个字符不能连续出现超过两次，那么我们就用一个 dp 的维度来判断是否出现了一次，另一个维度来判断第二个字符出现了一次，两次还是零次，最后一个字符判断长度 index

```
class Solution {
public:
    int checkRecord(int n) {

        // 0 : A
        // 1 : L
        // 2 : P

        vector<vector<vector<int>>> dp(2, vector<vector<int>>(3, vector<int>(n+1, 0)));

        for(int i = 0; i < 2; i++){
            for(int j = 0; j < 3; j++){
                dp[i][j][0] = 1;
            }
        }
        for(int k = 1; k <= n; k++){
            for(int i = 0; i < 2; i++){
                for(int j = 0; j < 3; j++){

                    dp[i][j][k] = dp[i][2][k-1]%1000000007; //P
                    if(i>0){
                         dp[i][j][k] =  (dp[i][j][k] + dp[i-1][2][k-1])%1000000007;//A
                    }
                    if(j>0){
                        dp[i][j][k]  =  (dp[i][j][k] + dp[i][j-1][k-1])%1000000007;
                    }
                }
            }
        }
        return dp[1][2][n];
    }
};
```

576 题：给一个矩形的固定边长，以及一个球的位置，需要走的步数，然后求出所有可能的操作的步数

```
class Solution {
public:
    int findPaths(int height, int width, int N, int I, int J) {
        vector<vector<vector<uint>>> dp(N+1, vector<vector<uint>>(height, vector<uint>(width, 0)));
        auto counts = [&](int k, int i, int j){
            return (i<0||i>=height||j<0||j>=width)?1:dp[k][i][j];
        };
        for(int n = 1; n <= N; n++){
            for(int h = 0; h < height; h++){
                for(int w = 0; w < width; w++){
                    dp[n][h][w] = counts(n-1, h-1, w) + counts(n-1, h, w-1) + counts(n-1, h+1, w) + counts(n-1, h, w+1);
                    dp[n][h][w] = dp[n][h][w] % (1000000007);
                }
            }
        }
        return dp[N][I][J];
    }
};
```

583 题：两个字符串的问题，直接用 dp 来表示两个字符串的索引，dp 内容表示需要操作的最小步骤：

```
class Solution {
public:
    int minDistance(string word1, string word2) {
        int len1 = word1.size();
        int len2 = word2.size();
        vector<vector<int>> dp(len1+1, vector<int>(len2+1, 0));

        for(int i = 0; i <= len1; i++){
            dp[i][0] = i;
        }
        for(int i = 0; i <= len2; i++){
            dp[0][i] = i;
        }

        for(int i = 1; i <= len1; i++){
            for(int j = 1;j <= len2; j++){
                if(word1[i-1] == word2[j-1]){
                    dp[i][j] = dp[i-1][j-1];
                }
                else{
                    dp[i][j] = min(dp[i-1][j-1]+2, min(dp[i-1][j]+1, dp[i][j-1]+1));
                }
            }
        }
        return dp[len1][len2];
    }
};
```

600 题，位运算的题目， 每一个 dp 数组存的是位数，这里面是从左往右计算的，一旦出现连续位就直接跳出：

```
class Solution {
public:
    int findIntegers(int num) {
        if(num==1)
            return 2;
        if(num==0)
            return 1;
        int dp[32];
        memset(dp, 0, sizeof(dp));

        dp[0] = 1;
        dp[1] = 2;

        for(int i = 2; i < 32; i++){
            dp[i] = dp[i-1] + dp[i-2];
        }

        int out = 0;
        bool prev = false;
        for(int i = 30; i >= 0; i--){
            if(num&(1<<i)){
                out += dp[i];
                if(prev){
                    return out;
                }
                prev = true;
            }
            else{
                prev = false;
            }
        }
        return out+1;
    }
};
```
