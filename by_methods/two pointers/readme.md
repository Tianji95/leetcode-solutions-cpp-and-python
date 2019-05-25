### 双指针算法

一般来说双指针问题都是和滑动窗口一样的算法，一个快指针和一个慢指针，然后找到一快一慢两个指针之间满足条件的最大值，一般来说数组是有一定规律的





##### leetcode题目（22题）

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

75题：三指针的算法，可以用left/mid/right三个指针来进行移动，0-left必定都是0，mid在left前面，把遇到的所有2都交给right-len， 这样mid和left之前肯定都是1了。



```
class Solution {
public:
    void sortColors(vector<int>& nums) {
        int left = 0;
        int mid  = 0;
        int right = nums.size()-1;
        
        while(mid<=right){
            if(nums[mid]==0){
                swap(nums[mid], nums[left]);
                left++;
                mid++;
            }
            else if(nums[mid]==1){
                mid++;
            }
            else if(nums[mid]==2){
                swap(nums[mid], nums[right]);
                right--;
            }
        }
    }
};
```

76题，双指针的算法，查找最短的拥有另一个字符字母的子字符串

```
class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char, int> count;
       
        int outleft = INT_MAX;
        int outright = INT_MAX;
        int maxlen = INT_MAX;
        int left  = 0;
        int right = 0;
        int len = s.size();
        int totalcount = t.size();
        bool ishas = false;

        for(auto& ss : t){
            count[ss]++;
        }

        while(right < len){
            if(count.find(s[right])!=count.end()){
                count[s[right]]--;
                totalcount--;
                if(totalcount<=0 && count[s[right]]<=0){
                    ishas = true;
                    for(auto& iter : count){
                        if(iter.second>0){
                            ishas = false;
                            break;
                        }
                    }
                    if(ishas){
                        while(left<=right){
                            if(maxlen>right-left+1){
                                outleft = left;
                                outright = right; 
                                maxlen = right-left+1;
                            }
                            if(count.find(s[left])!=count.end()){
                                count[s[left]]++;
                                totalcount++;
                                if(count[s[left]]>0){
                                    left++;
                                    break;
                                }

                            }
                            left++;
                        }
                    }
                }
            }
            right++;
        }
        if(outleft==outright&&outright==INT_MAX){
            return "";
        }
        return s.substr(outleft, outright-outleft+1);;
    }
};
```

88题：合并两个已经排序的数组，这里面是从后往前进行遍历的，先从大的数还是插，最后插入最小的数。虽然是easy，但是从后往前的思路非常的重要

```
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int first  = m-1;
        int second = n-1;
        int total  = m+n-1;
        
        while(first>=0 && second>=0){
            if(nums1[first]>nums2[second]){
                nums1[total--] = nums1[first--];
            }
            else{
                nums1[total--] = nums2[second--];
            }
        }
        while(first>=0){
            nums1[total--] = nums1[first--];
        }
        while(second>=0){
            nums1[total--] = nums2[second--];
        }
    }
};
```

142题：检测链表里面是否有环，并且把环里面第一个node给输出出来，这里面检测链表是否有环很简单，但是把环里面的输出出来就很麻烦。它里面是设right走了2*k步，left走了k步，环的长度是r,第一个节点到环头的距离是s,环头到指针相遇的节点距离为m，那么有：

2k-k = nr;

s+m = k

s = k-m = nr-m = nr-r+r-m 当n==1的时候s=r-m就是环剩下要走的路，那么只要有一个头结点和当前相遇节点同时跑的话，两者再次相遇的时候就是头结点了。代码如下

```
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        ListNode* left  = head;
        ListNode* right = head;
        while(right){
            left = left->next;
            right = right->next;
            if(right){
                right = right->next;
            }
            else{
                return nullptr;
            }
            if(left==right){
                left = head;
                while(left!=right){
                    left = left->next;
                    right=right->next;
                }
                return left;
            }
        }
        return nullptr;
    }
};
```

287题，是上面142题的变种，只不过变成数组了，代码如下

```
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int left = 0;
        int right = 0;
        while(true){
            left = nums[left];
            right = nums[nums[right]];
            if(left==right){
                left = 0;
                while(left!=right){
                    left = nums[left];
                    right=nums[right];
                }
                return left;
            }
        }
        return 0;
    }
};
```

