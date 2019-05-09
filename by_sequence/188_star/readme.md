这道题我有些取巧了，下面是正确的方法以及解释，说实话，这个方法有些繁琐了，不过也可以用我自己的方法写，想对好理解一些：
https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iv/discuss/54145/O(n)-time-8ms-Accepted-Solution-with-Detailed-Explanation-(C++)
    class Solution {
    public:
        int maxProfit(int k, vector<int>& prices) {

            // Step 1: Find out all profit opportunities            
            vector<int> profits;
            stack<pair<int, int>> vps; // valley-peak pairs
            
            int v;
            int p = -1;
            for (;;) {
                // find next valley-peak pair
                for (v = p+1; (v+1 < prices.size()) && (prices[v] >= prices[v+1]); ++v);
                for (p = v  ; (p+1 < prices.size()) && (prices[p] <= prices[p+1]); ++p);
                
                if (v == p) { // v==p means that both v and p reach the end of the array
                    break;
                }
                
                // Consider two transactions (v1, p1) (back of the stack) and (v2, p2) (the new-found).
                // If prices[v1] >= prices[v2], 
                // it is meaningless to combine the two transactions.
                // Save of profit of (v1, p1), and pop it out of the record.
                while ((!vps.empty()) && (prices[v] <= prices[vps.top().first])) {
                    profits.push_back(prices[vps.top().second] - prices[vps.top().first]);
                    vps.pop();
                }
                
                // If prices[v1]<prices[v2] and prices[p1]<prices[p2], 
                // then it is meaningful to combine the two transactions
                // update (v1, p1) to (v1, p2), and save the profit of (v2, p1)
                while ((!vps.empty()) && (prices[p] >= prices[vps.top().second])) {
                    profits.push_back(prices[vps.top().second] - prices[v]);
                    v = vps.top().first;
                    vps.pop();
                }
                
                // save the new-found valley-peak pair
                vps.emplace(v, p);
            }
            
            // save all remaining profits
            while (!vps.empty()) {
                profits.push_back(prices[vps.top().second] - prices[vps.top().first]);
                vps.pop();
            }
            
            // Step 2: Calculate the k highest profits
            int ret;
            if (profits.size() <= k) {
                ret = accumulate(profits.begin(), profits.end(), 0);
            } else {
                nth_element(profits.begin(), profits.end() - k, profits.end());
                ret = accumulate(profits.end() - k, profits.end(), 0);
            }
            return ret;
        }
    };