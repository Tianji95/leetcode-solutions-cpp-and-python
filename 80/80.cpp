class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int outlen = 0;
        int nlen = nums.size();
        int sameCount = 0;
        int dupCount = 0;
        int right = 0;
        
        while(right < nlen){
            if(right != 0 && nums[right] == nums[right-1]){
                sameCount++;
                if(sameCount>1){
                    dupCount++;
                }
                else{
                    outlen++;
                    nums[right-dupCount] = nums[right];
                }
            }
            else{
                outlen++;
                nums[right-dupCount] = nums[right];
                sameCount = 0;
            }
            right++;
        }
        return outlen;
        
    }
};