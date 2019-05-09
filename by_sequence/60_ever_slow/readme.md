这道题我用了上次那个不要脸的解法，相当于没有解出来，正常的解法应该是用swap不断的交换后面几位然后进行计算。
下面是一个比较快并且比较巧妙的解法。因为我们只需要知道第几位这个量，所以对于4位数字的排列组合，1开头有3！种情况，2开头有3！种情况，3开头有3！种情况，4开头有3！种情况，我们只需要让k/3！，就能够拿到第一位的数字是哪个。
然后继续处理后面的那些    

    class Solution {
    public:
        string getPermutation(int n, int k) {
            int d = n-1;
            int t = k;
            list<char> nums;
            string result = "";
            for(int i = 1; i <= n; i++){
                nums.push_back(i+48);
            }
            while(t!=0){
                int jd = jiecheng(d);
                int position = ceil((double)t/jd);
                auto it = nums.begin();
                for(int i = 0; i< position-1 && it != nums.end(); i++, it++);
                result += *it;
                nums.remove(*it);
                //cout<<t<<" "<<jd<<" "<<position<<" "<<t<<endl;
                t = t%jd; 
                d--;
            }
            nums.reverse();
            for(auto it = nums.begin(); it != nums.end(); it++){
                result += *it;
            }
            return result;
        }
        int jiecheng(int n){
            if(n == 0)return 1;
            int sum = n;
            while(--n > 0) sum*=n;
            return sum;
        }
    };