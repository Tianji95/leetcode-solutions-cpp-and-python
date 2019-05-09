class Solution {
public:
    bool isValid(string s) {
        if(s == "")
            return true;
        stack<char> tmpStack;
        
        vector<char> left = {'(', '{', '['};
        vector<char> right = {')', '}', ']'};
        map<char, char> charMap = {
            {'(', ')'},
            {'{', '}'},
            {'[', ']'}
        };
        
        int len = s.size();
        for(int i = 0; i < len; i++){
            //左括号
            auto findIter = find(left.begin(), left.end(), s[i]);
            if(findIter != left.end()){
                tmpStack.push(s[i]);
            }
            //右括号
            else{
                if(tmpStack.empty())
                    return false;
                char outChar = tmpStack.top();
                tmpStack.pop();
                if(s[i] != charMap[outChar])
                    return false;
            }
        }
        if(tmpStack.empty())
            return true;
        return false;
    }
};