class Solution {
public:
    string shortestPalindrome(string s) {
        int len = s.size();
        if(len == 0 || len == 1)
            return s;
        
        int middle = len / 2;
        int maxIdx = 0;
        bool isdouble = false;
        
        for(int i = middle; i >= 0; i--){
            //判断偶数
            int back = i;
            int font = i-1;
            for(; font >= 0; font--){
                if(s[font] != s[back]){
                    break;
                }
                back++;
            }
            if(font == -1){
                if(i>=maxIdx){
                    maxIdx = i;
                    isdouble = true;
                }
            }
            
            font = i - 1;
            back = i + 1;
            for(; font >= 0; font--){
                if(s[font] != s[back]){
                    break;
                }
                back++;
            }  
            if(font == -1){
                if(i>=maxIdx){
                    maxIdx = i;
                    isdouble = false;
                }
            }
            if(maxIdx != 0){
                break;
            }
        }
        
        std::string out;
        std::string tmp;
        if(!isdouble)
            tmp = s.substr(2*maxIdx+1);
        else
            tmp = s.substr(2*maxIdx);

        std::reverse(tmp.begin(), tmp.end());
        out = tmp + s;
        return out;
    }
};