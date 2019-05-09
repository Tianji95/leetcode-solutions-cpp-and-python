class Solution {
public:
    int nthSuperUglyNumber(int n, vector<int>& primes) {
        int len = primes.size();
        vector<int> val(len, 1);
        vector<int> idx(len, 0);
        vector<int> ugly(n, 0);
        
        int next = 1;
        for(int i = 0; i < n; i++){
            ugly[i] = next;
            next = INT_MAX;
            for(int j = 0; j < len; j++){
                if(val[j] == ugly[i]){
                    val[j] = ugly[idx[j]] * primes[j];
                    idx[j]++;
                }
                next = std::min(next, val[j]);
            }
        }
        return ugly[n-1];
        
    }
};