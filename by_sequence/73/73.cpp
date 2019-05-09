class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        bool isFirstRow = false;
        bool isFirstCol = false;
        int colLen = matrix.size();
        if(colLen == 0)
            return;
        int rowLen = matrix[0].size();
        
        for(int i = 0; i < colLen; i++){
            for(int j = 0; j < rowLen; j++){
                if(matrix[i][j] == 0){
                    if(i == 0)
                        isFirstCol = true;
                    if(j == 0)
                        isFirstRow = true;
                    if(j != 0 && i != 0){
                        matrix[0][j] = 0;
                        matrix[i][0] = 0;
                    }
                }
            }
        }
        
        for(int j = 1; j < rowLen; j++){
            for(int i = 1; i < colLen; i++){
                if(matrix[0][j] == 0 || matrix[i][0] == 0){
                    matrix[i][j] = 0;
                }
            }
        }
        if(isFirstRow){
            for(int i = 0; i < colLen; i++){
                matrix[i][0] = 0;
            }
        }
        if(isFirstCol){
            for(int i = 0; i < rowLen; i++){
                matrix[0][i] = 0;
            }
        }
        
    }
};