class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        std::stack<int> numStack;
        int len = tokens.size();
        int out = 0;
        
        for(int i = 0; i < len; i++){
            if(tokens[i]=="+"){
                int rightNum = numStack.top();
                numStack.pop();
                int leftNum  = numStack.top();
                numStack.pop();
                out = rightNum + leftNum;
                numStack.push(out);
            }
            else if (tokens[i] == "-"){
                int rightNum = numStack.top();
                numStack.pop();
                int leftNum  = numStack.top();
                numStack.pop();
                out =  leftNum - rightNum;
                numStack.push(out);  
            }
            else if(tokens[i] == "*"){
                int rightNum = numStack.top();
                numStack.pop();
                int leftNum  = numStack.top();
                numStack.pop();
                out =  leftNum * rightNum;
                numStack.push(out);
            }
            else if(tokens[i] == "/"){
                int rightNum = numStack.top();
                numStack.pop();
                int leftNum  = numStack.top();
                numStack.pop();
                out =  leftNum / rightNum;
                numStack.push(out);
            }
            else{
                numStack.push(std::stoi(tokens[i]));
            }
        }
        return numStack.top();
    }
};