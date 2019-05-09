class Solution {
public:
    void fillVector(vector<vector<int>>& matrix, int index){
        //横着的
        int rightIdx = width - index - 1;
        int bottomIdx = height - index - 1;
        
        if(rightIdx == index && index == bottomIdx){
            out.push_back(matrix[bottomIdx][rightIdx]);
            return ;
        }
        else if(rightIdx == index){
            for(int i = index; i <= bottomIdx; i++){
                out.push_back(matrix[i][rightIdx]);
            }
            return ;
        }
        else if(bottomIdx == index){
            for(int i = index; i <= rightIdx; i++){
                out.push_back(matrix[index][i]);
            }
            return;
        }

        
        
        
        for(int i = index; i < rightIdx; i++){
            out.push_back(matrix[index][i]);
        }
        //右边竖着的
        for(int i = index; i < bottomIdx; i++){
            out.push_back(matrix[i][rightIdx]);
        }
        //下面横着的，从右向左
        for(int i = rightIdx; i > index; i--){
            out.push_back(matrix[bottomIdx][i]);
        }
        //左边竖着的，从下到上
        for(int i = bottomIdx; i > index; i--){
            out.push_back(matrix[i][index]);
        }
        
        if(2 * index + 2 < height && 2 * index + 2 < width){
            fillVector(matrix,index+1);
        }
    }
    
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        
        height = matrix.size();
        if(height!=0){
            width = matrix[0].size();
            fillVector(matrix, 0);
        }
        
        return out;
    }
    vector<int> out;
    int width;
    int height;
};