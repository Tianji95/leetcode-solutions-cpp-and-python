class Solution {
public:
    vector<int> grayCode(int n) {
        if(n == 0){
            out.push_back(0);
            return out;
        }
        if(n >= 1){
            out.push_back(0);
            out.push_back(1);
        }
        
        for(int i = 2; i <=n; i++){
            int len = out.size();
            int addnum = 1<<i-1;
            for(int j = len-1; j >= 0; j--){
                out.push_back(out[j]+addnum);
            }
        }
        return out;
        
    }
    vector<int> out;
};