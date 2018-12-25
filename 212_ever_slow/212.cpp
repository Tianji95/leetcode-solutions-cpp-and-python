class Solution {
public:
    bool dfs(vector<vector<char>>& board, string& word, int idx, int x, int y){
        if(word.size() == idx)
            return true;
        if(board[y][x] == word[idx]){
            if(word.size() == idx+1)
                return true;
            
            int tmp = board[y][x];
            board[y][x] = '#';
            if(x!=0){
                if(dfs(board, word, idx+1, x-1, y)){
                    board[y][x] = tmp;
                    return true;
                }
            }
            if(x!=width-1){
                if(dfs(board, word, idx+1, x+1, y)){
                    board[y][x] = tmp;
                    return true;
                }
                    
            }
            if(y!=0){
                if(dfs(board, word, idx+1, x, y-1)){
                    board[y][x] = tmp;
                    return true;
                }
                    
            }
            if(y != height-1){
                if(dfs(board, word, idx+1, x, y+1)){
                    board[y][x] = tmp;
                    return true;
                }
                    
            }
            board[y][x] = tmp;
            
        }
        return false;
    }
    
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        
        set<string> out;
        int len = words.size();
        vector<string> V;
        height = board.size();
        if(height == 0 || len == 0)
            return V;
        width = board[0].size();
        
        for(int i = 0; i < len; i++){
            bool isThisWord = false;
            for(int y = 0; y < height; y++){
                for(int x = 0; x < width; x++){
                    if(dfs(board, words[i], 0, x, y)){
                        isThisWord = true;
                        break;
                    } 
                }
                if(isThisWord)
                    break;
            }
            if(isThisWord)
                out.insert(words[i]);
        }
        
        
        for(auto I : out){
            V.push_back(I);
        }
        return V;
    }

    int width;
    int height;
};