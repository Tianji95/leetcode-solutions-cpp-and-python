class Solution {
public:
    int minMoves2(vector<int>& nums) {
        int len = nums.size();
        sort(nums.begin(), nums.end());
        int median = nums[len/2];
        int count = 0;
        for(auto n : nums){
            count+=abs(n-median);
        }
        return count;
    }
};