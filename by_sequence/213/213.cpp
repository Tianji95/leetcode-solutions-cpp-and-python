class Solution {
public:
    int rob(vector<int>& nums) {
        int len = nums.size();
        if(len == 0)
            return 0;
        if(len == 1)
            return nums[0];
        vector<int> dpArray1(len+1, 0);
        vector<int> dpArray2(len+1, 0);
        dpArray1[0] = 0;
        dpArray1[1] = nums[0];
        
        for(int i = 2; i <= len; i++){
            dpArray1[i] = std::max(dpArray1[i-1], dpArray1[i-2] + nums[i-1]);
            dpArray2[i] = std::max(dpArray2[i-1], dpArray2[i-2] + nums[i-1]);
        }
        return std::max(dpArray1[len-1], dpArray2[len]);
        
    }
};