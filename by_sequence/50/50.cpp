class Solution {
public:
    double FLT_MAX      = 3.402823e+38;
    double myPow(double x, int n) {
        bool isNeg = false;
        bool isout = false;
        if(n == -2147483648){
            n = 2147483647;
            isout = true;
        }
        if(n < 0){
            isNeg = true;
            n = -n;
        }
        if(n == 0)
            return 1;
        if(n == 1){
            if(isNeg)
                return 1/ x;
            else
                return x;
        }   
        if(x == 1)
            return 1;
        
        if(x == -1){
            int isDouble = n % 2;
            if(isDouble == 1&&!isout)
                return -1;
            return 1;
        }
        
        double out = 1;
        
        int maxMul = 1;
        
        out = x;
        while(maxMul < n ){
            maxMul = maxMul + maxMul;
            if(maxMul < n){
                out = out * out;
                if(out==0)
                    return out;
                if(out > FLT_MAX)
                    return 0;
            }
        }
        maxMul /=2;
        
        for(int i = 0; i < n - maxMul; i++){
            out *= x;
        }
        if(isNeg){
            if(isout)
                out = 1/ out / x;
            else
                out = 1/ out;
        }
            
        return out;
    }
};