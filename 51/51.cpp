class Solution
{
public:
	void fillQueens(int idx, int n)
	{
		int colPos[100];
		int rightCross[100];
		int leftCross[100];

		for (int i = 0; i < n; i++)
		{
			if (idx == 0)
			{
				tmpoutIdx.clear();
			}
			if (!posArr[idx][i])
			{  //填idx行第n个格子
				if (idx == n - 1)
				{
					tmpoutIdx.push_back(i);
					out.push_back(tmpoutIdx);
                    tmpoutIdx.pop_back();
					continue;
				}

				for (int j = idx + 1; j < n; j++)
				{
					colPos[j] = posArr[j][i];
					posArr[j][i] = true;
					if (i + j - idx < n)
					{
						rightCross[j] = posArr[j][i + j - idx];
						posArr[j][i + j - idx] = true;
					}
					if (i + idx - j >= 0)
					{
						leftCross[j] = posArr[j][i + idx - j];
						posArr[j][i + idx - j] = true;
					}
				}
				tmpoutIdx.push_back(i);
				fillQueens(idx + 1, n);
				tmpoutIdx.pop_back();
				for (int j = idx + 1; j < n; j++)
				{
					if (i + idx - j >= 0)
					{
						posArr[j][i + idx - j] = leftCross[j];
					}

					if (i + j - idx < n)
					{
						posArr[j][i + j - idx] = rightCross[j];
					}
					posArr[j][i] = colPos[j];
				}
			}
		}

	}


	vector<vector<string>> solveNQueens(int n)
	{
		string     tmpstring(n, '.');
		vector<string> tmpout;
		vector<vector<string>> returnVal;

		fillQueens(0, n);

		for (int j = 0; j < out.size(); j++)
		{
			tmpout.clear();
			for (int i = 0; i < n; i++)
			{
				tmpstring[out[j][i]] = 'Q';
				tmpout.push_back(tmpstring);
				tmpstring[out[j][i]] = '.';
			}
			returnVal.push_back(tmpout);
		}
		return returnVal;
	}


	vector<int> tmpoutIdx;
	vector<vector<int>> out;

	bool posArr[100][100];
};