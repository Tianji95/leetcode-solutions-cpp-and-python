class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<pair<int, int>>& edges) {
        if(n == 1)
            return {0};
        vector<vector<int>> G(n);
        vector<int> degree(n);
        queue<int> Q;
        for(auto e:edges) {
            G[e.first].push_back(e.second);
            G[e.second].push_back(e.first);
        }
        for(int i = 0; i < n; ++i) {
            degree[i] = G[i].size();
            if(degree[i]==1)
                Q.push(i);
        }
        for(int cnt = n-Q.size(); cnt > 0; cnt-=Q.size()) {
            for(int N = Q.size(); N > 0; --N) {
                int m = Q.front();
                Q.pop();
                for(auto k:G[m]) {
                    if(degree[k] > 1) {
                        if(--degree[k] == 1)
                            Q.push(k);
                    }
                }
            }
        }
        vector<int> res;
        while(!Q.empty()) {
            res.push_back(Q.front());
            Q.pop();
        }
        return res;
    }
};