class Solution {
public:
    int findMin(vector<int>& nums, int leftIdx, int rightIdx){
        int len = rightIdx - leftIdx + 1;
        if(len == 1)
            return leftIdx;
        else if(len == 2){
            if(nums[leftIdx] < nums[rightIdx])
                return leftIdx;
            else
                return rightIdx;
        }
            
        int middle = nums[leftIdx + len/2];
        if(middle > nums[rightIdx])
            return findMin(nums, leftIdx + len/2, rightIdx);
        else
            return findMin(nums, leftIdx, leftIdx + len/2);
    }
    
    int findTarget(vector<int>& nums, int leftIdx, int rightIdx, int target){
        int len = rightIdx - leftIdx + 1;
        if(len == 1){
            if(target == nums[leftIdx])
                return leftIdx;
            else
                return -1;
        }
            
        else if(len == 2){
            if(nums[leftIdx] == target)
                return leftIdx;
            else if(nums[rightIdx] == target)
                return rightIdx;
            else
                return -1;
        }
            
        int middle = nums[leftIdx + len/2];
        if(middle < target)
            return findTarget(nums, leftIdx + len/2, rightIdx, target);
        else
            return findTarget(nums, leftIdx, leftIdx + len/2, target);
    }
    
    int search(vector<int>& nums, int target) {
        int len = nums.size();
        
        if(len == 0)
            return -1;
        if(len == 1){
            if(target == nums[0]){
                return 0;
            }
            else{
                return -1;
            }
        }
        
        int minIdx = findMin(nums, 0, len-1);
        
        if(target<nums[minIdx])
            return -1;
        else if(target>=nums[minIdx]&&target<=nums[len-1]){
            return findTarget(nums, minIdx, len-1, target);
        }
        else if(target>=nums[0]){
            if(minIdx==0)
                return findTarget(nums, minIdx, len-1, target);
            else{
                return findTarget(nums, 0, minIdx-1, target);
            }
        }
        else
            return -1;
    }
};