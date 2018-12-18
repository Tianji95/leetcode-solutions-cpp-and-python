class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        int len = nums.size();
        if(len == 0)
            return 0;
        int i = 0;
        int j = 0;
        int sumNow = 0;
        int minLen = INT_MAX;
        
        while(i < len){
            sumNow += nums[i];
            while(sumNow >= s){
                minLen = std::min(minLen, i-j+1);
                sumNow -= nums[j];
                j++;
            }
            i++;
        }
        if(minLen == INT_MAX)
            return 0;
        else
            return minLen;
    }
};