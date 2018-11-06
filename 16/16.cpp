class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int out = 0;
        int len = nums.size();
        int minValue;
        int returnVal;
        std::sort(nums.begin(), nums.end());
        
        minValue = abs(nums[0] + nums[1]+nums[2]- target);
        returnVal = nums[0] + nums[1]+nums[2];
        
        for(int i = 0; i < len-2; i++){
            int left = i + 1;
            int right = len - 1;
            
            while(left < right){
                int thisValue = nums[left] + nums[right] + nums[i] - target;
                if(abs(thisValue) < minValue){
                    returnVal = nums[left] + nums[right] + nums[i];
                    minValue = abs(thisValue);
                }
                    
                if(thisValue < 0)
                    left++;
                else if(thisValue > 0)
                    right--;
                else
                    return nums[left] + nums[right] + nums[i];
            }
        }
        return returnVal;
        
    }
};