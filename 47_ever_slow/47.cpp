class Solution {
public:
    set<vector<int>> hashout;
    
    bool iteraFunc(vector<int> & nums, int idx){
        int i;
        int len = nums.size();
        if(idx == len-1){
            hashout.insert(nums);
            return true;
        }
        for(int i = idx; i < len; i++){
            swap(nums[i], nums[idx]);
            iteraFunc(nums, idx+1);
            swap(nums[i], nums[idx]);
        }
        return true;
    }
    
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        iteraFunc(nums, 0);
        vector<vector<int>> out;
        for(auto iter = hashout.begin(); iter!=hashout.end(); iter++){
            out.push_back(*iter);
        }
        return out;
    }
};

