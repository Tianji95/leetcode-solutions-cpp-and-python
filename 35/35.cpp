class Solution {
public:
    int findIdx(vector<int>& nums, int target, int left, int right){
        int len = right-left+1;
        if(len == 1){
            return left;
        }
        if(target > nums[right])
            return right;
        if(target < nums[left])
            return left;
        
        else if(len == 2){
            if(target == nums[left])
                return left;
            else
                return right;
        }
        
        int halflen = left + len/2;
        int middle = nums[halflen];
        int middleleft = nums[halflen-1];
        if(abs(middle-target) < abs(middleleft-target)){
            return findIdx(nums, target, halflen, right);
        }
        else if(abs(middle-target) > abs(middleleft-target)){
            return findIdx(nums, target, left, halflen);
        }
        else{
            return halflen;
        }
    }
    
    int searchInsert(vector<int>& nums, int target) {
        int out;
        int len = nums.size();
        if(len == 0)
            return 0;
        if(len == 1){
            if(target > nums[0])
                return 1;
            else 
                return 0;
        }
        if(target > nums[len-1])
            return len;
        if(target < nums[0])
            return 0;
        
        int halflen = len/2;
        int middle = nums[halflen];
        int middleleft = nums[halflen-1];
        if(abs(middle-target) < abs(middleleft-target)){
            out = findIdx(nums, target, len/2, len-1);
        }
        else if(abs(middle-target) > abs(middleleft-target)){
            out = findIdx(nums, target, 0, len/2);
        }
        else{
            out = len/2;
        }
        return out;
    }
};