class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int rowSize = matrix.size();
        if(rowSize == 0)
            return false;
        int colSize = matrix[0].size();
        if(colSize == 0)
            return false;
        
        int rowSmall = 0;
        int rowLarge = rowSize - 1;
        int middle;
        if(target > matrix[rowLarge][0]){
            rowSmall = rowLarge;
        }
        while(rowSmall < rowLarge - 1){
            middle = (rowSmall + rowLarge) / 2;
            if(matrix[middle][0] < target){
                rowSmall = middle;
            }
            else if(matrix[middle][0] > target){
                rowLarge = middle;
            }
            else{
                return true;
            }
        }
        
        int finalRow = 0;
        if(target > matrix[rowLarge][0]){
            finalRow = rowLarge;
        }
        else if(target < matrix[rowLarge][0]){
            finalRow = rowSmall;
        }
        else{
            return true;
        }
        
        int colSmall = 0;
        int colLarge = colSize - 1;
        while(colSmall < colLarge - 1){
            middle = (colSmall + colLarge) / 2;
            if(matrix[finalRow][middle] < target){
                colSmall = middle;
            }
            else if(matrix[finalRow][middle] > target){
                colLarge = middle;
            }
            else{
                return true;
            }
        }
        if(target == matrix[finalRow][colLarge] || target == matrix[finalRow][colSmall])
            return true;
        return false;
        
    }
};