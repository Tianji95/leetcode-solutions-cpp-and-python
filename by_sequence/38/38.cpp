class Solution {
public:
    string countAndSay(int n) {
        
        string prevs("1");
        int sLen = 1;
        int count = 1;
        string tmps("");
        if(n == 1)
            return prevs;
        for(int i = 1; i < n; i++){
            sLen = prevs.size();
            for(int j = 0; j < sLen-1; j++){
                if(prevs[j+1] != prevs[j]){
                    tmps = tmps + to_string(count) + prevs[j];
                    count = 1;
                }
                else{
                    count++;
                }
            }
            tmps = tmps + to_string(count)+prevs[sLen-1];
            count = 1; 
            prevs = tmps;
            tmps = "";
        }
        return prevs;
    }
};