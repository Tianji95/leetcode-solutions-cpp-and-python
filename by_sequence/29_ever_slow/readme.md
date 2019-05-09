+ 这道题实在是太慢了，看一下别人的解法，别人首先是判断是否超出范围，如果超出直接返回的
+ 然后，里面的位运算和pow=30值得借鉴一下，这里面pow的作用就是直接将除数放大到最大，通过位运算找到距离被除数最大的数，然后依次递减除以2

    class Solution {
    public:
        int divide(int dividend, int divisor) {
            if (!divisor || (dividend == INT_MIN && divisor == -1))
                return INT_MAX;
            bool isNeg = false;
            long long rem = (long long) dividend;
            long long div = (long long) divisor;
            if(rem < 0) {
                isNeg = !isNeg;
                rem = - rem;
            }
            if(div < 0){
                isNeg = !isNeg;
                div = - div;
            }
            cout << isNeg << endl;
            int pow = 30;
            long long res = 0LL;

            while(rem > 0 && rem >= div){
                while(rem < (div << pow)){
                    pow--;
                }
                res += (1LL<<pow);
                rem -= div<<pow;
            }
            return isNeg ? -res : res;
        }
    };