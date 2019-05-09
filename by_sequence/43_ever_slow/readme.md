这个题写的太麻烦了，下面是比较简洁的代码，这里面采用的是第i位和第j位乘，得出的结果一定在i+j位

class Solution {
public:
    string multiply(string num1, string num2) {
        int m = num1.size();
        int n = num2.size();
        vector<int> num(m+n,0);
        reverse(num1.begin(),num1.end());
        reverse(num2.begin(),num2.end());
        
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                num[i+j] += (num1[i]-'0')*(num2[j] - '0');
                num[i+j+1] += num[i+j]/10;
                num[i+j] = num[i+j]%10;
            }
        }
        
        reverse(num.begin(),num.end());
        string res = "";
        int i=0;
        for(;i<num.size();i++){
            if(num[i] != 0)
                break;
        }
        for(;i<num.size();i++){
            res+=to_string(num[i]);
        }
        return res == ""?"0":res;
    }
};