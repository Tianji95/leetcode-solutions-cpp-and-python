class Solution {
public:
    int jump(vector<int>& nums) {
        int len = nums.size();
        
        if(len == 0||len == 1)
            return 0;
        
        if(nums[0] > len)
            return 1;
        
        int out = 0;
        int i   = 0;
        int startNum = 0;
        int maxNum = 0;
        int maxNumIdx = 0;
        bool isEnd = false;
        while(i < len){
            startNum = nums[i];
            maxNum = 0;
            
            for(int j = i+1; j < i + startNum + 1; j++){
                if(maxNum <= nums[j] + j){
                    maxNum = nums[j] + j;
                    maxNumIdx = j;
                }
                if(j == len-1){
                    isEnd = true;
                    break;
                }
            }
            i = maxNumIdx;
            out++;
            if(isEnd)
                break;
        }
        return out;
        
    }
};