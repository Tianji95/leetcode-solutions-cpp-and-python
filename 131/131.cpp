class Solution {
public:
    bool isPalidrome(string s){
        int len = s.size();
        if(len == 1 || len == 0)
            return true;
        
        int font = 0;
        int back = len-1;
        while(font < back){
            if(s[font] != s[back])
                return false;
            font++;
            back--;
        }
        return true;
    }
    
    void partitionString(string s, vector<string>& now){
        int len = s.size();
        if(len == 0){
            out.push_back(now);
            return ;
        }
            
        for(int i = 1; i <= len; i++){
            string tmpS = s.substr(0, i);
            if(isPalidrome(tmpS)){
                now.push_back(tmpS);
                partitionString(s.substr(i), now);
                now.pop_back();
            }
                
        }
        
    }
    
    vector<vector<string>> partition(string s) {
        
        if(s.size() == 0)
            return out;
        
        vector<string> tmp;
        partitionString(s, tmp);
        
        return out;
    }
    vector<vector<string>> out;
    
    
};