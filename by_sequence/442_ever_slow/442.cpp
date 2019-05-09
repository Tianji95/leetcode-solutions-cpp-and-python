class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        vector<int> out;
        int len = nums.size();
        if(len == 0 || len == 1)
            return out;
        
        for(int i = 0; i < len; i++){
            nums[abs(nums[i])-1] = -nums[abs(nums[i])-1];
            if(nums[abs(nums[i])-1]>0){
                out.push_back(abs(nums[i]));
            }
        }
        return out;
        
    }
};