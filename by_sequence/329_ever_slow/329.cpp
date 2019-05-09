class Solution {
public:
    int DFS(vector<vector<int>>& matrix, int y, int x, int val, vector<vector<int>>& hash)
    {
        if(y < 0 || y >= matrix.size() || x <0 || x >= matrix[0].size())
            return 0;
        if(matrix[y][x] > val)
        {
            if(hash[y][x] != 0) return hash[y][x]; //if this path has been searched
            int a = DFS(matrix, y, x+1,matrix[y][x], hash) + 1;
            int b = DFS(matrix, y, x-1,matrix[y][x], hash) + 1;
            int c = DFS(matrix, y+1, x,matrix[y][x], hash) + 1;
            int d = DFS(matrix, y-1, x,matrix[y][x], hash) + 1;
            hash[y][x] = max(a, max(b,max(c, d)));
            return hash[y][x];
        }
        return 0;
    }
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        if(matrix.size() == 0) return 0;
        int Max = 0;
        vector<int> tem(matrix[0].size(),0);
        vector<vector<int>> hash(matrix.size(), tem);
        for(int i = 0; i< matrix.size(); i++)
            for(int j = 0; j < matrix[0].size(); j++)
                Max = max(DFS(matrix, i, j, INT_MIN, hash), Max);
        return Max;
    }
};