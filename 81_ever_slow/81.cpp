class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int len = nums.size();
        if(len == 0)
            return false;
        
        for(int i = 0; i< len; i++){
            if(nums[i] == target)
                return true;
        }
        return false;
    }
};

class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int len = nums.size();
        if(len == 0)
            return false;
        int left = 0;
        int right = len - 1;
        int middle;
        
        while(left < right - 1){
            middle = (left + right) / 2;
            if(nums[middle] == target || nums[left] == target || nums[right] == target)
                return true;
            if(nums[middle] == nums[left] && nums[left] == nums[right])
                break;
            if(nums[middle] > nums[right]){
                //说明中间点在右边这段这里面
                if(target > nums[middle] || target <=nums[right]){
                    left = middle;
                    continue;
                }
                
            }
            else{
                //说明右边这一段已经是排序过的了
                if(target > nums[middle] && target <= nums[right]){
                    left = middle;
                    continue;
                }
            }
            
            if(nums[left] > nums[middle]){
                //说明中间点在这里面
                if(target >=nums[left] || target < nums[middle]){
                    right = middle;
                    continue;
                }
                else
                    return false;
            }
            else{
                if(target>=nums[left] && target<=nums[middle]){
                    right = middle;
                    continue;
                }
                else
                    return false;
            }
        }
        for(int i = left; i <= right; i++){
            if(nums[i] == target)
                return true;
        }
        return false;
        
    }
};