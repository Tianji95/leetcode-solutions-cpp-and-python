受到之前动态规划的影响，这道题用了动态规划，反而慢了不少，如果用回溯的话会快很多

    class Solution {
    public:
        bool isMatch(string s, string p) {
            
            int pIndex = 0;
            int sIndex = 0;
            
            int temp_pIndex = -1;
            int temp_sIndex = -1;
            
            while(sIndex < s.length())
            {
                if(s[sIndex] == p[pIndex] || p[pIndex] == '?')
                {
                    pIndex++;
                    sIndex++;
                }
                else
                {
                    if(p[pIndex] == '*')
                    {
                        temp_pIndex = pIndex;
                        temp_sIndex = sIndex;
                        pIndex++;
                    }
                    else if(temp_pIndex >= 0)
                    {
                        pIndex = temp_pIndex+1;
                        sIndex = temp_sIndex+1;
                        
                        temp_sIndex++;
                    }
                    else
                    {
                        return false;
                    }
                }
            }
            
            while(pIndex < p.length() && p[pIndex] == '*')
            {
                pIndex++;
            }
            
            if(pIndex != p.length())
            {
                return false;
            }
            
            return true;
        }
    };
