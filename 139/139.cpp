class Solution {
public:  
    bool wordBreak(string s, vector<string>& wordDict) {
        int lens = s.size();
        int lenw = wordDict.size();
        unordered_set<string> wordSet(wordDict.begin(), wordDict.end());
        vector<bool> dpArray(lens+1, false);
        dpArray[0] = true;
        
        for(int i = 1; i <= lens; i++){
            for(int j = 0; j < i; j++){
                string subS = s.substr(j, i-j);
                if(dpArray[j] && wordSet.find(subS)!=wordSet.end()){
                    dpArray[i] = true;
                    break;
                }
            }
        }

        return dpArray[lens];
        
    }
};