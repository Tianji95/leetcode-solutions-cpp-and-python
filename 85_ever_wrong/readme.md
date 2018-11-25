    
    class Solution {
    public:
        int maximalRectangle(vector<vector<char>>& matrix) {
            int maxR = 0;
            int rowlen = matrix.size();
            if(rowlen == 0)
                return 0;
            int collen = matrix[0].size();
            if(collen == 0)
                return 0;
            
            vector<int> hIdx(collen + 1, 0); // 保存这列最大长度
            
            for(int r = 0; r < rowlen; r++){
                std::stack<int> stk;
                for(int c = 0; c < collen + 1; c++){
                    if(c < collen){
                        if(matrix[r][c] == '1'){
                            hIdx[c] += 1;
                        }
                        else{
                            hIdx[c] = 0;
                        }
                    }
                    
                    if (stk.empty() || hIdx[stk.top()] <= hIdx[c])
                        stk.push(c);
                    else{
                        while(!stk.empty() && hIdx[c] < hIdx[stk.top()]){
                            int top = stk.top();
                            stk.pop();
                            int area = hIdx[top] * (stk.empty()?c:(c - stk.top() - 1));
                            if(area > maxR)
                                maxR = area;
                        }
                        stk.push(c);
                    }
                }
            }
            return maxR;
        }
    };