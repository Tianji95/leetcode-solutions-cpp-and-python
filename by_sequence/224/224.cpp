class Solution {
public:
    int calculate(string s) {
        int len = s.size();
        std::stack<char> opS;
        std::stack<int> nbS;
        int num = 0;
        if(len == 0)
            return 0;
        if(len == 1)
            return s[0]-'0';
        
        for(int i = 0; i < len; i++){
            if(s[i] == '(' || s[i] == '+' || s[i] == '-'){
                opS.push(s[i]);
            }
            else if(s[i] >= '0' && s[i] <= '9'){
                num = num*10 + s[i] - '0';
                while(i+1<len && s[i+1] >='0' && s[i+1]<= '9'){
                    num = num*10 + s[i+1] - '0';
                    i++;
                }
                if(opS.size()==0){
                    nbS.push(num);
                    num = 0;
                    continue;
                }
                char O = opS.top();
                if(O == '('){
                    nbS.push(num);
                    num = 0;
                    continue;
                }
                opS.pop();
                int left = nbS.top();
                nbS.pop();
                int right = num;
                if(O == '+'){
                    nbS.push(left+right);
                }
                else if(O=='-'){
                    nbS.push(left-right);
                }
                
                num = 0;
            }
            else if(s[i] == ')'){
                char O = opS.top();
                opS.pop();
                while(O!='('){
                    int right = nbS.top();
                    nbS.pop();
                    int left = nbS.top();
                    nbS.pop(); 
                    if(O == '+'){
                        nbS.push(left+right);
                    }
                    else if(O=='-'){
                        nbS.push(left-right);
                    }
                    O = opS.top();
                    opS.pop();
                }
                if(opS.size() > 0){
                    O = opS.top();
                    if(O == '+'){
                        int right = nbS.top();
                        nbS.pop();
                        int left = nbS.top();
                        nbS.pop(); 
                        nbS.push(left+right);
                        opS.pop();
                    }
                    else if(O == '-'){
                        int right = nbS.top();
                        nbS.pop();
                        int left = nbS.top();
                        nbS.pop(); 
                        nbS.push(left-right);
                        opS.pop();
                    }
                }
            }
        }
        while(opS.size()){
            char O = opS.top();
            opS.pop();
            int right = nbS.top();
            nbS.pop();
            int left = nbS.top();
            nbS.pop();
            if(O == '+'){
                nbS.push(left+right);
            }
            else if(O=='-'){
                nbS.push(left-right);
            }
        }
        return nbS.top();
        
    }
};