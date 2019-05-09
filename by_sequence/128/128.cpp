class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        std::set<int> numset;
        
        int lenN = nums.size();
        
        for(int i = 0; i < lenN; i++){
            numset.insert(nums[i]);
        }
        
        int maxVal = 0;
        
        for(int i = 0; i < lenN; i++){
            if(numset.find(nums[i]-1)==numset.end()){
                int thisnum = nums[i] + 1;
                int thisLen = 1;
                while(numset.find(thisnum)!=numset.end()){
                    thisLen++;
                    thisnum++;
                }
                if(thisLen > maxVal)
                    maxVal = thisLen;
            }
            
        }
        return maxVal;
    }
};