class NumMatrix {
public:
    vector<vector<int>> cache;
    NumMatrix(vector<vector<int>> matrix) {
        int height = matrix.size();
        if(height == 0){
            return;
        }
        int width  = matrix[0].size();
        if(width == 0){
            return;
        }
        cache.resize(height+1, vector<int>(width+1, 0));
        for(int h = 1; h <= height; h++){
            for(int w = 1; w <= width; w++){
                cache[h][w] = cache[h][w-1]+cache[h-1][w]-cache[h-1][w-1]+matrix[h-1][w-1];
            }
        }
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        return cache[row2+1][col2+1]-cache[row1][col2+1]-cache[row2+1][col1]+cache[row1][col1];
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix obj = new NumMatrix(matrix);
 * int param_1 = obj.sumRegion(row1,col1,row2,col2);
 */