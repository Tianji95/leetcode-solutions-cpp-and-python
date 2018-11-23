class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        heights.push_back(0);
        int len = heights.size();
        int maxR = 0;
        vector<int> prevIdx;
        
        if(len == 0)
            return 0;
        for(int i = 0; i < len; i++){
            while(prevIdx.size() > 0 && heights[prevIdx.back()] >= heights[i]){
                int h = heights[prevIdx.back()];
                prevIdx.pop_back();
                
                int nowlen = prevIdx.size() > 0?prevIdx.back():-1;
                int thisMaxR = h * (i-nowlen-1);
                if(thisMaxR > maxR)
                    maxR = thisMaxR;
            }
            prevIdx.push_back(i);
        }
        return maxR;
    }
};