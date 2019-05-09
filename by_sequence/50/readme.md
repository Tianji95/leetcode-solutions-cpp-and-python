说实话这个代码写的麻烦了，下面有一个更好的代码：
    
    class Solution {
    public:
        double myPow(double x, int n) {
            if(n==0)
                return 1;
            double temp=myPow(x,n/2);
            if(n%2==0)
                return temp*temp;
            else if(n>0)
                return temp*temp*x;
            else
                return (temp*temp)/(x*1.0);
        }
    };