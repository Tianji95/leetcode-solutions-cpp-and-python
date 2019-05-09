class Solution {
public:
    bool canJump(vector<int>& nums) {
        int  len = nums.size();
        
        if(len == 0)
            return false;
        if(len == 1)
            return true;
        if(nums[0] == 0)
            return false;

        
        int prev = nums[0];
        int maxStep = 0;
        int maxStepIdx = 0;
        int i = 0;
        int j = 0;
        
        while(i < len){
            prev = nums[maxStepIdx] + maxStepIdx;
            maxStep = 0;
            for(j = maxStepIdx+1; j <= prev;j++){
                if(maxStep <= nums[j] + j){
                    maxStep = nums[j] + j;
                    maxStepIdx = j;
                }
            }
            if(j > len-1)
                break;
            if(maxStep - maxStepIdx==0)
                return false;

            i = j;
        }
        return true;
        
    }
};