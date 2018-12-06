class Solution {
public:
    int candy(vector<int>& ratings) {
        int len = ratings.size();
        int out = 1;
        int lastMinIdx = 0;
        int lastMinCandy = 1;
        int lastCandy = 1;
            
        if(len == 0)
            return 0;

        for(int i = 1; i < len; i++){
            if(ratings[i] < ratings[i-1]){
                lastCandy = 1;
                if(i-lastMinIdx == lastMinCandy){
                    out+=i-lastMinIdx+1;
                    lastMinCandy++;
                }
                else{
                    out+= i-lastMinIdx;
                }
                
            }
            else if(ratings[i] > ratings[i-1]){
                lastCandy++;
                out += lastCandy;
                lastMinCandy = lastCandy;
                lastMinIdx = i;
            }
            else{
                out++;
                lastCandy = 1;
                lastMinIdx = i;
                lastMinCandy = 1;
            }
        }
        return out;
    }
};