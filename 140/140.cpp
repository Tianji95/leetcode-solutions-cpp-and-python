class Solution {
public:
    bool dfs(string& s, int idx, string& outStr, unordered_set<string>& wordSet){
        if(idx == lens){
            out.push_back(outStr.substr(0, outStr.size()-1));
            return true;
        }
        
        for(int i = idx; i < lens; i++){
            string subS = s.substr(idx, i-idx+1);
            if(wordSet.find(subS)!=wordSet.end()){
                subS = subS + " ";
                outStr += subS;
                dfs(s, i+1, outStr, wordSet);
                outStr = outStr.substr(0, outStr.size()- subS.size());
            }
        }
        return false;
    }
    
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        lens = s.size();
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

        if(!dpArray[lens]){
            return out;
        }
        
        
        
        for(int i = 0; i < lens; i++){
            string subS = s.substr(0, i+1);
            if(wordSet.find(subS)!=wordSet.end()){
                subS = subS + " ";
                dfs(s, i+1, subS, wordSet);
            }
        }
        
        
        return out;
        
        
    }
    int lens;
    vector<string> out;
};