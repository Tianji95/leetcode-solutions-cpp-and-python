class Solution {
public:
    char** allocMem1() {
        char** p = new char*[9]();
        for(int i=0; i<9; i++) {
            p[i] = new char[9]();
        }
        return p;
    }
    
    char*** allocMem2() {
        char*** p = new char**[3]();
        for(int i=0; i<3; i++) {
            p[i] = new char*[3]();
            for(int j=0; j<3; j++) {
                p[i][j] = new char[9]();
            }
        }
        return p;
    }
    void solveSudoku(vector<vector<char>>& board) {
        char** row = allocMem1(); 
        char** col = allocMem1();  
        char*** rect = allocMem2();  
        for(int i=0; i<9; i++) {
            for(int j=0; j<9; j++) {
                if(board[i][j]=='.') continue;
                int idx = board[i][j] - '1';
                row[i][idx] = 1;
                col[j][idx] = 1;
                rect[i/3][j/3][idx] = 1;
            }
        }
        fill(board, row, col, rect, 0, 0);
    }
    
    bool searchEmpty(vector<vector<char>>& board, int& iIdx, int& jIdx) {
        int i=iIdx, j=jIdx;
        bool found = false;
        while(i<9) {
            if(board[i][j]=='.') {
                found = true;
                break;
            }
            else {
                if(j==8) {
                    i += 1;
                    j = 0;
                    continue;
                } else {
                    j += 1;
                }
            }
        }
        iIdx = i;
        jIdx = j;
        return found;
    }
    
    bool fill(vector<vector<char>>& board, char** row, char** col, char*** rect, int iiIdx, int jjIdx) {
        int iIdx = iiIdx;
        int jIdx = jjIdx;
        bool found = searchEmpty(board, iIdx, jIdx);
        if(!found) return true;
        //find an available 1-9 digit that is in row, col, and rect
        //val = idx+1;
        for(int idx=0; idx<9; idx++) {
            if(!row[iIdx][idx] && !col[jIdx][idx] && !rect[iIdx/3][jIdx/3][idx]) {
                board[iIdx][jIdx] = '1'+idx;
                row[iIdx][idx] = 1;
                col[jIdx][idx] = 1;
                rect[iIdx/3][jIdx/3][idx] = 1;
                bool good = fill(board, row, col, rect, iIdx, jIdx);
                if(good) {return true;}
                else {
                    board[iIdx][jIdx] = '.';
                    row[iIdx][idx] = 0;
                    col[jIdx][idx] = 0;
                    rect[iIdx/3][jIdx/3][idx] = 0;
                }
            }
        }
        return false;
    }
};