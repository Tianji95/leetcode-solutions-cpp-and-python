class Solution {
public:
    int countBattleships(vector<vector<char>>& board) {
        int height = board.size();
        if(height == 0){
            return 0;
        }
        int width = board[0].size();
        if(width == 0){
            return 0;
        }
        
        int out = 0;
        for(int h = 0; h < height; h++){
            for(int w = 0; w < width; w++){
                if((board[h][w] == 'X') && (h==0 || board[h-1][w] !='X') && (w==0 || board[h][w-1]!='X')){
             out++;       
                }
            }
        }
        
        return out;
        
    }
};