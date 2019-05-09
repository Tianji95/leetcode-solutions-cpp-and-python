class Solution {
public:
    bool findCandi(vector<int>& candidates, int clen, int target, int idx, int pos, vector<int> prevVector, vector<vector<int>>& out){
        if(idx >= clen || target < candidates[idx])
            return 0;
        prevVector.push_back(candidates[idx]);
        for(int i = idx; i < clen; i++){
            while(i!=idx&&i<clen&&candidates[i-1]==candidates[i]){
                i++;
            }
            prevVector[pos] = candidates[i];
            if(target == candidates[i]){
                out.push_back(prevVector);
                return 1;
            }
            if(target < candidates[i])
                break;
            findCandi(candidates, clen, target-candidates[i], i+1, pos+1, prevVector, out);
        }
        return 0;
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> out;
        vector<int>         prevVector;
        int clen = candidates.size();
        
        if(clen == 0)
            return out;
        std::sort(candidates.begin(), candidates.end());
        if(target < candidates[0])
            return out;
        
        prevVector.push_back(candidates[0]);
        for(int i = 0; i < clen; i++){
            while(i!=0&&i<clen&&candidates[i-1]==candidates[i]){
                i++;
            }
            prevVector[0] = candidates[i];
            if(target==candidates[i]){
                out.push_back(prevVector);
                break;
            }
            if(target < candidates[i])
                break;
            findCandi(candidates, clen, target-candidates[i], i+1, 1, prevVector, out);
        }
        return out;
    }
};