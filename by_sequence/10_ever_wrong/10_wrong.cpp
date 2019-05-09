class Solution
{
public:
	bool isMatch(string s, string p)
	{
		int oriIdx = 0;
		int regIdx = 0;
		int lenStr = s.size();
		int lenReg = p.size();
		int isAsterisk = false;
		char lastC;

		for (oriIdx = 0; oriIdx < lenStr; )
		{

			if ((s[oriIdx] != p[regIdx]) && (p[regIdx] != '.'))
			{
				if (p[regIdx] == '*')
				{
					isAsterisk = true;
					lastC = p[regIdx - 1];
					regIdx++;
				}
				else if (isAsterisk)
				{
					if ((s[oriIdx] != lastC) && lastC != '.')
					{
						return false;
					}
					oriIdx++;
				}
				else
				{
					//第一个字符不相等
					if ((regIdx + 1 < lenReg) && p[regIdx + 1] == '*')
					{
						regIdx++;
					}
					else if (p[regIdx] == '.')
					{
						oriIdx++;
						regIdx++;
					}
					else
						return false;
				}

			}
			else
			{
				if (isAsterisk)
				{
					if ((s[oriIdx] != lastC) && lastC != '.')
					{
						isAsterisk = false;
						oriIdx++;
						regIdx++;
					}
					else
					{
						oriIdx++;
					}
				}
				else
				{
					isAsterisk = false;
					oriIdx++;
					regIdx++;
				}

			}

		}

		if (regIdx < lenReg && !isAsterisk)
		{
			return false;
		}
		while (regIdx < lenReg)
		{
			if (p[regIdx] != '*')
			{
				if ((regIdx + 1 < lenReg) && p[regIdx + 1] != '*')
					return false;
				else if (regIdx + 1 >= lenReg)
					return false;
			}
			else
			{
				isAsterisk = true;
				lastC = p[regIdx - 1];
				regIdx++;
			}
		}
		return true;
	}
};