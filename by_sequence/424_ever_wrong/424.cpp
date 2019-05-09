class Solution
{
public:
	int characterReplacement(string s, int k)
	{
		int len = s.size();
		if (len == 0 || len == 1)
			return len;

		int left = 0;
		int right = 0;

		int out = INT_MIN;
		int maxCount = 0;

		vector<int> count(26, 0);

		for (right=0; right < len; right++)
		{
			maxCount = max(maxCount, ++count[s[right]-'A']);
			while (right - left + 1 - maxCount > k)
			{
				count[s[left++] - 'A']--;
			}
			out = max(out, right - left + 1);
		}
		return out;
	}
};