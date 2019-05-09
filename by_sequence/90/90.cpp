class Solution {
public:
    void addVector(int maxCount, int thisIdx, vector<int>& insV, int depth, vector<int>& nums){
        if(maxCount == depth){
            out.push_back(insV);
            return ;
        }
        for(int i = thisIdx; i < len; i++){
            if(len - maxCount < i - depth)
                return;
            if(i !=thisIdx && nums[i] == nums[i-1])
                continue;
            insV.push_back(nums[i]);
            addVector(maxCount, i+1,insV, depth+1,nums);
            insV.pop_back();
        }
        
    }
    
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<int> insV;
        out.push_back(insV);
        std::sort(nums.begin(), nums.end());
        len = nums.size();
        for(int i = 0; i < len; i++){
            addVector(i+1, 0, insV, 0, nums);
        }
        return out;
    }
    int len;
    vector<vector<int>> out;
};