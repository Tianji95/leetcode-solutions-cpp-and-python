class Solution {
public:
    
    string minWindow(string s, string t) {
        int count = t.size(), m = s.size(), start = 0, maxLen = INT_MAX, result = 0;
        vector<int> dp(256, 0);
        for(char c : t)
            dp[c]++;
        for(int i = 0; i < m; i++) {
            if(dp[s[i]]-- > 0)
                count--;
            while(count == 0) {
                if(i-start+1 < maxLen) {
                    result = start;
                    maxLen = i-start+1;
                }
                if(dp[s[start++]]++ == 0)
                    count++;
            }
        }
        return maxLen == INT_MAX ? "" : s.substr(result, maxLen);
    }
};