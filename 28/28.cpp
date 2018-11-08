class Solution {
public:
    int strStr(string haystack, string needle) {
        int out = -1;
        if(needle=="")
            return 0;
        int haylen = haystack.size();
        int neelen = needle.size();
        
        int j = 0;
        int isdupli = 0;
        for(int i = 0; i < haylen;){
            if(haystack[i] == needle[j]){
                if(j!=0 && haystack[i] == needle[0]&&!isdupli){
                    isdupli = i;
                }
                if(j == neelen-1){
                    out = i-neelen+1;
                    break;
                }
                j++;
                i++;
            }
            else{
                if(isdupli){
                    i = isdupli;
                    j = 0;
                    isdupli = 0;
                }
                else if(j!=0){
                    j = 0;
                }
                else{
                    i++;
                }
            }

        }
                
        return out;
    }
};