class Solution {
public: 
    int numTrees(int n) {
        if(n == 0)
            return 0;
        vector<int> dpArray(n+1, 0);
        dpArray[0] = 1;
        dpArray[1] = 1;
        
        for(int i = 2; i <= n; i++){
            for(int j = 1; j <= i; j++){
                dpArray[i] += dpArray[j-1] * dpArray[i-j];
            }
        }
        return dpArray[n];
    }
};