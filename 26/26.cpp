class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int len = nums.size();
        int out = 0;
        vector<int> outV;
        for(int i = 0; i < len; i++){
            if(i==0){
                out++;
                outV.push_back(nums[i]);
            }
            else if(i!=0 && nums[i]!=nums[i-1]){
                outV.push_back(nums[i]);
                out++;
            }
                
            
        }
        nums = outV;
        return out;
    }
};