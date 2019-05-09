class Solution {
public:
    string removeKdigits(string num, int k) {
        int len = num.size();
        
        stack<char> stk;
        int i = 0;
        
        while(i < len){
            while(stk.size() != 0 && k > 0 && num[i] < stk.top()){
                stk.pop();
                k--;
            }
            stk.push(num[i]);
            i++;
            
        }
        while(k > 0){
            stk.pop();
            k--;
        }
        string out;
        len = stk.size();

        for(int i = 0; i < len; i++){
            out = stk.top()+out;
            stk.pop();
        }
        len = out.size();
        i = 0;
        for(; i < len; i++){
            if(out[i]!='0'){
                break;
            }
        }
        out = out.substr(i);
        if(out.size()==0){
            return "0";
        }
        return out;
    }
};