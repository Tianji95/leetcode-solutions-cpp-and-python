class Solution {
public:
    void getSubParenth(string s, int maxN, int left, int right){
        
        if(s.size() == 2 * maxN){
            out.push_back(s);
        }

        if(left < maxN)
            getSubParenth(s+"(", maxN, left+1, right);
        if(right<left)
            getSubParenth(s+")", maxN, left, right+1);

    }
    vector<string> generateParenthesis(int n) {
        getSubParenth("",n, 0, 0);
        return out;
    }
    vector<string> out;
};