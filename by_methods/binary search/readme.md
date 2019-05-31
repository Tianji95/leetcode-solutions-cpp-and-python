### 二分检索

二分检索一般用于已经排序的数据当中，一半一半地进行检索

##### leetcode 题目（18 题）

4

29

33

34

81

154

162

230

236

275

287

297

302

410

475

483

644

668

第 4 题，双数组的二分查找算法：

```
class Solution {
public:
    int GetKth(vector<int>& nums1, int a, vector<int>& nums2, int b, int k){
        if(a > nums1.size()-1)
            return nums2[b+k-1];
        if(b > nums2.size()-1)
            return nums1[a+k-1];
        if(k==1)
            return min(nums1[a], nums2[b]);

        int mid1 = INT_MAX;
        int mid2 = INT_MAX;
        if(a+k/2-1 < nums1.size())
            mid1 = nums1[a+k/2-1];
        if(b+k/2-1 < nums2.size())
            mid2 = nums2[b+k/2-1];

        if(mid1 < mid2)
            return GetKth(nums1, a+k/2, nums2, b, k-k/2); //aright + bleft
        else
            return GetKth(nums1, a, nums2, b+k/2, k-k/2); //bright + aright
    }

    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int len1 = nums1.size();
        int len2 = nums2.size();
        if(len1 == 0)
            return (nums2[len2/2]+nums2[(len2-1)/2]) / 2.0;
        if(len2 == 0)
            return (nums1[len1/2]+nums1[(len1-1)/2]) / 2.0;
        return (GetKth(nums1, 0, nums2, 0, (len1+len2+1)>>1) + GetKth(nums1, 0, nums2, 0, (len1+len2+2)>>1))/2.0;
    }
};
```

29 题，又是一个位运算+二分检索的问题， 这里面是把除法的时候，每次都减去一个已经左移过的数字，这样可以增快减少的效率，可以实现数字 logN 的复杂度，这里面还要注意的一点是最外面的跳出条件是 dividend>=divisor 而不是 dividend>=0

```
class Solution {
public:
    int divide(long dividend, long divisor) {
        bool isminus = false;
        if((dividend>0&&divisor<0) ||(dividend<0 && divisor>0)){
            isminus = true;
        }
        if(dividend==INT_MIN){
            if(divisor==1)
                return dividend;
            if(divisor==-1)
                return INT_MAX;
        }
        if(dividend==0)
            return 0;
        dividend = abs(dividend);
        divisor  = abs(divisor);
        long count = 0;
        while(dividend>=divisor){
            long bitcount = 1;
            long nowminus = divisor;
            while(dividend >= (nowminus<<1)){
                nowminus <<= 1;
                bitcount <<= 1;
            }
            count += bitcount;
            dividend = dividend - nowminus;
        }

        if(isminus){
            return -count;
        }
        return count;
    }
};
```

33 题，数组的二分检索，也是比较经典的一类题目，用已经排序，但是经过旋转的数组，来进行检索，是一类题目，只要判断是不是左边的数大于右边的数，就能判断到底有没有在这个数组里面旋转了

```
class Solution {
public:
    int findTarget(vector<int>& nums, int left, int right, int target){
        if(left==right){
            if(nums[left]==target){
                return left;
            }
            return -1;
        }
        if(target==nums[right])
            return right;
        if(target==nums[left])
            return left;

        int mid = (left+right)/2;
        if(target==nums[mid])
            return mid;
        if(nums[left] > nums[right]){
            if(nums[mid] > nums[right]){
                if(target < nums[right] || target > nums[mid])
                    return findTarget(nums, mid+1, right, target);
                else
                    return findTarget(nums, left, mid, target);
            }
            else{
                if(target < nums[right] && nums[mid]<target)
                    return findTarget(nums, mid+1, right, target);
                else
                    return findTarget(nums, left, mid, target);
            }
        }
        else{
            if(target > nums[mid]){
                return findTarget(nums, mid+1, right, target);
            }
            else if(target < nums[mid]){
                return findTarget(nums, left, mid, target);
            }
            else{
                return mid;
            }
        }
    }

    int search(vector<int>& nums, int target) {
        int len = nums.size();
        if(len == 0)
            return -1;
        if(len == 1){
            return nums[0]==target?0:-1;
        }

        return findTarget(nums, 0, len-1, target);
    }
};
```

81 题/跟上面差不多的思路

```
class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int len = nums.size();
        if(len == 0)
            return false;
        if(len == 1)
            return target==nums[0];
        int left = 0;
        int right = len-1;
        while(left <= right){
            int mid = (left+right)/2;
            if(mid>len-1||mid<0)
                break;

            if(nums[mid]==target||nums[left]==target||nums[right]==target)
                return true;

            if(nums[mid]==nums[left]&&nums[left]==nums[right]){
                left++;
                right--;
                continue;
            }
            else if(nums[left] <= nums[mid])
            {
                if( (nums[left]<=target) && (nums[mid] > target) ) right = mid-1;
                else left = mid + 1;
            }
            else
            {
                if((nums[mid] < target) &&  (nums[right] >= target) ) left = mid+1;
                else right = mid-1;
            }

        }
        return false;
    }
};
```

154 题，跟上面差不多的思路

```
class Solution {
public:
    int findMin(vector<int>& nums) {
        int minval = INT_MAX;
        int len = nums.size();
        int left = 0;
        int right = len-1;
        if(len==1)
            return nums[0];

        minval = min(nums[left],nums[right]);
        while(left < right){
            int mid = (left+right)/2;
            minval = min(minval, nums[mid]);
            minval = min(minval, nums[left]);
            minval = min(minval, nums[right]);

            if(nums[mid]==nums[left]&&nums[right]==nums[left]){
                left++;
                right--;
            }
            else if(nums[left]<=nums[mid]){
                left = mid+1;
            }
            else {
                right = mid;
            }
        }
        return minval;
    }
};
```

34 题，也是二分检索问题，这里面因为是找到相等的两个坐标，所以可以分两次循环查找，第一个循环用来找 left，如果数据比 mid 要大，说明当前 mid 还不到要找的距离，left=mid+1，这样当 mid==target 的时候，left 是不会变的，right 一直在往下走。第二次用相同的思路做相反的操作，当 target 比 mid 要小的时候，说明 right 大了，right 应该等于 mid-1，然后如果相等的话就让 left 往上走，这样就能找到正确的 right 了

```
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> out(2,-1);
        int len = nums.size();
        if (len == 0){
            return out;
        }
        int left = 0;
        int right = len-1;

        int mid;
        while(left<right){
            mid = (right+left)/2;
            if(nums[mid]<target){
                left = mid+1;
            }
            else{
                right = mid;
            }
        }
        if(nums[left]!=target){
            return out;
        }
        out[0] = left;

        right = len-1;
        while(left < right){
            mid = (right+left)/2;
            if(nums[mid]>target){
                right = mid;
            }
            else{
                left = mid+1;
            }
        }
        out[1] = left;
        return out;
    }
};
```

162 题，找到比两遍数字都大的数字 idx，其实跟上面的思路差不多

```
class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int len = nums.size();
        if(len == 0 || len == 1)
            return 0;

        int left = 0;
        int right = len-1;
        int middle;
        while(left < right){
            middle = (right + left) / 2;
            if(nums[middle] < nums[middle+1]){
                left = middle+1;
            }
            else{
                right = middle;
            }
        }
        return left;
    }

};
```

230 题，是一个二叉搜索树的二分检索题目，只要会遍历树就比较简单

```
class Solution {
public:
    int out;
    int countNode(TreeNode* node, int k){
        int rightcount = 0;
        int leftcount  = 0;
        if(!node)
            return 0;

        leftcount = countNode(node->left, k);
        if(leftcount > k)
            return leftcount;
        if(k==leftcount+1){
            out = node->val;
            return k+1;
        }
        rightcount = countNode(node->right, k-leftcount-1);
        return leftcount+rightcount+1;
    }

    int kthSmallest(TreeNode* root, int k) {
        countNode(root, k);
        return out;
    }
};
```
