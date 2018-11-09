class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        int lenWords=words.size();
        int lens=s.size();
        vector<int> res;
        if(lenWords==0||lens==0)return res;
        int singlelen=words[0].size();
        int count=lenWords;
        unordered_map<string,int> use;
        //初始化map
        use.clear();
        for(int i=0;i<words.size();i++){
            string temp=words[i];
            use[temp]++;
        }    
        
        //外层循环控制分组遍历
        for(int start=0;start<singlelen;start++){
            int pre=start;
            string str;
            // double points
            for(int i=start;i<=lens-singlelen;i+=singlelen){
                pre=pre>i?pre:i;
                while(pre+singlelen<=lens){
                    str=s.substr(pre,singlelen);
                    if(use.count(str)!=0&&use[str]!=0){
                        use[str]--;
                        count--;
                        pre+=singlelen;
                        if(count==0){
                            res.push_back(i);
                            break;
                        }
                    }
                    else{
                        break;
                    }
                }
                if(use.count(s.substr(i,singlelen))!=0){
                    use[s.substr(i,singlelen)]++;
                    count++;
                } 
            }
        }
        return res;
    }
};


//一个更快的方法
static const int size = 1<<15;
typedef unsigned int uint;

class Solution {
public:
    
    uint hash[size];
    uint pw;
    vector<int> res;
    
    int geth(int a, int n) {
        return hash[a+n] - hash[a]*pw;
    }
    
    void go(int start, vector<int> &a, vector<int> &need, int K, int total) {
        if (a.size()<total) return;
        
        vector<int> has(need.size(),0);
        int match=0;
        for (int i = 0; i < total-1; ++i) {
            if (has[a[i]]==need[a[i]]) --match;
            ++has[a[i]];
            if (has[a[i]]==need[a[i]]) ++match;
        }
        for (int i = total-1; i < a.size(); ++i) {
            if (has[a[i]]==need[a[i]]) --match;
            ++has[a[i]];
            if (has[a[i]]==need[a[i]]) ++match;
            //printf("  %d->%d\n", i-total+1, match);
            if (match==need.size()) res.push_back(start + K*(i-total+1));
            if (has[a[i-total+1]]==need[a[i-total+1]]) --match;
            --has[a[i-total+1]];
            if (has[a[i-total+1]]==need[a[i-total+1]]) ++match;
        }
    }
    
    
    vector<int> findSubstring(string s, vector<string>& w) {
        if (!w.size()) return {};
        assert(s.size()<size);
        
        int K = w[0].size();
        pw=1; 
        for (int i = 0; i < K; ++i) 
            pw = pw*47u;

        hash[0]=0; 
        for (int i = 0; i < s.size(); ++i) {
            hash[i+1] = hash[i]*47u + (uint)(s[i]-'a'+1);
        }
        unordered_map<uint, int> H;
        vector<int> need;
        for (int i = 0; i < w.size(); ++i) {

            uint h = 0;
            for (char c : w[i]) 
                h = h*47u + (uint)(c - 'a' + 1);

            if (!H.count(h)) {
                H[h]=need.size();
                need.push_back(0);
            }
            ++need[H[h]];
        }
        
        res.clear();
        for (int k = 0; k < w[0].size(); ++k) {
            vector<int> a;
            int start = k;
            for (int i = k; i+K <= s.size(); i+=K) {
                int h = geth(i,K);
                if (!H.count(h)) {
                    go(start,a,need,K,w.size());
                    start = i+K;
                    a.clear();
                } else {
                    a.push_back(H[h]);
                }
            }
            go(start, a, need, K, w.size());
        }
        
        return res;
    }
};