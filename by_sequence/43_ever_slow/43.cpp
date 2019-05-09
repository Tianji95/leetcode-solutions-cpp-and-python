class Solution
{
public:
	string multiply(string num1, string num2)
	{
		int len1 = num1.size();
		int len2 = num2.size();

		int outArr[130][130];
		int tmp1, tmp2;

		int extra = 0;
		int tmpResult = 0;

		string out("");

		int count1 = 0;
		int count2 = 0;
		for (int i = len1 - 1; i >= 0; i--)
		{
			tmp1 = 0;
			for (int k = 1; k != 10000 && i >= 0; k *= 10)
			{
				tmp1 += k * (num1[i] - '0');
				i--;
			}
			i++;
			int extra = 0;
			count2 = 0;
			for (int j = len2 - 1; j >= 0; j--)
			{
				tmp2 = 0;
				for (int k = 1; k != 10000 && j >= 0; k *= 10)
				{
					tmp2 += k * (num2[j] - '0');
					j--;
				}
				j++;
				tmpResult = tmp1 * tmp2 + extra;
				extra = tmpResult / 10000;
				outArr[count1][count2] = tmpResult % 10000;
				count2++;
			}
			if (extra != 0)
			{
				outArr[count1][count2] = extra;
				count2++;
			}
			count1++;
		}
		int tmpout = 0;
		extra = 0;
		for (int i = 0; i < count1 + count2 -1; i++)
		{
			tmpout = 0;
			for (int j = 0; j <= i && j < count1; j++)
			{
				if (outArr[j][i - j] < 0)
					continue;

				tmpout = tmpout + outArr[j][i - j];
			}
			tmpout = tmpout + extra;
			extra = tmpout / 10000;
			auto resultS = to_string(tmpout % 10000);
			while (i < count1 + count2 - 2 && resultS.size() < 4)
			{
				resultS = "0" + resultS;
			}
			out = resultS + out;
		}
		if (extra != 0)
		{
			out = to_string(extra) + out;
		}
		return out;
	}
};