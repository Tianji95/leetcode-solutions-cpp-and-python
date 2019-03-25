class Solution {
public:
    int getMoneyAmount(int n) {
        int out = 0;
        vector<vector<int>> dp(n+1, vector<int>(n+1, 0));
        
        //length
        for(int i = 2; i <= n; i++){
            //start
            for(int j = 1; j <= n - (i-1);  j++){
                dp[j][j+(i-1)] = INT_MAX;
                for(int k = j; k < j+i-1; k++){
                    int costForThisGuess;
                    if (k == n) {
                        costForThisGuess = dp[j][k - 1] + k;
                    } else {
                        costForThisGuess = k + max(dp[j][k - 1], dp[k + 1][j + (i - 1)]);
                    }
                    dp[j][j+i-1] = min(dp[j][j+i-1], costForThisGuess);
                }
            }
        }
        
        return dp[1][n];
    }
};