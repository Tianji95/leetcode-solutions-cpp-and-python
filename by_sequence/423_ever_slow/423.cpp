class Solution
{
public:
	
	string originalDigits(string s)
	{
		vector<int> charCount(26, 0);
		string out("");
		int len = s.size();

		for (int i = 0; i < len; i++)
		{
			charCount[s[i] - 'a']++;
		}

		vector<int> numcount(10, 0);
		numcount[0] = charCount['z' - 'a'];
		numcount[2] = charCount['w' - 'a'];
		numcount[4] = charCount['u' - 'a'];
		numcount[8] = charCount['g' - 'a'];
		numcount[3] = charCount['t' - 'a'] - numcount[2] - numcount[8];
		numcount[1] = charCount['o' - 'a'] - numcount[0] - numcount[2] - numcount[4];
		numcount[6] = charCount['x' - 'a'];
		numcount[7] = charCount['s' - 'a'] - numcount[6];
		numcount[5] = charCount['v' - 'a'] - numcount[7];
		numcount[9] = charCount['i' - 'a'] - numcount[5] - numcount[6] - numcount[8];

		for (int i = 0; i < 10; i++)
		{
			for (int j = 0; j < numcount[i]; j++)
			{
				out.push_back('0'+i);
			}
		}
		
		return out;
	}
};