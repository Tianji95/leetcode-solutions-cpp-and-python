class Solution {
public:
    int minDistance(string word1, string word2) {
        int m = word1.size();
        int n = word2.size();
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
        for(int i = 0; i <= m; i++)
            dp[i][0] = i;
        for(int j = 0; j <= n; j++)
            dp[0][j] = j;
        for(int i = 1; i <= m; i++){
            for(int j = 1; j <= n; j++){
                if(word1[i - 1] == word2[j - 1]){
                    dp[i][j] = dp[i - 1][j - 1];
                }
                else{
                    int opt1 = dp[i - 1][j]; // delete
                    int opt2 = dp[i][j - 1]; // insert
                    int opt3 = dp[i - 1][j - 1]; // replace
                    dp[i][j] = min(opt1, min(opt2, opt3)) + 1;
                }
            }
        }
        return dp[m][n];
    }
};