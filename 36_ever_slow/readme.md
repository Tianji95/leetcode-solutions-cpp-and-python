这个题扫一遍就能解决，重点在于使用bool数组，来保存是否这个数字曾经出现过，这里面使用三个数组，就可以扫一遍解决这个问题了

    class Solution {
    public:
        bool isValidSudoku(vector<vector<char>>& board) {
            vector<vector<int>> row_used(9,vector<int>(10,0));
            vector<vector<int>> col_used(9,vector<int>(10,0));
            vector<vector<int>> bok_used(9,vector<int>(10,0));
            for(int i = 0;i < 9;++i)
            {
                for(int j = 0;j < 9;++j)
                {
                    int k = 3 * (i / 3) + j / 3;
                    char ch = board[i][j];
                    if(ch == '.')
                        continue;
                    int val = ch - '0';
                    if(row_used[i][val] == 1 || col_used[j][val] == 1 || bok_used[k][val] == 1)
                        return false;
                    row_used[i][val] = 1;
                    col_used[j][val] = 1;
                    bok_used[k][val] = 1;
                }
            }
            return true;
        }
    };