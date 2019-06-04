### 位运算

主要是与运算，或运算以及异或运算的特点

所有位运算的总结：
https://leetcode.com/problems/sum-of-two-integers/discuss/84278/A-summary%3A-how-to-use-bit-manipulation-to-solve-problems-easily-and-efficiently

leetcode 题目（13 题）

136

149

166

172

190

191

204

260

268

318

326

342

371



136题：查找数组里面唯一没有出现两次的数，直接用异或来解决就好

```
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int out = 0;
        for(auto &n: nums){
            out ^= n;
        }
        return out;
    }
};
```

149题，这道题是计算一张图里面，在一条线上的所有点的最大值，其中有两个思路，对于所有的点来说，和其他的点计算直线的斜率，如果斜率相同，加上本身是同一个点，所以肯定是在同一条线上面，把斜率的x和y存到map里面，另外如果是ysub直接除以xsub的话，精度会出现问题，所以不能这样做。最后要处理同一个地方拥有多个点的情况，以及在最后计算的时候是不包括自己的，所以要localmax+1

```
class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {
        int len = points.size();
        int out = 0;
        
        for(int i = 0; i < len; i++){

            unordered_map<int, unordered_map<int, int>> mp;
            int samepoint = 0;

            for(int j = i+1; j < len; j++){
                if(points[i][0]==points[j][0]&&points[i][1]==points[j][1]){
                    samepoint++;
                }
                else if(points[i][0] == points[j][0]){
                    mp[INT_MAX][0]++;
                }
                else{
                    int ysub = points[i][1] - points[j][1];
                    int xsub = points[i][0] - points[j][0];
                    int gcd = __gcd(ysub, xsub);
                    ysub /= gcd;
                    xsub /= gcd;
                    mp[ysub][xsub]++;

                }
            }
            int localmax = 0;
            for(auto& iter : mp){
                for(auto& initer : iter.second){
                    localmax = max(localmax, initer.second);
                }
            }
            localmax += samepoint;
            out = max(out, localmax+1);
        }
        return out;
    }
};
```

166题，手动进行除法的问题，将除数，被除数转换成字符串输出出来，其中最主要的是，在isvisit里面存储的是**余数，而不是除法以后的整数**这一点很重要。然后存储的是位置而不是只用一个unordered_set。最后这两个数的符号还是要单独处理，不能直接to_string(a/b)，因为如果是-0的话输出的是0而不是-0

```
class Solution {
public:
    string fractionToDecimal(long a, long b) {
        string out("");
        long resume;
        char dec;
        bool iscycle = false;
        unordered_map<long, int> isvisit;
        
        bool ismin = false;
        if((a<0&&b>0) ||(a>0&&b<0)){
            out = '-' + to_string(abs(a) / abs(b));
        }
        else{
            out = to_string(a / b);

        }

        a = abs(a);
        b = abs(b);

        resume = a % b;
        if(resume!=0){
            out.push_back('.');
        }
        int idx = out.size();
        while(resume != 0){
            a = resume * 10;
            dec = '0' + a / b;
            if(isvisit.find(a)==isvisit.end()){
                isvisit[a] = idx++;
                out.push_back(dec);
                resume = a % b;
            }
            else{
                out.push_back(')');
                iscycle = true;
                break;
            }
        }
        if(iscycle){
            out.insert(out.begin()+isvisit[a], '(');
        }
        return out;       
    }
};
```

172题，是一个比较有意思的题目，题目是查找n!中末尾有多少个0，其实就是查找n里面有多少个5

```
class Solution {
public:
    int trailingZeroes(int n) {
        if(n==0)
            return 0;
        return n/5+trailingZeroes(n/5);
    }
};
```

190题，位运算，翻转数字位数，仔细想一下就好了

```
class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t out = 0;
        
        for(int i = 0; i < 32; i++){
            out |= (((n&(1<<i))>>i)<<(31-i));
        }
        return out;
    }
};
```

191题，也很基础的位运算

```
class Solution {
public:
    int hammingWeight(uint32_t n) {
        int out = 0;
        for(int i = 0; i < 32; i++){
            if(((n>>i)&1)) out++;
        }
        return out;
    }
};
```

204题，题目是搜索的题目，只要稍微不考虑复杂度就很容易过

```
class Solution {
public:
    int countPrimes(int n) {
        
        if(n < 3) return 0;
        if(n == 3) return 1;
        if(n < 5) return 2;

        vector<int> dp(n, 0);
        dp[4] = 1;
        for(int i = 6; i < n; i++){
            if(i%2==0 || i%3==0 || i%5==0) dp[i] = 1;

        }

        for(long i = 6; i < n; i++){
            if(dp[i]) continue;
            for(long j = i; j*i < n; j++){
                dp[i*j] = 1;
            }
        }
        int out = 0;
        for(int i = 2; i < n; i++){
            if(dp[i]==0)
                out++;
        }
        return out;
    }
};
```

260题，找到数组中只出现一次的两个数，用异或可能不太够了，得把两个数分开，用一位来表示两个数之间的差异，然后再重新异或一下

```
class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int yihuo = 0;
        
        for(auto& n : nums){
            yihuo ^= n;
        }
        int lastbit = yihuo & (-yihuo);
        int A = 0;
        int B = 0;
        for(auto &n:nums){
            if(lastbit&n){
                A^=n;
            }
            else{
                B^=n;
            }
        }
        vector<int> out;
        out.push_back(A);
        out.push_back(B);
        return out;
    }
};
```

268题，查找0-n失踪的那个数字，可以用异或，也可以用加法

```
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        long total = nums.size()*(nums.size()+1)/2;
        long now = accumulate(nums.begin(), nums.end(), 0);

        return total-now;
    }
    //第二种方法
    int missingNumber(vector<int>& nums) {
        int res = 0;
        for(int i = 0; i < nums.size(); i++){
            res ^= (i + 1) ^ nums[i];
        }
        return res;
    }
};


```

318题，这道题是查找最长的两个字符串长度的乘积，注意，这道题学到的方法是**任何能用unordered_set或者isvisited的东西很大概率可以用位运算来进行标志**



```
struct MyComp{
    bool operator()(const string& left, const string& right){
        return left.size()<right.size();
    }
};

class Solution {
public:
    int maxProduct(vector<string>& words) {
        int out = 0;
        int len = words.size();
        vector<int> mask(len, 0);
        
        //sort(words.begin(), words.end(), MyComp());

        for(int i = 0; i < len; i++){
            for(auto& c : words[i]){
                mask[i] |= (1<<(c-'a'));
            }
        }

        for(int i = len-1; i >= 0; i--){
            for(int j = i-1; j >= 0; j--){
                if((mask[i] & mask[j])==0){
                    int tmp = words[i].size() * words[j].size();
                    out = max(out, tmp);
                }
            }
        }

        return out;
    }
};
```



326题，查找是不是3的n次方的题，很简单

```
class Solution {
public:
    bool isPowerOfThree(int n) {
        if(n<=0 || n>=INT_MAX)
            return false;
        int MAX = 1162261467;
        return MAX % n==0;
    }
};
```

342题，跟上面类似，但是是4的倍数，方法不太一样

```
class Solution {
public:
    bool isPowerOfFour(int num) {
        if(num==1) return true;
        
        for(int i = 2; i < 32; i+=2){
            if(num==(1<<i))
                return true;
        }
        return false;
    }
};
```

371题，用位运算实现加法

```
class Solution {
public:
    int getSum(int a, int b) {     
        return b==0?a:getSum(a^b, (a&b&0xffffffff)<<1);
    }
};
```

