class Solution {                                                                               
public:
    int combinationSum4(vector<int>& nums, int target) {
        
        vector<int> result(target + 1, -1);
        result[0] = 1;
        
        return dpsHandle(nums, result, target);
    }
    
private:
    
    int dpsHandle(vector<int>& nums,
                  vector<int>& result,
                  int target){
        
        if(result[target] != -1){
            return result[target];
        }
        int re = 0;
        for(int i = 0; i < nums.size(); i++){
            
            if(nums[i] > target) continue;
            re += dpsHandle(nums, result, target - nums[i]);
        }
        result[target] = re;
        return re;
        
        return result[target];
    }
};