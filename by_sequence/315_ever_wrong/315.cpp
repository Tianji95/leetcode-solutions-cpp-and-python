class Solution {
public:
    vector<int> countSmaller(vector<int>& nums) {
        vector<int> db;
        vector<int> result(nums.size());
        for(int i = nums.size()-1; i >= 0; i--)
        {
            auto it = lower_bound(db.begin(), db.end(), nums[i]);
            result[i] = it - db.begin();
            db.insert(it, nums[i]);
        }
        return result;
    }
};