class Solution {
public:
    void findMinIter(vector<int>& nums, int left, int right){
        if(left >= right-1){
            if(nums[left]<minNum){
                minNum = nums[left];
            }
            if(nums[right] < minNum){
                minNum = nums[right];
            }
            return ;
        }
        int middle = left+(right-left)/2;
        if(nums[middle] > nums[right]){
            findMinIter(nums, middle, right);
        }
        else{
            findMinIter(nums, left, middle);
        }
    }
    
    int findMin(vector<int>& nums) {
        int len = nums.size();
        minNum = INT_MAX;
        findMinIter(nums, 0, len-1);
        return minNum;
    }
    int minNum;
};