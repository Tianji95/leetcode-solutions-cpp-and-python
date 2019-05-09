class Solution {
public:
    void dfs(vector<vector<char>>& board, int row, int col){
        board[row][col] = '#';
        if(row+1 < rows && board[row+1][col] == 'O'){
            dfs(board, row+1, col);
        }
        if(row-1 >= 0 && board[row-1][col] == 'O'){
            dfs(board, row-1, col);
        }
        if(col+1 < cols && board[row][col+1] == 'O'){
            dfs(board, row, col+1);
        }
        if(col-1 >= 0 && board[row][col-1] == 'O'){
            dfs(board, row, col-1);
        }
    }
    
    void solve(vector<vector<char>>& board) {
        rows = board.size();
        if(rows == 0)
            return ;
        cols = board[0].size();
        if(cols == 0)
            return ;
        
        for(int i = 0; i < rows; i++){
            if(board[i][0] == 'O'){
                dfs(board, i, 0);
            }
            if(cols-1!=0&&board[i][cols-1] == 'O'){
                dfs(board, i, cols-1);
            }
        }
        for(int i = 0; i < cols; i++){
            if(board[0][i] == 'O'){
                dfs(board, 0, i);
            }
            if(rows-1!=0&&board[rows-1][i] == 'O'){
                dfs(board, rows-1, i);
            }
        }
        
        for(int i = 0; i < rows; i++){
            for(int j = 0; j < cols; j++){
                if(board[i][j] == 'O'){
                    board[i][j] = 'X';
                }
                if(board[i][j] == '#'){
                    board[i][j] = 'O';
                }
            }
        }
    }
    int rows;
    int cols;
};