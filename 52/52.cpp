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
				tmpCount = 0;
			}
			if (!posArr[idx][i])
			{  //填idx行第n个格子
				if (idx == n - 1)
				{
					tmpCount++;
					count++;
                    tmpCount--;
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
				tmpCount++;
				fillQueens(idx + 1, n);
				tmpCount--;
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


	int totalNQueens(int n)
	{
        count = 0;
        tmpCount = 0;
		fillQueens(0, n);
        return count;
	}


	int tmpCount;
    int count;

	bool posArr[100][100];
};