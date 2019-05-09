class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int nowGas = 0;
        int lastIdx = 0;
        int glen = gas.size();
        int clen = cost.size();
        if(glen!=clen)
            return -1;
        if(glen==0)
            return 0;
        
        nowGas = gas[0] - cost[0];
        if(nowGas < 0){
            nowGas = 0;
            lastIdx = 0;
        }
        else{
            lastIdx = -1;
        }
        for(int i = 1; i < glen; i++){
            nowGas = nowGas + gas[i] - cost[i];
            if(nowGas < 0){
                nowGas = 0;
                lastIdx = i;
            }
        }
        
        if(lastIdx == -1){
            return 0;
        }
        else{
            for(int i = 0; i <= lastIdx; i++){
                nowGas = nowGas + gas[i] - cost[i];
                if(nowGas < 0)
                    return -1;
            }
            if(lastIdx == glen - 1)
                return 0;
            return lastIdx+1;
        }
        
    }
};