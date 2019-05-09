class Solution {
public:
    bool findCombin(vector<int>& candidates, int clen, int target, vector<int> prevVector, vector<vector<int>>& out, int idx, int pos){
        if(clen==0 || target < candidates[0])
            return 0;
        
        prevVector.push_back(candidates[0]);
        for(int i = pos; i < clen; i++){
            prevVector[idx] = candidates[i];
            if(target==candidates[i]){
                out.push_back(prevVector);
                return true;
            }
            else{
                findCombin(candidates, clen, target-candidates[i], prevVector, out, idx+1, i);
            }
            
        }
        return 0;
    }
    
    
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        int clen = candidates.size();
        vector<vector<int>> out;
        vector<int> prevVector;
        
        std::sort(candidates.begin(), candidates.end());
        if(clen==0 || target < candidates[0])
            return out;
        
        prevVector.push_back(candidates[0]);
        for(int i = 0; i < clen; i++){
            prevVector[0] = candidates[i];
            if(target==candidates[i]){
                out.push_back(prevVector);
                break;
            }
            else{
                findCombin(candidates,clen, target-candidates[i], prevVector, out, 1, i);
            }
            
        }
        return out;
    }
};