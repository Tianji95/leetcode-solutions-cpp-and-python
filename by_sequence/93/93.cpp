class Solution {
public:
    void storeS(string& s, int depth, int idx, vector<int>& idxVector){
        if(depth == 4){
            int idxSize = idxVector.size();
            if(idx == len && idxSize == 4 &&idxVector[3] == len-1){
                string insertS = s;
                for(int i = 0; i < 3; i++){
                    insertS.insert(insertS.begin()+idxVector[i]+i+1, '.');
                }
                out.push_back(insertS);
            }
            return;
        }

        for(int i = idx; i < len; i++){
            
            int num = atoi(s.substr(idx, i-idx+1).c_str());
            if(s[idx]=='0' && i-idx>0)
                break;
            if(num >= 0 && num <= 255){
                idxVector.push_back(i);
                storeS(s, depth+1, i+1, idxVector);
                idxVector.pop_back();
            }
            else if(num > 255)
                break;
        }
    }
    
    vector<string> restoreIpAddresses(string s) {
        len = s.size();
        vector<int> idxVector;
        storeS(s, 0, 0, idxVector);
        return out;
        
    }
    int len;
    vector<string> out;
};