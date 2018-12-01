class Solution {
public:
    int numDistinct(string s, string t) {
        int lens = s.size();
        int lent = t.size();
        vector<vector<int>> dpArray(lens+1, vector<int>(lent+1, 0));
        
        for(int i = 0; i <= lens; i++){
            dpArray[i][0] = 1;
        }
        for(int i = 1; i <= lens; i++){
            for(int j = 1; j <= lent; j++){
                if(s[i-1] == t[j-1]){
                    dpArray[i][j] = dpArray[i-1][j-1] + dpArray[i-1][j];
                }
                else{
                    dpArray[i][j] = dpArray[i-1][j];
                }
            }
        }
        return dpArray[lens][lent];
    }
};