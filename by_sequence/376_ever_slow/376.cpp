class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        int len   = nums.size();
        vector<int> up(len, 0);
        vector<int> down(len, 0);
        if(len == 0){
            return 0;
        }
        if(len == 1){
            return 1;
        }
        up[0]   = 1;
        down[0] = 1;
        
        for(int i = 1; i < len; i++){
            if(nums[i] > nums[i-1]){
                up[i] = down[i-1] + 1;
                down[i] = down[i-1];
            }
            else if(nums[i] < nums[i-1]){
                up[i] = up[i-1];
                down[i] = up[i-1]+1;
            }
            else{
                down[i] = down[i-1];
                up[i]   = up[i-1];
            }
        }
        
        return max(up[len-1], down[len-1]);
    }
};