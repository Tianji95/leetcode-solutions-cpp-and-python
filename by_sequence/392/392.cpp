class Solution {
public:
    bool isSubsequence(string s, string t) {
        int sidx = 0;
        int tidx = 0;
        int slen = s.size();
        int tlen = t.size();
        
        if(slen == 0){
            return true;
        }
        if(tlen == 0){
            return false;
        }
        
        while(tidx < tlen){
            if(s[sidx] == t[tidx]){
                sidx++; 
            }
            if(sidx == slen){
                return true;
            }
            
            tidx++;
        }
        return false;
    }
};