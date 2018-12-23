class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        vector<string> ret;
        bitset<1<<20> flag1;
        bitset<1<<20> flag2;
        int code=0;
        for(int i = 0;i<10;i++)
        {
            code = (code<<2) |  ecode(s[i]);
        }
        flag1.set(code);
        const int mask = (1<<20)-1;
        for(int i = 10;i<s.length();i++)
        {
            code = ((code<<2)&mask) | ecode(s[i]);
            if(flag2[code]) continue;
            else if(flag1[code])
            {
                flag2.set(code);
                ret.push_back(s.substr(i-9,10));
            }
            else
            {
                flag1.set(code);
            }
        }
        
        return ret;
    }
    
    int ecode(char c)
    {
        switch(c)
        {
            case 'A':return 0;
            case 'C':return 1;
            case 'G':return 2;
            case 'T':return 3;
            default:return 1;
        }
    }
    
    char decode(int code)
    {
        switch(code)
        {
            case 0:return 'A';
            case 1:return 'C';
            case 2:return 'G';
            case 3:return 'T';
            default:return 'A';
        }
    }
};