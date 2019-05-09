class Solution(object):
    def lengthOfLongestSubstring(self, s):
        """
        :type s: str
        :rtype: int
        """
        maxSubLen = 0
        nowSubStr = ""
        nowSubLen = 0
        for idx in range(len(s)):
            tmpSubStr = None
            for subIdx in range(nowSubLen):
                if s[idx] is nowSubStr[subIdx]:
                    tmpSubStr = nowSubStr[subIdx+1:nowSubLen] + s[idx]
            nowSubStr = nowSubStr + s[idx]
            nowSubLen = len(nowSubStr)
            if tmpSubStr:
                nowSubStr = tmpSubStr 
                nowSubLen = len(tmpSubStr)
                
            if maxSubLen < nowSubLen:
                maxSubLen = nowSubLen
        return maxSubLen
            
                
                