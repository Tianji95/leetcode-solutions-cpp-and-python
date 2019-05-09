class Solution {
public:
    int divide(int dividend, int divisor) {
        bool isNegvidend = false;
        bool isNegvisor  = false;
        long dend = dividend;
        long disor = divisor;
        
        if(dividend < 0){
            isNegvidend  = true;
            dend = -dend;
        }
            
        
        if(divisor < 0){
            disor = -disor;
            isNegvisor   = true;
        }
        
        long out = 0;
        if(disor == 1)
            out = dend;
        else{
            while(dend >= disor){
                dend -=disor;
                out++;
            }
        }

        if((isNegvisor&&!isNegvidend)||(!isNegvisor&&isNegvidend))
            out = -out;
        if(out < -2147483648 || out > 2147483647)
            return 2147483647;
        return out;
        
    }
};