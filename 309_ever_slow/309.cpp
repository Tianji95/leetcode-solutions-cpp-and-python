class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int len = prices.size();
        int lastBuy = 0;
        int lastSell = 0;
        int out = 0;
        int buy = INT_MIN;
        int sell = 0;
        
        for(int i = 0; i < len; i++){
            lastBuy = buy;
            buy = max(lastSell-prices[i], buy);
            lastSell = sell;
            sell = max(lastBuy+prices[i], sell);
            
        }
        return sell;
    }
};