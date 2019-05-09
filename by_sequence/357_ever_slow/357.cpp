class Solution {
public:
    int countNumbersWithUniqueDigits(int n) {
        if (n == 0) return 1;
        if (n == 1) return 10;
        int val = 9, ans = 10;
        for (int i = 2; i <= n; ++i) {
            val *= 11 - i;
            ans += val;
        }
        return ans;
    }
};