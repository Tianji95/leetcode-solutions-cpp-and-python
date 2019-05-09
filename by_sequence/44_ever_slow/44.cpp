class Solution {
public:
    bool isMatch(string s, string p) {
        bool dpArray[2000][2000] = {false};
        int sLen = s.size();
        int pLen = p.size();
        bool isMatch;
        
        dpArray[sLen][pLen] = true;
        
        for(int ss = sLen; ss >=0; ss--){
            for(int pp = pLen-1; pp >=0; pp--){
                isMatch = (s[ss] == p[pp] || p[pp] == '?');
                if(p[pp] == '*'){
                    dpArray[ss][pp] = dpArray[ss][pp+1] || dpArray[ss+1][pp] || dpArray[ss+1][pp+1];
                }
                else{
                    dpArray[ss][pp] = (isMatch && dpArray[ss+1][pp+1]);
                }
            }
        }
        return dpArray[0][0];
    }
};