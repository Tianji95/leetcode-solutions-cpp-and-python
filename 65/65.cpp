class Solution {
public:
    enum STATE{
        INIT,
        ISDECIMAL,
        DECIMAL_NUM,
        DECIMAL_INT_NUM,
        ISE,
        E_NUM,
        E_POSI_NEGA,
        E_POSI_NEGA_NUM,
        POSI_NEGA,
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
        if(len == 1){
            if(s[0] >= '0' && s[0] <= '9')
                return true;
            else
                return false;
        }
        
        for(int i = 0; i < len; i++){
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
                else if(nowState == E_POSI_NEGA){
                    nowState = E_POSI_NEGA_NUM;
                }
                
                else if(nowState == POSI_NEGA){
                    nowState = POSI_NEGA_NUM;
                }
            }
            else if(s[i] == 'e'){
                if(nowState == INIT || nowState == ISE || nowState == E_NUM || nowState == ISDECIMAL || nowState == E_POSI_NEGA_NUM || nowState == E_POSI_NEGA || nowState == POSI_NEGA)
                    return false;
                else 
                    nowState = ISE;
            }
            else if(s[i] == '.'){
                if(nowState == ISDECIMAL || nowState == DECIMAL_NUM || nowState == ISE || nowState == E_NUM || nowState == E_POSI_NEGA_NUM || nowState == E_POSI_NEGA || nowState == DECIMAL_INT_NUM)
                    return false;
                else if(nowState == NUM || nowState == POSI_NEGA_NUM){
                    nowState = DECIMAL_INT_NUM;
                }
                else
                    nowState = ISDECIMAL;
            }
            else if(s[i] == '+' || s[i]== '-'){
                if(nowState == INIT){
                    nowState = POSI_NEGA;
                }
                else if(nowState == ISE){
                    nowState = E_POSI_NEGA;
                }
                else
                    return false;
            }
            else{
                return false;
            }
        }
        if(nowState == ISE || nowState == E_POSI_NEGA || nowState == ISDECIMAL){
            return false;
        }
            
        
        return true;
    }
};