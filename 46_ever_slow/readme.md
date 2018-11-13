这道题主要慢在我的vector以及暴力编码上面了，下面是比较快的解法

class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> result;
        vector<int> tmp;
        helper(result, tmp, nums);
        return result;
    }
private:
    void helper(vector<vector<int>> &result, vector<int>& tmp, vector<int> &nums){
        if(tmp.size() == nums.size()){
            result.push_back(tmp);
            return;
        }
        bool is_repeat = false;
        for(int i=0; i<nums.size(); i++){
            for(auto num:tmp){
                if(num == nums[i]){
                    is_repeat = true;
                    break;
                }
            }
            if(is_repeat){
                is_repeat = false;
                continue;
            }
            tmp.push_back(nums[i]);
            helper(result, tmp, nums);
            tmp.pop_back();
        }
    }
};