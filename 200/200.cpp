class Solution {
public:
    void fillIsland(vector<vector<char>>& grid, int y, int x){
        grid[y][x] = '#';
        if(x-1>=0&&grid[y][x-1] == '1'){
            fillIsland(grid, y, x-1);
        }
        if(x+1<width && grid[y][x+1]=='1'){
            fillIsland(grid, y, x+1);
        }
        if(y-1 >=0 && grid[y-1][x] == '1'){
            fillIsland(grid, y-1, x);
        }
        if(y+1 < height && grid[y+1][x] == '1'){
            fillIsland(grid,y+1,x);
        }
    }
    
    int numIslands(vector<vector<char>>& grid) {
        height = grid.size();
        if(height==0)
            return 0;
        width = grid[0].size();
        if(width == 0)
            return 0;
        
        int out = 0;
        for(int i = 0; i < height; i++){
            for(int j = 0; j < width; j++){
                if(grid[i][j] == '1'){
                    fillIsland(grid, i, j);
                    out++;
                }
            }
        }
        return out;
    }
    int width;
    int height;
};