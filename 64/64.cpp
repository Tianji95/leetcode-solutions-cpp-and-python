class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int height = grid.size();
        if(height == 0)
            return 0;
        int width = grid[0].size();
        if(width == 0)
            return 0;
        if(height == 1 && width == 1)
            return grid[0][0];
        
        vector<vector<int>> dpArray(height, vector<int>(width, 0));
        dpArray[0][0] = grid[0][0];
        for(int i = 1; i < height; i++){
            dpArray[i][0] = dpArray[i-1][0] + grid[i][0];
        }
        for(int i = 1; i < width; i++){
            dpArray[0][i] = dpArray[0][i-1] + grid[0][i];
        }
        for(int i = 1; i < height; i++){
            for(int j = 1; j < width; j++){
                if(dpArray[i-1][j] < dpArray[i][j-1]){
                    dpArray[i][j] = dpArray[i-1][j] + grid[i][j];
                }
                else{
                    dpArray[i][j] = dpArray[i][j-1] + grid[i][j];
                }
            }
        }
        return dpArray[height-1][width-1];
        
    }
};