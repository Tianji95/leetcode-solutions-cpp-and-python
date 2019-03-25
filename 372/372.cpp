class Solution {
public:
    int superPow(int a, vector<int>& b) {
        int now = 1;
        int len = b.size();
        int out = 1;
        
        vector<long long> dp(len+1, 1);
        
        dp[0] = a;
        for(int i = 1; i < len; i++){
            for(int j = 0; j < 10; j++){
                dp[i] = dp[i]*dp[i-1]%1337;
            }
        }
        for(int i = 0; i < len; i++){
            int times = b.back();
            for(int j = 0; j < times; j++){
                out = out*dp[i]%1337;
            }
            b.pop_back();
        }
        return out;
    }
};