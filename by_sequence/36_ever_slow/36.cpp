class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        int row = 0;
        int col = 0;
        
        bool isNum[10];
        int nowIdx = 0;
        
        for(row = 0; row < 9; row++){
            memset(isNum, 0, sizeof(isNum));
            for(col = 0; col < 9; col++){
                if(board[row][col]!='.'){
                    nowIdx = board[row][col] - '0';
                    if(isNum[nowIdx])
                        return false;
                    isNum[nowIdx] = true;
                }
            }
        }
        
        for(col = 0; col < 9; col++){
            memset(isNum, 0, sizeof(isNum));
            for(row = 0; row < 9; row++){
                if(board[row][col]!='.'){
                    nowIdx = board[row][col] - '0';
                    if(isNum[nowIdx])
                        return false;
                    isNum[nowIdx] = true;
                }
            }
        }
        
        int blockrow = 0;
        int blockcol = 0;
        
        for(blockrow = 0; blockrow < 3; blockrow++){
            for(blockcol = 0; blockcol < 3; blockcol++){
                memset(isNum, 0, sizeof(isNum));
                for(row = blockrow * 3; row < blockrow*3+3; row++){
                    for(col = blockcol * 3; col < blockcol*3+3; col++){
                        if(board[row][col]!='.'){
                            nowIdx = board[row][col] - '0';
                            if(isNum[nowIdx])
                                return false;
                            isNum[nowIdx] = true;
                        }
                    }
                }
            }
        }
        return true;
        
    }
};