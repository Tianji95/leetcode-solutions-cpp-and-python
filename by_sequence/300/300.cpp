class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int len = nums.size();
        vector<int> dpArray(len , 1);
        vector<int> last;
        if(len == 0)
            return 0;
        if(len == 1)
            return 1;
        
        dpArray[0] = 1;
        last.push_back(nums[0]);
        for(int i = 1; i < len; i++){
            int maxcount = 1;
            for(int j = 0; j < last.size(); j++){
                if(nums[j] < nums[i] && dpArray[j]+1 > maxcount){
                    maxcount = dpArray[j] + 1;
                }
            }
            last.push_back(nums[i]);
            dpArray[i] = maxcount;
        }
        int out = 0;
        for(int i = 0; i < len; i++){
            if(dpArray[i] > out)
                out = dpArray[i];
        }
        
        return out;
    }
};