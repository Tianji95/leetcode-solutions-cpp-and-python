class Solution {
public:
    string longestPalindrome(string s) {
        int leftIdx  = 0;
        int rightIdx = 0;
        int doubleRightIdx = 0;
        int doubleLeftIdx  = 0;
        int nowIdx   = 0;
        int maxLen   = 0;
        int strLen   = s.size();
        string maxStr("");
        bool ispalinStr(true);
        
        while(nowIdx < strLen){
            ispalinStr = true;
            leftIdx = rightIdx = nowIdx;
            doubleRightIdx = nowIdx;
            doubleLeftIdx  = nowIdx - 1;
            if(leftIdx - 1 >= 0 && rightIdx + 1 < strLen){
                
                // 判断奇数字符的回文串
                while(rightIdx < strLen && leftIdx >=0 && ispalinStr){
                    if(s[leftIdx] == s[rightIdx]){
                        leftIdx--;
                        rightIdx++;
                    }
                    else{
                        ispalinStr = false;
                    }
                }
                if(rightIdx - leftIdx - 1 > maxLen){
                    maxStr = s.substr(leftIdx+1, rightIdx - leftIdx - 1);
                    maxLen = maxStr.size();
                }
            }
            if(doubleLeftIdx >= 0){
                // 判断偶数字符的回文串
                ispalinStr = true;

                while(doubleRightIdx < strLen && doubleLeftIdx >= 0 &&ispalinStr){
                    if(s[doubleLeftIdx] == s[doubleRightIdx]){
                        doubleLeftIdx--;
                        doubleRightIdx++;
                    }
                    else{
                        ispalinStr = false;
                    }
                }
                if(doubleRightIdx - doubleLeftIdx - 1 > maxLen){
                    maxStr = s.substr(doubleLeftIdx + 1, doubleRightIdx - doubleLeftIdx - 1);
                    maxLen = maxStr.size();
                }
                
            }
            else{
                if(maxLen < 1){
                    maxStr = s[nowIdx];
                    maxLen = 1;
                }
            }
            nowIdx++;
        }
        return maxStr;
    }
};