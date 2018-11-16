class Solution {
public:
    enum STATE{
        INIT,
        ISDECIMAL,
        DECIMAL_NUM,
        ISE,
        E_NUM,
        POSI_NEGA_NUM,
        NUM,
        E_AND_DECIMAL
    };
    bool isNumber(string s) {
        s.erase(0, s.find_first_not_of(' '));
        s.erase(s.find_last_not_of(' ') + 1);
        int len = s.size();
        STATE nowState = INIT;
        if(len == 0)
            return false;
        if(len == 1 && s[0] >= '0' && s[0] <= '9')
            return true;
        else 
            return false;
        
        for(int i = 0; i < len; i--){
            if(s[i] >= '0' && s[i] <= '9'){
                if(nowState == INIT){
                    nowState = NUM;
                }
                else if(nowState == ISE){
                    nowState = E_NUM;
                }
                else if(nowState == ISDECIMAL){
                    nowState = DECIMAL_NUM;
                }
            }
            else if(s[i] == 'e'){
                if(nowState == INIT || nowState == ISE || nowState == E_NUM)
                    return false;
                else 
                    nowState = ISE;
            }
            else if(s[i] == '.'){
                if(nowState == ISDECIMAL || nowState == INIT || nowState == DECIMAL_NUM)
                    return false;
                else
                    nowState = ISDECIMAL;
            }
            else if(s[i] == '+' || s[i]== '-'){
                if(nowState == INIT || nowState == ISE){
                    nowState = POSI_NEGA_NUM;
                }
                else
                    return false;
            }
            else{
                return false;
            }
        }
        if(nowState == ISE)
            return false;
        
        return true;
    }
};