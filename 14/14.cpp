class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string out("");
        int idxs = 0;
        int len = strs.size();
        if(len == 0)
            return "";
        for(int i = 0; i < len; i++){
            if(strs[i] == "")
                return "";
        }
        
        while(true){
            for(int i = 0; i < len; i++){
                if(idxs >= strs[i].size())
                    return out;
                if(strs[i][idxs] != strs[0][idxs])
                    return out;
            }
            out += strs[0][idxs];
            idxs++;
        }
        
    }
};