class Solution {
public:
    void decodeIter(string& s, int idx){
        if(idx >= len - 1){
            count++;
            return ;
        }
            
        
        if(s[idx] >= '1' && s[idx] <= '9' && s[idx+1]!='0')
            decodeIter(s, idx+1);
        
        if(s[idx] == '1' || (s[idx]=='2' && s[idx+1]<='6' && s[idx+1] >='0')){
            if(idx+2 < len && s[idx+2] == '0'){
                
            }
            else{
                decodeIter(s, idx+2);
            }
        }
            
    }
    
    int numDecodings(string s) {
        count = 0;
        if(s.size() == 0 || s == "0")
            return 0;
        
        len = s.size();
        decodeIter(s, 0);
        return count;
    }
    
    int len;
    int count;
};