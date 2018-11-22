class Solution {
public:
    void insertVector(int size, int nowsize, int firstIdx, vector<int>& nums, vector<int>& v){
        if(size == nowsize)
            out.push_back(v);
        int len = nums.size();
        for(int i = firstIdx; i < len; i++){
            v.push_back(nums[i]);
            insertVector(size, nowsize+1, i+1, nums, v);
            v.pop_back();
        }
            
    }
    
    vector<vector<int>> subsets(vector<int>& nums) {
        int len = nums.size();
        vector<int> v;
        out.push_back(v);
        if(len == 0)
            return out;
        
        for(int s = 1; s <= len; s++){
            for(int first = 0; first < len - s + 1; first++){
                v.push_back(nums[first]);
                insertVector(s, 1, first + 1, nums, v);
                v.pop_back();
            }
        }
        return out;
        
    }
    
    vector<vector<int>> out;
};