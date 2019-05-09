class Solution {
public:
    void InsertVector(vector<int>& v, int now, int k, int n){
        if(k == 1){
            for(int i = now; i <= n; i++){
                v.push_back(i);
                out.push_back(v);
                v.pop_back();
            }
        }
        else{
            int maxsmall = n - k + 1;
            for(int i = now; i <= maxsmall; i++){
                v.push_back(i);
                InsertVector(v, i + 1, k - 1, n);
                v.pop_back();
            }
        }
    }
    
    vector<vector<int>> combine(int n, int k) {
        int maxsmall = n - k + 1;
        
        if(k == 1){
            vector<int> v;
            for(int i = 1; i <= n; i++){
                v.push_back(i);
                out.push_back(v);
                v.pop_back();
            }
            return out;
        }
        
        for(int i = 1; i <= maxsmall; i++){
            vector<int> v;
            v.push_back(i);
            InsertVector(v, i + 1, k - 1, n);
        }
        return out;
    }
    vector<vector<int>> out;
};