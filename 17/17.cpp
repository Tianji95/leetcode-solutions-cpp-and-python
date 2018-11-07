class Solution {
public:
    vector<string> letterCombinations(string digits) {
        map<char, string> strMap = {
            {'2', "abc"},
            {'3', "def"},
            {'4', "ghi"},
            {'5', "jkl"},
            {'6', "mno"},
            {'7', "pqrs"},
            {'8', "tuv"},
            {'9', "wxyz"}
        };
        
        int len = digits.size();
        vector<string> out;
        
        for(int i = 0; i < len; i++){
            int thisMapLen = (strMap[digits[i]]).size();
            int outLen = out.size();
            if(outLen!=0){
                vector<string> tmp = out;
                for(int k = 0; k < thisMapLen - 1; k++){
                    out.insert(out.end(), tmp.begin(), tmp.end());
                }
                int nowLen =  outLen * thisMapLen;
                for(int v = 0; v < nowLen; v++){
                    out[v] += strMap[digits[i]][v / outLen];
                }
            }
            else{
                for(int k = 0; k < thisMapLen; k++){
                    string tmp("");
					tmp = tmp + strMap[digits[i]][k];
					out.push_back(tmp);
                }
            }

            
        }
        return out;
    }
};