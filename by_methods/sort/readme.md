### 排序

没什么好说的



leetcode题目（10题）

41

164

215

275

406

435

442

448

452

581



41题：这道题还是很巧妙的，是一套思路，就是把n个数都放在自己应该有的位置上，然后重新遍历的时候就能够找到需要找的那个数字，排序的复杂度是O（n），代码如下

其实第448题也是这个套路，448题的代码是下面的那块

```
class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        for(int i = 0; i < nums.size(); i++){
            while(nums[i]>INT_MIN&&(nums[i]-1) < nums.size() && nums[i]!=nums[nums[i]-1]){
                swap(nums[i], nums[nums[i]-1]);
            }
        }
        for(int i = 0; i < nums.size(); i++){
            if(nums[i]!=i+1){
                return i+1;
            }
        }
        return nums.size()+1;
    }
};


class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        for(int i = 0; i < nums.size(); i++){
            while(nums[i]!=i+1 && nums[i] != nums[nums[i]-1]){
                swap(nums[i], nums[nums[i]-1]);
            }
        }
        vector<int> out;
        for(int i = 0; i < nums.size(); i++){
            if(nums[i]!=i+1){
                out.push_back(i+1);
            }
        }
        return out;
    }
};
```

164题：桶排序，所有的桶排序需要知道的是：gap需要向上取整，在找最大和最小值的时候应该直接忽略掉最大最小值，然后在最后一行，应该把空的桶忽略掉，还应该在最后取out = max(out, maxval-prev);

以及最开始prev=minval的时候out = max(out, minbucket[i]-prev);代码入下

```
class Solution {
public:
    int maximumGap(vector<int>& nums) {
        int len = nums.size();
        if(len==0 || len==1)
            return 0;
        int minval = INT_MAX;
        int maxval = INT_MIN;
        vector<int> maxbucket(len-1, INT_MIN);
        vector<int> minbucket(len-1, INT_MAX);
        
        for(auto& n : nums){
            minval = min(minval, n);
            maxval = max(maxval, n);
        }

        int gap = ceil(1.0*(maxval-minval) / (len-1));
        for(auto& n : nums){
            if(n==minval || n==maxval)
                continue;

            int idx = (n-minval)/gap;
            maxbucket[idx] = max(maxbucket[idx], n);
            minbucket[idx] = min(minbucket[idx], n);
        }

        int out = 0;
        int prev = minval;
        for(int i = 0; i < len-1;i++){
            if(minbucket[i]==INT_MAX)
                continue;

            out = max(out, minbucket[i]-prev);
            prev = maxbucket[i];
        }
        out = max(out, maxval-prev);
        return out;
    }
};
```

215题：找到一个数组里面第k个最小的数字，直接用最大堆来做就好，而且最大堆做出来的效果也有O(N*logK)的复杂度，确实也够了。不过还有O(N)复杂度的算法,下面那个代码块就是理论上更优化的方法，用的是类似于快速排序的方法，O（N）的复杂度，最差O(N^2)的复杂度，但是运行结果发现，比优先队列慢很多

```
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int, vector<int>, greater<int>> Q;
        
        for(auto& n : nums){
            Q.push(n);
            if(Q.size()>k){
                Q.pop();
            }
        }
        return Q.top();
    }
};
```

```
class Solution {
public:
    int parti(vector<int>& nums, int left, int right){
        int l = left;
        int r = right+1;
        while(true){
            while(l < right && nums[++l] < nums[left]){
                //l++;
            }
            while(r > left && nums[--r] > nums[left]){
                //r--;
            }
            if(r<=l)
                break;
            swap(nums[l], nums[r]);
        }
        swap(nums[left], nums[r]);
        return r;
    }
    
    int findKthLargest(vector<int>& nums, int K) {
        int k = nums.size()-K;
        int left = 0;
        int right = nums.size()-1;

        while(left < right){
            int mid = parti(nums, left, right);
            if(mid > k){
                right = mid-1;
            }
            else if(mid < k){
                left = mid+1;
            }
            else{
                break;
            }
        }

        return nums[k];
    }
};
```

275题：二分检索，主要是一个right，一个left，然后进行二分操作，难度不大，代码如下

```
class Solution {
public:
    int hIndex(vector<int>& citations) {
        int len   = citations.size();
        int left  = 0;
        int right = len - 1;
        int mid;
        int out   = 0;
        
        if(len == 0)
            return 0;

        while(left <= right){
            mid = (right + left) / 2;
            if(citations[mid] < len - mid){
                out  = max(citations[mid], out);
                left = mid+1;
            }
            else if(citations[mid] > len - mid){
                out = max(len - mid, out);
                right = mid-1;
            }
            else{
                return citations[mid];
            }
        }
        return out;
    }
};
```

406题：排序问题，遇到这种二维数组的一连串问题，首先想到的就应该是排序，这里面也是这样的，排序中，先按照第一个数字（身高）进行排序，然后身高相同的，再按照前面有多少比他高的顺序排序。最后让矮子插队，插入到高个子的前面。因为矮个子插队是不影响高个子的。

```
struct MyComp{
    bool operator() (const vector<int>& left, const vector<int>&right){
        if(left[0] == right[0]){
            return left[1] < right[1];
        }
        return left[0] > right[0];
    }
};
class Solution {
public:
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        MyComp mycomp;
        sort(people.begin(), people.end(), mycomp);
        vector<vector<int>> out;
        
        for(auto& item : people){
            out.insert(out.begin()+item[1],move(item));
        }
        return out;
    }
};


```

435题/452题，也是一个二维数组的排序问题，只不过这次是只对第二个数进行排序，这样就可以来查找最小的非覆盖的数据个数了

```
struct MyComp{
    bool operator()(const vector<int>& left, const vector<int>& right){
        return left[1] < right[1];
    }
};

class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        
        sort(intervals.begin(), intervals.end(), MyComp());
        int count = 0;
        int end = INT_MIN;

        for(auto& iter : intervals){
            if(iter[0] >= end){
                end = iter[1];
                count++;
            }
        }
        return intervals.size()-count;
    }
};
```

442题，查找所有出现个数大于2的数值，并且输出出来，有点像当时链表的思路，但是这个时候，是把所有以这个数为索引的数都取负值，然后出现了两次以后肯定就负负得正重新变成正值了。

```
class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        vector<int> out;
        for(auto& n : nums){
            int absn = abs(n)-1;
            nums[absn] = -nums[absn];
            if(nums[absn]>0){
                out.push_back(absn+1);
            }
        }
        return out;
    }
};
```

581题，其实更像是一个双指针的问题，从左往右遍历一遍，然后再从右往左遍历一遍。代码也比较简单：

```
class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        int left = 0;
        int right= 0;
        bool isleft = false;
        int maxval=INT_MIN;
        
        for(int i = 1; i < nums.size(); i++){
            if(nums[i] < nums[i-1] || nums[i] < maxval){
                if(!isleft){
                    left = i-1;
                    isleft = true;
                }
                right = i;
                maxval = max(maxval, nums[i-1]);
            }

        }
        if(left == right)
            return 0;

        int minval = INT_MAX;
        for(int i = right; i >= 1; i--){
            if(nums[i] < nums[i-1] || nums[i-1] > minval){
                left = min(left, i-1);
                minval = min(minval, nums[i]);
            }
        }
        return right-left+1;
    }
};
```

