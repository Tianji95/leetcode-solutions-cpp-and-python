class Solution
{
public:
	bool isMatch(string s, string p)
	{
        bool dpArray[100][100] = { false }; 
		int strLen = s.size();
		int regLen = p.size();

        dpArray[strLen][regLen] = true;
		for (int ss = strLen; ss >= 0; ss--)
		{
			for (int rr = regLen - 1; rr >= 0; rr--)
			{
                bool fontMatch = (ss < strLen && (p[rr] == s[ss])||p[rr]=='.');
				if(rr + 1 < regLen && p[rr+1] == '*'){
                    dpArray[ss][rr] = dpArray[ss][rr+2] || (fontMatch && dpArray[ss+1][rr]);
                }
                else{
                    dpArray[ss][rr] = (fontMatch && dpArray[ss+1][rr+1]);
                }
			}
		}
		return dpArray[0][0];
	}
};