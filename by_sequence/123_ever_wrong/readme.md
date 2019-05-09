这段代码十分巧妙了，其中buy1指的是一开始买所需要的价钱，sell1指的是卖出的价格，buy2指的是用sell1卖出的价格再买所需要的钱，我们需要剩余更多的钱，所以用了一个max，sell2指的是卖出第二个物品所得到的收益。这样就相当于买卖两次所赚取的最大收益了。

    class Solution {
    public:
        int maxProfit(vector<int>& prices) {
            int len = prices.size();
            if(len == 1 || len == 0)
                return 0;
            
            int sell1 = 0;
            int sell2 = 0;
            int buy1 = INT_MIN;
            int buy2 = INT_MIN;
            
            
            for(int i = 0; i < len; i++){
                buy1  = max(buy1, -prices[i]);
                sell1 = max(sell1, buy1+prices[i]);
                buy2  = max(buy2, sell1-prices[i]);
                sell2 = max(sell2, buy2+prices[i]);
            }
            return sell2;
            
            
        }
    };