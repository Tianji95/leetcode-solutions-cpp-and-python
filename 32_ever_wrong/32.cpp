class Solution {
public:
    int longestValidParentheses(string s) {
        int sLen = s.size();
        int maxout = 0;
        int tmpout = 0;
        stack<int> stk;
        
        stk.push(-1);
        for(int i = 0; i < sLen; i++){
            if(s[i] == ')'){
                stk.pop();
                if(stk.empty()){
                    stk.push(i);
                }
                else{
                    maxout = max(maxout, i - stk.top());
                }
            }
            else{
                stk.push(i);
            }
        }

        

        return maxout;
    }
};