class Solution {
public:
    int findMin(vector<int>& nums, int preIdx){
        int len = nums.size();
        if(len == 1)
            return preIdx;
        int middle = nums[]
        if()
    }
    
    int search(vector<int>& nums, int target) {
        int len = nums.size();
        
        if(len == 0)
            return -1;
        if(len == 1){
            if(target == nums[0]){
                return 0;
            }
            else{
                return -1;
            }
        }
        
        int minIdx = findMin(nums, 0)
        
    }
};