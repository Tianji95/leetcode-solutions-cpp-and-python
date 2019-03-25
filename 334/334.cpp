class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int len = nums.size();

        int leftValue = INT_MAX;
        int rightValue = INT_MAX;
        
        for(int i = 0; i < len; i++){
            if(nums[i] <= leftValue){
                leftValue = nums[i];
            }
            else if(nums[i] <= rightValue){
                rightValue = nums[i];
            }
            else{
                return true;
            }
        }
        return false;
        
    }
};