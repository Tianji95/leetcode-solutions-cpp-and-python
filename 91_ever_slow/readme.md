用递归还是太慢了，应该用dp的

    class Solution {
    public:
        int numDecodings(string s) {
            const int n = s.size();
            vector<int> dp(n, 0);
            if (n == 0) return 0;
            if (s[0] == '0') return 0;
            
            dp[0] = 1;
            for (int i = 1; i < n; ++i) {
                int code = atoi(s.substr(i - 1, 2).c_str());
                if ('1' <= s[i] && s[i] <= '9')
                    dp[i] += dp[i - 1];
                if (10 <= code && code <= 26)
                    dp[i] += (i >= 2) ? dp[i - 2] : 1;
            }
            return dp[n - 1];
        }
    };