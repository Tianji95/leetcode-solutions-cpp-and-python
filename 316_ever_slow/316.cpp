class Solution {
public:
    string removeDuplicateLetters(string s) {
        vector<int>  Ctimes(26, 0);
        vector<bool> isVisited(26, false);
        for(auto c : s){
            Ctimes[c-'a']++;
        }
        
        string out="";
        for(auto c:s){
            Ctimes[c-'a']--;
            if(isVisited[c-'a']) continue;
            while(out.size()!=0&&c < out.back() && Ctimes[out.back()-'a']!=0){
                isVisited[out.back()-'a'] = false;
                out.pop_back();
            }
            out.push_back(c);
            
            isVisited[c-'a'] = true;
        }
        return out;
    }
};