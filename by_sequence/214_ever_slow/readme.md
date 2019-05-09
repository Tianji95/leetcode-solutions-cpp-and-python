有必要研究一下KMP的方法

    class Solution {
    public:
        string shortestPalindrome(string s) {
            vector<int> kmp((s.length() + 1) / 2);
            for (int i = 0, cur = -1; i < kmp.size(); ++i) {
                if (cur >= 0 && s[i] == s[cur]) {
                    kmp[i] = kmp[cur++];
                } else {
                    kmp[i] = cur;
                    while (cur >= 0 && s[i] != s[cur]) cur = kmp[cur];
                    ++cur;
                }
            }
            int l = 0, r = s.length();
            for (; --r > l;) {
                while (l >= 0 && s[r] != s[l]) l = kmp[l];
                ++l;
            }
            string prefix = s.substr(l + r + 1);
            std::reverse(prefix.begin(), prefix.end());
            return prefix + s;
        }
    };