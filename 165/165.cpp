class Solution {
public:
    int compareVersion(string version1, string version2) {
        int len1 = version1.size();
        int len2 = version2.size();
        
        int i = 0;
        int j = 0;
        int num1 = 0;
        int num2 = 0;
        
        for(; i < len1 && j < len2; i++, j++){
            if(version1[i] != '.'){
                num1 = version1[i] - '0';
                while(i+1 < len1 && version1[i+1]!='.'){
                    num1 = num1*10 + version1[i+1] - '0';
                    i++;
                }
            }
            
            if(version2[j] != '.'){
                num2 = version2[j] - '0';
                while(j+1 < len2 && version2[j+1]!='.'){
                    num2 = num2*10 + version2[j+1] - '0';
                    j++;
                }
            }
            if(num1 > num2)
                return 1;
            if(num1 < num2)
                return -1;
            num1 = num2 = 0;
        }
        if(i != len1){
            while(i < len1){
                if(version1[i] >= '1' && version1[j] <= '9')
                    return 1;
                i++;
            }
        }
            
        if(j != len2){
            while(j < len2){
                if(version2[j] >= '1' && version2[j] <= '9')
                    return -1;
                j++;
            }
        }
            
        return 0;
    }
};