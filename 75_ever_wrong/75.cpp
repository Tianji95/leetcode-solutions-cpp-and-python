class Solution {
public:
    void sortColors(vector<int>& nums) {
        int len = nums.size();
        if(len == 0 || len == 1)
            return;
        int left = 0;
        int middle = 0;
        int right = len - 1;
        
        while(middle <= right){
            if(nums[middle] == 0){
                nums[middle]^=nums[left]^=nums[middle]^=nums[left];
                left++;
                middle = max(left, middle);
            }
            else if(nums[middle] == 1){
                middle++;
            }
            else{
                swap(nums[middle], nums[right]);
                //nums[middle]^=nums[right]^=nums[middle]^=nums[right];
                right--;
            }
        }
    }
};