### 贪心算法

一般来说贪心算法在解决最优子结构的问题中是比较有效的，贪心算法每一步都是局部最优解，从而在多步计算以后得到全局最优解，但是大部分情况贪心算法得到的并不是全局最优，所以在算法中一旦用贪心算法，贪心算法一定是解决这个问题最好的算法

45

84

85

122

134

135 这里面的贪心算法比较贪心，，，先从左往右贪心一遍，然后不管不顾，再从右往左贪心一遍（因为每个数都会受到两边数的影响）

221

229

300

316

321

330

334

354

358

386

440

484

517



一个比较基本的贪心算法：用栈来实现，是以第84题为基础的

具体的代码为：

		for (int i = 0; i < len; i++)
		{
			while (stk.size() != 0 && heights[stk.top()] >= heights[i])
			{
				int h = heights[stk.top()];
				stk.pop();
				int idx = stk.size() > 0 ? stk.top() : -1;
				nowsize =  h * (i - idx - 1);
				
				if (out < nowsize)
				{
					out = nowsize;
				}
			}
			stk.push(i);
	
		}
这段代码用来计算最大的矩形



还有一个是135题candy的代码：



```C++
class Solution {
public:
    int candy(vector<int>& ratings) {
        int len = ratings.size();
        int out = 1;
        int lastMinIdx = 0;
        int lastMinCandy = 1;
        int lastCandy = 1;
            
    if(len == 0)
        return 0;

    for(int i = 1; i < len; i++){
        if(ratings[i] < ratings[i-1]){
            lastCandy = 1;
            if(i-lastMinIdx == lastMinCandy){
                out+=i-lastMinIdx+1;
                lastMinCandy++;
            }
            else{
                out+= i-lastMinIdx;
            }
            
        }
        else if(ratings[i] > ratings[i-1]){
            lastCandy++;
            out += lastCandy;
            lastMinCandy = lastCandy;
            lastMinIdx = i;
        }
        else{
            out++;
            lastCandy = 1;
            lastMinIdx = i;
            lastMinCandy = 1;
        }
    }
    return out;
}

};
```

或者，先从左往右贪心一遍，然后再从右往左贪心一遍

    int candy(vector<int>& ratings) {
        int out = 0;
        int len = ratings.size();
        vector<int> nums(len, 1);
    
        for(int i = 1; i < len; i++){
            if (ratings[i] > ratings[i-1]){
                nums[i] = nums[i-1]+1;
            }
        }
        
        for(int i = len-1; i > 0; i--){
            if (ratings[i-1] > ratings[i]){
                nums[i-1] = max(nums[i]+1, nums[i-1]);
            }
        }
        
        for(int i = len-1; i >= 0; i--){
            out += nums[i];
        }
        
        return out;
    }


229题，输出所有出现次数大于len/3的数字：用num1和num2分别表示两个数，然后用count1,count2表示这两个数出现的次数，如果又遇到这两个数，就++，如果不是的话就--，减到0以后就把num1或者num2换一个新的数



300题：找到最长递增子序列的题目，就是找到最长的递增的子序列长度，以及变种354题

```
int lengthOfLIS(vector<int>& nums) {
    vector<int> res;
    for(int i=0; i<nums.size(); i++) {
        auto it = std::lower_bound(res.begin(), res.end(), nums[i]);
        if(it==res.end()) res.push_back(nums[i]);
        else *it = nums[i];
    }
    return res.size();
}
```

316题：删除字符串中所有重复字母，同时让输出的字符串最小：

```
public class Solution {
    public String removeDuplicateLetters(String s) {
        int[] cnt = new int[26];
        int pos = 0; // the position for the smallest s[i]
        for (int i = 0; i < s.length(); i++) cnt[s.charAt(i) - 'a']++;
        for (int i = 0; i < s.length(); i++) {
            if (s.charAt(i) < s.charAt(pos)) pos = i;
            if (--cnt[s.charAt(i) - 'a'] == 0) break;
        }
        return s.length() == 0 ? "" : s.charAt(pos) + removeDuplicateLetters(s.substring(pos + 1).replaceAll("" + s.charAt(pos), ""));
    }
}
```

321题，给两个数字数组，找出两个数组中间拼出的最大的数

```
class Solution {
public:
vector<int> maxNumber(vector<int>& nums1, vector<int>& nums2, int k) {
    int n1 = nums1.size(), n2 = nums2.size();
    vector<int> best;
    for (int k1=max(k-n2, 0); k1<=min(k, n1); ++k1)
        best = max(best, maxNumber(maxNumber(nums1, k1),
                                   maxNumber(nums2, k-k1)));
    return best;
}

vector<int> maxNumber(vector<int> nums, int k) {
    int drop = nums.size() - k;
    vector<int> out;
    for (int num : nums) {
        while (drop && out.size() && out.back() < num) {
            out.pop_back();
            drop--;
        }
        out.push_back(num);
    }
    out.resize(k);
    return out;
}

vector<int> maxNumber(vector<int> nums1, vector<int> nums2) {
    vector<int> out;
    while (nums1.size() + nums2.size()) {
        vector<int>& now = nums1 > nums2 ? nums1 : nums2;
        out.push_back(now[0]);
        now.erase(now.begin());
    }
    return out;
}
};
```

330题：找到可以加起来都能够达到的数字，主要是用miss表示下一个没有的数字，如果没有miss的话就加一个miss：

```
class Solution {
public:
    int minPatches(vector<int>& nums, int n) {
        long miss = 1;
        int i = 0;
        int out = 0;
        while (miss <= n){
            if(i >= nums.size() || nums[i] > miss){
                out++;
                miss += miss;
            }
            else{
                miss += nums[i];
                i++;
            }
        }
        return out;
    }
};
```

386题：按照字母顺序输出数字

```
class Solution {
public:
    void dfs(int target, int n, vector<int>& out){
        if(target > n)
            return ;
        out.push_back(target);
        dfs(target*10, n, out);
        if (target % 10 != 9) 
            dfs(target+1, n, out);
    }
    vector<int> lexicalOrder(int n) {
        vector<int> out;
        dfs(1, n, out);
        return out;
    }
};
```

440题：

```
class Solution {
public:
    int iter(int n, int k, long long start){
        if(k > 0){
            int count;
            for(int i = 0; i <= 9; i++){
                count = GetCountByThisPrefix(start*10+i, n);
                if(k <= count){
                    return iter(n, k-1, start*10+i);
                }
                else{
                    k -= count;
                }
            }
        }
        return start;
    }
    
int findKthNumber(int n, int k) {
    int count;
    for(int i = 1; i <= 9; i++){
        count = GetCountByThisPrefix(i, n);
        if(k <= count){
            return iter(n, k-1, i);
        }
        else{
            k -= count;
        }
    }
    return 0;
}
int GetCountByThisPrefix(long long prefix, int n){
    int count = 0;
    long long fac = 1;
    for(int i = 1; i <= 9; i++){
        long long minval = fac*prefix;
        long long maxval = fac*prefix+fac-1;
        if(n < minval)
            break;
        else if(n >= minval && n <= maxval){
            count += (n-minval+1);
            break;
        }
        else{
            count += fac;
            fac *= 10;
        }
        
    }
    return count;
}
};
```

517题：洗衣机问题：

```
class Solution {
public:
    int findMinMoves(vector<int>& machines) {
        int len = machines.size();
        int total = accumulate(machines.begin(), machines.end(), 0);
        if(total % len != 0)
            return -1;
        
    int each = total/len;
    int out = 0;
    vector<int> sums(len+1, 0);
    
    for(int i = 0; i < len; i++){
        sums[i+1] = sums[i]+machines[i];
    }
    for(int i = 0; i < len; i++){
        int left = i * each - sums[i];
        int right = (len-i-1)*each - (sums[len]-sums[i+1]);
        if(left > 0 && right > 0){
            out = max(out, left+right);
        }
        else{
            out = max(out, max(left, right));
        }
    }
    return out;
    
}
};
```

