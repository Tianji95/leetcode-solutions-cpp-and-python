class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int allsum = 0;
        
        for(auto each : nums)
        {
            allsum += each;
        }
        if(allsum%2==1){
            return false;
        }
        int aim = allsum / 2;
        vector<bool> dp(aim+1, false);
        
        for(auto each : nums)
        {
            for(int i = aim-each; i >= 0; i--){
                if(dp[i]){
                    if(each+i == aim){
                        return true;
                    }
                    dp[each+i] = true;
                }
            }
            if(each > aim){
                continue;
            }
            dp[each] = true;
        }
        return dp[aim];
    }
};