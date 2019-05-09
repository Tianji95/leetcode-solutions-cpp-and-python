class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> out;
        map<int, int> idxMap;
        int left  = 0;
        int right = 1;
        int len = nums.size();
        int minus = 0;
        
        
        if(len < 3)
            return out;

        //去重
        std::sort(nums.begin(), nums.end());
        
        
        for(int i = 0; i < len; i++){
            idxMap[nums[i]] = i;
        }
        
        for(left = 0; left < len - 2; left++){
            map<int, int> isEqualFlag;
            for(right = left + 1; right < len - 1; right++){
                if(nums[left] == nums[right]){
                    isEqualFlag[nums[right]]++;
                }
                if(nums[left] != nums[right] && nums[right] == nums[right - 1])
                    continue;
                if(isEqualFlag[nums[right]] >=2){
                    continue;
                }
                minus = -nums[left]-nums[right];
                if(minus < 0)
                    break;
                if(idxMap.find(minus)!=idxMap.end() && idxMap[minus] > right){
                    vector<int> tmpout;
                    tmpout.push_back(nums[left]);
                    tmpout.push_back(nums[right]);
                    tmpout.push_back(nums[idxMap[minus]]);
                    out.push_back(tmpout);
                }
            }
            left += isEqualFlag[nums[left]];
        }
        return out;
    }
};