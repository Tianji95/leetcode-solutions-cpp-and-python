### 双指针算法

一般来说双指针问题都是和滑动窗口一样的算法，一个快指针和一个慢指针，然后找到一快一慢两个指针之间满足条件的最大值，一般来说数组是有一定规律的





##### leetcode题目（24题）

3

11

15

16

18

26

30

75

76

80

88

141

142

159

209

259

283

287

340

360

395

532

611

第三题，最经典的双指针问题，查找最长的非重复字符的长度：

```
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int left  = 0;
        int out   = 0;
        int right = 0;
        int len = s.size();
        int cache[200];
        if(len == 0)
            return 0;
        
        memset(cache, 0, sizeof(cache));

        while(right < len){
            cache[s[right]]++;
            while(cache[s[right]]>1 && left<right){
                cache[s[left]]--;
                left++;
            }
            out = max(out, right-left+1);
            right++;
        }
        return out;
    }
};
```



11题：

```
class Solution {
public:
    int maxArea(vector<int>& height) {
        int len = height.size();
        if(len == 0)
            return 0;
        int left = 0;
        int right = len-1;
        int out = 0;
        int now = 0;
        
        while(left<right){
            now = min(height[left], height[right])*(right-left);
            if(now>out){
                out = now;
            }
            if(height[left]<height[right]){
                left++;
            }
            else{
                right--;
            }
        }
        return out;
    }
};
```

15题/16题思路差不多：三数之和等于一个定值，找出所有可能的情况，用两个指针在for循环里面做就好

```
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int len = nums.size();
        vector<vector<int>> out;
        vector<int> now(3, 0);
        int left = 0;
        int right = 0;
        int last = 0;
        
        sort(nums.begin(), nums.end());

        for(int i = 0; i < len-2; i++){
            now[0] = nums[i];
            left = i+1;
            right = len-1;

            while(left<right){
                last = nums[left]+nums[right];
                if(last > -now[0]){
                    right--;
                }
                else if(last < -now[0]){
                    left++;
                }
                else{
                    now[1] = nums[left];
                    now[2] = nums[right];
                    out.push_back(now);
                    left++;
                    while(left<right && nums[left]==nums[left-1]){
                        left++;
                    }
                    right--;
                    while(left<right&&nums[right]==nums[right+1]){
                        right--;
                    }
                }
            }
            while(i+1<len && nums[i]==nums[i+1]){
                i++;
            }
        }
        return out;
    }
};
```

18题，思路跟上面差不多，但是更麻烦一些，多了一层循环

```
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int left, right;
        vector<vector<int>> out;
        vector<int> now(4, 0);
        int nownum;
        if(nums.size()<4)
            return out;
        sort(nums.begin(), nums.end());
        
        
        for(int i = 0; i < nums.size()-3; i++){
            now[0] = nums[i];
            for(int j = i+1; j < nums.size()-2; j++){
                now[1] = nums[j];
                left = j+1;
                right = nums.size()-1;
                while(left < right){
                    nownum = now[0]+now[1]+nums[left]+nums[right];
                    if(nownum < target){
                        left++;
                    }
                    else if(nownum > target){
                        right--;
                    }
                    else{
                        now[2] = nums[left];
                        now[3] = nums[right];
                        out.push_back(now);
                        left++;
                        while(left<right && nums[left]==nums[left-1])left++;
                        right--;
                        while(left<right && nums[right]==nums[right+1])right--;
                    }
                }
                while(j+1<nums.size()-2&&nums[j]==nums[j+1])j++;
            }
            while(i+1<nums.size()-3&&nums[i]==nums[i+1])i++;
        }
        return out;
    }
};
```

30题：思路跟上面差不多，但是是字符串类型的，如果把上面的数字换成字符串的话，就是第30题了，

```
class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int> out;
        unordered_map<string, int> count;
        
        if(words.size()==0 || s.size()==0){
            return out;
        }

        for(string& ss : words){
            count[ss]++;
        }

        int left, right;
        int len = words[0].size();
        string now;

        for(int i = 0; i < s.size()-len*words.size()+1; i++){
            left = 1;
            unordered_map<string, int> seen;
            while(left <= words.size()){
                now = s.substr(i+(left-1)*len, len);
                if(count.find(now)!=count.end()){
                    seen[now]++;
                    if(seen[now] > count[now]){
                        break;
                    }
                }
                else{
                    break;
                }
                left++;
            }
            if(left==words.size()+1){
                out.push_back(i);
            }
        }

        return out;
    }
};
```

