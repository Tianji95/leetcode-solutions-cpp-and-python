class Solution {
public:
    bool dfs(int x, int y, int wIdx, vector<vector<char>>& board, string& word){
        if(wIdx >= wlen)
            return true;
        
        if(board[y][x] != word[wIdx])
            return false;
        int tmp = board[y][x];
        board[y][x] = '#';
        if(y - 1 >= 0){
            if(dfs(x, y - 1, wIdx+1, board, word))
                return true;
        }
        if(y + 1 < height){
            if(dfs(x, y+1, wIdx+1, board, word))
                return true;
        }
        if(x - 1 >= 0){
            if(dfs(x-1, y, wIdx+1, board, word))
                return true;
        }
        if(x + 1 < width ){
            if(dfs(x+1, y, wIdx+1, board, word))
                return true;
        }
        if(wIdx == wlen - 1)
            return true;
        else{
            board[y][x] = tmp;
            return false;
        }
            
    }
    
    bool exist(vector<vector<char>>& board, string word) {
        wlen = word.size();
        height = board.size();
        if(height == 0)
            return false;
        width  = board[0].size();
        if(width == 0)
            return false;
        
        for(int i = 0; i < height; i++){
            for(int j = 0; j < width; j++){
                if(dfs(j, i, 0, board, word)){
                    return true;
                }
            }
        }
        return false;
    }
    int height;
    int wlen;
    int width;
};