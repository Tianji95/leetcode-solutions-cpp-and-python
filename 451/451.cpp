class Solution {
public:
    string frequencySort(string s) {
        vector<int> v(126, 0);
        int len = s.size();
        string out("");
        
        for(int i = 0; i < len; i++){
            v[s[i]]++;
        }
        vector<int> b(126,0);
        for(int i = 0; i < 126; i++){
            b[i] = i;
        }
        
        for(int i = 0; i < 125; i++){
            for(int j = i+1; j < 126; j++){
                if(v[i]<v[j]){
                    swap(v[i], v[j]);
                    swap(b[i], b[j]);
                }
            }
        }
        
        for(int i = 0; i < 126;i++){
            if(v[i]!=0){
                for(int j = 0; j < v[i]; j++){
                    out.push_back(b[i]);
                }
            }
        }
        return out;
        
    }
};