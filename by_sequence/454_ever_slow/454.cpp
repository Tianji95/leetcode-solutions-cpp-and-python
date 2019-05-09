class Solution {
public:
    int fourSumCount(vector<int>& A, vector<int>& B, vector<int>& C, vector<int>& D) {
        int len = A.size();
        unordered_map<int, int> mp;
        int count = 0;
        for(auto a : A){
            for(auto b : B){
                if(mp.find(a+b)!=mp.end()){
                    mp[a+b]++;
                }
                else{
                    mp[a+b] = 1;
                }
            }
        }
        
        for(auto c : C){
            for(auto d : D){
                if(mp.find(-c-d)!=mp.end()){
                    count += mp[-c-d];
                }
            }
        }
        return count;
    }
};