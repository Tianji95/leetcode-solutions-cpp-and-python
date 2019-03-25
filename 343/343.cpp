class Solution {
public:
    int integerBreak(int n) {
        vector<int> dp(n+1, 0);
        dp[0] = 0;
        dp[1] = 1;
        dp[2] = 1;
        
        for(int i = 3; i <= n; i++){
            for(int j = 2; j < i; j++){
                int maxleft  = max(dp[j], j);
                int maxright = max(dp[i-j], i-j);
                dp[i] = max(dp[i], maxleft*maxright);
            }
        }
        return dp[n];
    }
};