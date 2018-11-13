class Solution {
public:
    vector<vector<int>> insertP(vector<int> nums){
        int len = nums.size();
        vector<vector<int>> out;
        if(len == 1){
            out.push_back(nums);
            return out;
        }
        
        for(int i = 0; i < len; i++){
            vector<int> tmpV = nums;
            tmpV.erase(tmpV.begin()+i);
            auto tmpout = insertP(tmpV);
            
            for(int j = 0; j < tmpout.size(); j++){
                tmpout[j].push_back(nums[i]);
            }
            out.insert(out.end(), tmpout.begin(), tmpout.end());
        }
        return out;
        
    }
    
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> out;
        
        int len = nums.size();
        
        if(len == 0)
            return out;
        if(len == 1){
            out.push_back(nums);
            return out;
        }
        return insertP(nums);      
    }
};