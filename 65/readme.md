我的代码用了状态机，不够清晰也不够快，下面是一个比较快的代码
    class Solution {
    public:
        bool isNumber(string s) {
            const char *p = s.c_str(), *q;

            while (isspace(*p))
                ++p;
            if (*p == 0)
                return false;

            if (*p == '-' || *p == '+')
                ++p;

            q = p;
            while (isdigit(*p))
                ++p;

            if (*p == '.') {
                /* .NUMBER */
                if (p == q && !isdigit(*(p+1)))
                    return false;
                ++p;

                while (isdigit(*p))
                    ++p;
            }

            if (*p == 'e' || *p == 'E') {
                /* e and nothing before */
                if (p == q)
                    return false;

                ++p;
                if (*p == '+' || *p == '-')
                    ++p;

                if (!isdigit(*p))
                    return false;
                while (isdigit(*p))
                    ++p;
            }

            while (isspace(*p))
                ++p;
            if (*p != 0)
                return false;

            return true;

        }
    };

下面是一串相对比较好理解的代码：[来源](https://leetcode.com/problems/valid-number/discuss/23725/C++-My-thought-with-DFA)
    
    class Solution {
    public:
        bool isNumber(string str) {
            int state=0, flag=0; // flag to judge the special case "."
            while(str[0]==' ')  str.erase(0,1);//delete the  prefix whitespace 
            while(str[str.length()-1]==' ') str.erase(str.length()-1, 1);//delete the suffix whitespace
            for(int i=0; i<str.length(); i++){
                if('0'<=str[i] && str[i]<='9'){
                    flag=1;
                    if(state<=2) state=2;
                    else state=(state<=5)?5:7;
                }
                else if('+'==str[i] || '-'==str[i]){
                    if(state==0 || state==3) state++;
                    else return false;
                }
                else if('.'==str[i]){
                    if(state<=2) state=6;
                    else return false;
                }
                else if('e'==str[i]){
                    if(flag&&(state==2 || state==6 || state==7)) state=3;
                    else return false;
                }
                else return false;
            }
            return (state==2 || state==5 || (flag&&state==6) || state==7);
        }
    };