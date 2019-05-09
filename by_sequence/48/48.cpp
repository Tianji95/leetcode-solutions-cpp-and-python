class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int len = matrix.size();
        if(len == 0 || len == 1)
            return;
        
        int tmp = 0;
        int tmpIdx1 = 0;
        int tmpIdx2 = 0;
        
        for(int m = 0; m < len / 2; m++){
            for(int i = m; i < len - m - 1; i++){
                tmpIdx1 = len - i - 1;
                tmpIdx2 = len - m - 1;
                tmp = matrix[m][i];
                matrix[m][i] = matrix[tmpIdx1][m];
                matrix[tmpIdx1][m] = matrix[tmpIdx2][tmpIdx1];
                matrix[tmpIdx2][tmpIdx1] = matrix[i][tmpIdx2];
                matrix[i][tmpIdx2] = tmp;
            }
        }

    }
};