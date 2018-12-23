class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {

        int len = prices.size();
        
        if (k > len / 2) {
            int sum = 0;
            for (int i = 1; i <len; i++){
                if (prices[i] > prices[i - 1]){
                    sum += prices[i] - prices[i - 1];
                }
            }
            return sum;
        }
        
        vector<int> buyVector(k+1, INT_MIN);
        vector<int> sellVector(k+1, 0);
        for(int i = 0; i < len; i++){
            for(int j = 1; j <= k; j++){
                buyVector[j] = std::max(buyVector[j], sellVector[j-1]-prices[i]);
                sellVector[j] = std::max(sellVector[j], buyVector[j]+prices[i]);
            }
        }
        return sellVector[k];
        
    }
};