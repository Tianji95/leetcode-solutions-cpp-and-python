class Solution {
public:
    int reverse(int x) {
        if (x == 0)
            return 0;
        
        bool isMinus = false;
        if(x < 0){
            isMinus = true;
            x = -x;
        }
        int outi[30];
        int idx = 0;
        while(x){
            outi[idx++] = x % 10;
            x = x / 10;
        }
        
        long outval = 0;
        for(int i = 0; i < idx; i++){
            outval = outval*10 + outi[i];
        }    
        if(isMinus){
            outval = -outval;
        }
        if(outval > 2147483647 || outval < -2147483648)
            return 0;
        return outval;        
    }
};