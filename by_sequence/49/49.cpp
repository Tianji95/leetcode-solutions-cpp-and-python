class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> hashmap;
        vector<vector<string>> out;
        int len = strs.size();
        string tmpS("");
        for(int i = 0 ; i < len; i++){
            tmpS = strs[i];
            std::sort(tmpS.begin(), tmpS.end());
            hashmap[tmpS].push_back(strs[i]);
        }
        for(auto iter : hashmap){
            out.push_back(iter.second);
        }
        return out;
    }
};