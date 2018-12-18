class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int len = nums.size();
         
        if(len == 1)
            return nums[0];
        int maxNum = nums[0];
        int minNum = nums[0];
        int out = nums[0];
        for(int i = 1; i < len; i++){
            if(nums[i] < 0){
                std::swap(maxNum, minNum);
            }
            maxNum = std::max(maxNum*nums[i], nums[i]);
            minNum = std::min(minNum*nums[i], nums[i]);
            out = std::max(out, maxNum);
        }
        return out;
        
    }
};