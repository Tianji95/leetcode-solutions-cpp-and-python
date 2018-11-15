class Solution {
public:
    void fillMatrix(int index, int n){
        int rightIdx = n - index - 1;
        int bottomIdx = n - index - 1;
        
        if(rightIdx == index && bottomIdx == index){
            matrix[index][index] = count++;
            return;
        }
        
        for(int i = index; i < rightIdx; i++){
            matrix[index][i] = count++;
        }
        //右边竖着的
        for(int i = index; i < bottomIdx; i++){
            matrix[i][rightIdx] = count++;
        }
        //下面横着的，从右向左
        for(int i = rightIdx; i > index; i--){
            matrix[bottomIdx][i] = count++;
        }
        //左边竖着的，从下到上
        for(int i = bottomIdx; i > index; i--){
            matrix[i][index] = count++;
        }
        if(2 * index + 2 < n){
            fillMatrix(index + 1,n);
        }
    }
    
    vector<vector<int>> generateMatrix(int n) {
        count = 1;
        vector<int> tmpVector;
        for(int i = 0; i < n; i++){
            tmpVector.push_back(0);
        }
        for(int i = 0; i < n; i++){
            matrix.push_back(tmpVector);
        }
        fillMatrix(0, n);
        
        
        
        return matrix;
    }
    vector<vector<int>> matrix;
    int count;
};