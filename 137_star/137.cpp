class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int len = nums.size();
        if(len == 1)
            return nums[0];
        
        unordered_map<int, int> numMap;
        
        for(int i = 0; i < len; i++){
            if(numMap.find(nums[i])!=numMap.end()){
                numMap[nums[i]] --;
            }
            else{
                numMap[nums[i]] = 2;
            }
        }
        for(auto theN : numMap){
            if(theN.second == 2)
                return theN.first;
        }
    }
};