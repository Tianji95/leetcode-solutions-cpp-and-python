class Solution {
public:
    int uniquePaths(int m, int n) {
        int dpArray[100][100];
        
        if(m == 0 || n == 0)
            return 0;
        
        if(m == 1 || n == 1)
            return 1;
        
        for(int i = 0; i < 100; i++){
            dpArray[0][i] = 1;
            dpArray[i][0] = 1;
        }
        for(int i = 1; i < m; i++){
            for(int j = 1; j < n; j++){
                dpArray[i][j] = dpArray[i][j - 1] + dpArray[i-1][j];
            }
        }
        return dpArray[m-1][n-1];
    }
};