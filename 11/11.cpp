class Solution {
public:
    int maxArea(vector<int>& height) {
        int maxWater = 0;
        int leftPointer = 0;
        int rightPointer = height.size() - 1;
        while(leftPointer < rightPointer){
            int nowWater = min(height[leftPointer], height[rightPointer]) * (rightPointer - leftPointer);
            maxWater = max(nowWater, maxWater);
            if(height[leftPointer] < height[rightPointer])
                leftPointer++;
            else
                rightPointer--;
        }
        return maxWater;
    }
};