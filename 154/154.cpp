class Solution {
public:
    int findMin(vector<int>& nums) {
        int left = 0;
        int right = nums.size()-1;
        if(right == 0)
            return nums[0];
        int middle;
        while(left < right-1){
            middle = left + (right-left)/2;
            if(nums[middle] > nums[right]){
                left = middle;
                continue;
            }
            else if (nums[middle] < nums[right]){
                right = middle;
                continue;
            }
            else{
                right--;
            }
        }
        if(nums[left]  < nums[right]){
            return nums[left];
        }
        else{
            return nums[right];
        }
    }
};