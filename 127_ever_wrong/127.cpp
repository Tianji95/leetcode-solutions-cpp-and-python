class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        if (wordList.empty()) return 0;
        unordered_set<string> dict(wordList.begin(), wordList.end());
        if (!dict.count(endWord)) return 0;
        vector<string> check;
        unordered_set<string> lookup;
        check.emplace_back(beginWord);
        lookup.emplace(endWord);
        int res = 1;
        vector<string> tmp;
        while (!check.empty()) {
            ++res;
            for (auto& s:check) dict.erase(s);
            tmp.clear();
            for (auto& s:check) {
                string next = s;
                const int n = next.length();
                for (int i=0;i<n;++i) {
                    char t = next[i];
                    for (char ch='a';ch<='z';++ch) {
                        if (ch==t) continue;
                        next[i] = ch;
                        if (!dict.count(next)) continue;
                        if (lookup.count(next)) return res;
                        tmp.emplace_back(next);
                    }
                    next[i] = t;
                }
            }
            if (tmp.size()>lookup.size()) {
                check = vector<string>(lookup.begin(), lookup.end());
                lookup = unordered_set<string>(tmp.begin(), tmp.end());                
            }
            else {
                check = tmp;
            }
        }
        return 0;        
    }
};