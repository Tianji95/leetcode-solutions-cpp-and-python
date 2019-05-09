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