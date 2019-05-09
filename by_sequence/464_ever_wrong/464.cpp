class Solution {
private:
    uint8_t m[1<<20] = {0};
    bool DFS(int maxChoosableInteger, int desiredTotal, int k){
        if ( desiredTotal <= 0 || m[k] ) return ( desiredTotal>=0 && m[k]==1 );
        for ( int i=maxChoosableInteger ; i>0 ; i-- ) {
            int this_num = 1<<(i-1);
            if ( !(k & this_num) && !DFS(maxChoosableInteger, desiredTotal-i, k | this_num) ) {
                m[k] = 1;
                return true;
            }    
        }
        m[k] = -1;
        return false;
    }
public:
    bool canIWin(int maxChoosableInteger, int desiredTotal) {
        if ( desiredTotal < 2 ) return true;
        int sum = (maxChoosableInteger * (maxChoosableInteger+1)) >> 1;
        if ( sum < desiredTotal ) return false;
        if ( sum == desiredTotal ) return maxChoosableInteger%2;
        return DFS(maxChoosableInteger, desiredTotal, 0);
    }
};