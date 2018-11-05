class Solution {
public:
    int myAtoi(string str) {
        long out = 0;
        int strLen = str.size();
        bool isNum = false;
        bool isMinus = false;
        
        for(int i = 0; i < strLen; i++){
            if(isNum && (str[i] > '9' || str[i] < '0')){
                isNum = false;
                break;
            }
            if(out > 2147483647)
                break;
                
            if(str[i] <= '9' && str[i] >= '0'){
                if(!isNum){
                    if(i > 0 && str[i-1] == '-')
                        isMinus = true;
                    isNum = true;
                }
                out = out*10 + str[i] - '0';
            }
            if(str[i] != ' '&& !isNum){
                if(str[i] == '-' || str[i] == '+'){
                    if(i > 0 && str[i-1] != ' ' &&(str[i-1]< '0' || str[i-1] > '9')){
                        return 0;       
                    }
                }
                else{
                    return 0;
                }
                
            }
            if(i > 0 && (str[i] == ' ' && str[i-1] != ' '&&(str[i-1]< '0' || str[i-1] > '9'))){
                return 0;
            }
            
        }
        if(isMinus)
            out = -out;
        
        if(out < -2147483648)
            return -2147483648;
        if(out > 2147483647)
            return 2147483647;
        return out;
        
    }
};