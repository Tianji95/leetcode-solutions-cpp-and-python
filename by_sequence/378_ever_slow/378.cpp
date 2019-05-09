class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int height = matrix.size();
        if(height == 0)
            return 0;
        int width  = matrix[0].size();
        if(width == 0)
            return 0;
        
        vector<int> allSmallElement(height, 0);
        
        int left = matrix[0][0];
        int right= matrix[height-1][width-1];
        
        double mid = left + (left - right)/2.0;
        
        while(left < right)
        {        
            mid = (left + right)/2.0;
            int num = 0;
            for(int h = 0; h < height; h++)
            {
                int pos = upper_bound(matrix[h].begin(), matrix[h].end(), mid) - matrix[h].begin();
                num += pos;
            }
            if(num >= k){
                right = mid;
            }
            else{
                left = mid+1;
            }
        }
        
        return left;
    }
};