class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        
        int minval = INT_MIN;
        stack<int> stk;
        
        int len = nums.size();
        if(len <= 2){
            return false;
        }
        for(int i = len-1; i >= 0; i--){
            if(nums[i]<minval){
                return true;
            }
            else{
                while(!stk.empty()&&nums[i]>stk.top()){
                    minval = stk.top();
                    stk.pop();
                }
                stk.push(nums[i]);
            }
        }
        return false;
    }
};