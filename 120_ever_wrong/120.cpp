class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int rows = triangle.size();
        if(rows == 0)
            return 0;
        
        vector<int> dpArray(rows+1, 0);
        for(int i = rows - 1; i >= 0; i--){
            for(int j = 0; j <= i; j++){
               dpArray[j] = min(dpArray[j], dpArray[j+1]) + triangle[i][j]; 
            }
        }
        return dpArray[0];
    }
};