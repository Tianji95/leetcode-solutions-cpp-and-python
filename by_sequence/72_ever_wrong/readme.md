这道题使用dp来做，二维dp保存两个字符串之间最短的距离，然后计算的时候需要计算三种方法（删除，添加，修改）的最近距离

    class Solution {
    public:
        int minDistance(string word1, string word2) {
            int m = word1.size(),n = word2.size();
            int dp[m+1][n+1];
            for(int i = 0;i<=m;i++) {
                for(int j = 0;j<=n;j++) {
                    if(i == 0)
                        dp[i][j] = j;
                    else if(j == 0) dp[i][j] = i;
                    else if(word1[i-1] == word2[j-1])
                        dp[i][j] = dp[i-1][j-1];
                    else dp[i][j] = min(dp[i][j-1],min(dp[i-1][j],dp[i-1][j-1]))+1;
                }
            }
            return dp[m][n];
            // return max(max(m-dp[m][n],n-dp[m][n]));
        }
    };