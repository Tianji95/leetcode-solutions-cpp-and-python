class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int len = nums.size();
        vector<int> out(len, 1);
        int left = 1;
        int right = 1;
        
        for(int i = 0; i < len; i++){
            out[len-i-1]*= right;
            out[i] *=left;
            left *= nums[i];
            right*= nums[len-i-1];
            
        } 
        return out;
        
    }
};