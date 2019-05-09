class Solution {
public:
    int maxCoins(vector<int>& nums) {
        int n = nums.size();
        nums.insert(nums.begin(), 1);
        nums.push_back(1);
        int dp[n + 2][n + 2] = {0};
        for (int len = 1; len <= n; ++len)
            for (int left = 1; left <= n - len + 1; ++left) {
                int right = left + len - 1;
                for (int k = left; k <= right; ++k) {
                    int prod = nums[left-1] * nums[k] * nums[right+1];
                    int first = dp[left][right];
                    int second = dp[left][k-1] + prod + dp[k+1][right];
                    dp[left][right] = max(first, second);
                }
            }
        return dp[1][n];
    }
};