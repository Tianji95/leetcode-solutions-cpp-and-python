class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        int len1 = s1.size();
        int len2 = s2.size();
        int len3 = s3.size();
        if(len1+len2 != len3)
            return false;
        
        vector<vector<bool>> dpArray(len1+1, vector<bool>(len2+1, false));
        
        dpArray[0][0] = true;
        for(int i = 1; i <= len1; i++){
            if(s1[i-1] == s3[i-1]){
                dpArray[i][0] = true && dpArray[i - 1][0];
                if(!dpArray[i][0])
                    break;
            }
            else
                break;
        }
        for(int i = 1; i <= len2; i++){
            if(s2[i-1] == s3[i-1]){
                dpArray[0][i] = true && dpArray[0][i - 1];
                if(!dpArray[0][i])
                    break;
            }
            else
                break;
        }
        
        for(int i = 1; i <= len1; i++){
            for(int j = 1; j <= len2; j++){
                dpArray[i][j] = (dpArray[i-1][j] && (s1[i-1] == s3[i+j-1])) || (dpArray[i][j-1] && (s2[j-1] == s3[i+j-1]));
            }
        }
        
        return dpArray[len1][len2];
    }
};