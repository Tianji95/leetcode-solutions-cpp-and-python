class Solution {
public:
    int maxProfit(vector<int>& prices) {
        vector<int> profitVector;
        int len = prices.size();
        if(len == 1 || len == 0)
            return 0;
        int lastPrice = prices[0];
        int maxProfit = 0;
        
        for(int i = 1; i < len; i++){
            if(prices[i] < prices[i-1]){
                maxProfit = prices[i-1] - lastPrice;
                profitVector.push_back(maxProfit);
                lastPrice = prices[i];
            }
        }
        maxProfit = prices[len-1] - lastPrice;
        profitVector.push_back(maxProfit);
        
        std::sort(profitVector.begin(), profitVector.end());
        
        int out = 0;
        int profitSize = profitVector.size();
        if(profitSize == 0)
            return 0;
        if(profitSize == 1)
            return profitVector[0];
        out += profitVector[profitSize-1];
        out += profitVector[profitSize-2];
        return out;
        
        
    }
};