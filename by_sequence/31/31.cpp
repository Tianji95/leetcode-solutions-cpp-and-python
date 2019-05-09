class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        bool isChanged = false;
        int lenN = nums.size();
        if(lenN!=0 && lenN!=1){
            for(int i = lenN - 1; i > 0; i--){
                 if(nums[i-1] < nums[i]){
                     int findSmallLarge = i;
                     while(findSmallLarge <= lenN-1){
                         if(nums[findSmallLarge] > nums[i-1]){
                             findSmallLarge++;
                         }
                         else{
                             break;
                         }
                     }
                     if(findSmallLarge!=i)
                         findSmallLarge--;
                     std::swap(nums[findSmallLarge], nums[i-1]);
                     reverse(nums.begin() + i, nums.end());
                     
                     isChanged = true;
                     break;
                 }
            }
            
            if(!isChanged){
                reverse(nums.begin(), nums.end());
            }
        }
    }
};