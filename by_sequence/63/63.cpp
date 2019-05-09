class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int dpArray[100][100];
        int height = obstacleGrid.size();
        if(height == 0)
            return 0;
        int width  = obstacleGrid[0].size();
        if(width == 0)
            return 0;
        
        if(obstacleGrid[height - 1][width - 1] == 1)
            dpArray[0][0] = 0;
        else
            dpArray[0][0] = 1;
        
        for(int i = 1; i < height; i++){
            if(obstacleGrid[height - i][width - 1] == 1 || obstacleGrid[height - i - 1][width - 1]){
                dpArray[i][0] = 0;
            }
            else{
                dpArray[i][0] = dpArray[i-1][0];
            }
        }
        
        for(int i = 1; i < width; i++){
            if(obstacleGrid[height - 1][width - i] == 1 || obstacleGrid[height - 1][width - i - 1]){
                dpArray[0][i] = 0;
            }
            else{
                dpArray[0][i] = dpArray[0][i-1];
            }
        }
        
        for(int i = 1; i < height; i++){
            for(int j = 1; j < width; j++){
                if(obstacleGrid[height - i - 1][width - j - 1] != 1){
                    dpArray[i][j] = dpArray[i-1][j] + dpArray[i][j-1];
                }
                else
                    dpArray[i][j] = 0;
            }
        }
        return dpArray[height - 1][width - 1];
    }
};