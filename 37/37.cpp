class Solution
{
	bool FillBoard(vector<vector<char>>& board, int row, int col, int index, vector<pair<int, int>>& blankPos)
	{
		bool notFilled = true;
		bool rowCanInsert[9];
		bool colCanInsert[9];
		bool blockCanInsert[9];

		if (index >= blankPos.size())
			return true;

		for (int i = 0; i < 9; i++)
		{
			auto tmp = canInsert[row][col];
			if (canInsert[row][col][i])
			{
				memset(rowCanInsert, 1, sizeof(rowCanInsert));
				memset(colCanInsert, 1, sizeof(colCanInsert));
				memset(blockCanInsert, 1, sizeof(blockCanInsert));
				
				board[row][col] = '0'+i+1;
				//把这个一行所有的这个数置为true;
				for (int j = 0; j < 9; j++)
				{
					colCanInsert[j] = canInsert[row][j][i];
					canInsert[row][j][i] = 0;
				}

				//把这个一列所有的这个数置为true;
				for (int j = 0; j < 9; j++)
				{
					rowCanInsert[j] = canInsert[j][col][i];
					canInsert[j][col][i] = 0;
				}

				//所有的block里面把这个数置为true
				int leftbound = col / 3;
				int upbound = row / 3;

				for (int j = leftbound * 3; j < leftbound * 3 + 3; j++)
				{
					for (int k = upbound * 3; k < upbound * 3 + 3; k++)
					{
						int index = j - leftbound * 3 + (k - upbound * 3) * 3;
						blockCanInsert[index] = canInsert[k][j][i];
						canInsert[k][j][i] = 0;
					}
				}
				if (index + 1 >= blankPos.size())
					return true;
				bool iscomplete = FillBoard(board, blankPos[index + 1].first, blankPos[index + 1].second, index + 1, blankPos);
				if (iscomplete == true)
				{
					return true;
				}
					
				if (row == 0 && col == 3)
				{
					cout << 11 << endl;
				}

				for (int j = leftbound * 3; j < leftbound * 3 + 3; j++)
				{
					for (int k = upbound * 3; k < upbound * 3 + 3; k++)
					{
						int index = j - leftbound * 3 + (k - upbound * 3) * 3;
						canInsert[k][j][i] = blockCanInsert[index];
					}
				}

				//把这个一列所有的这个数置为true;
				for (int j = 0; j < 9; j++)
				{
					canInsert[j][col][i] = rowCanInsert[j];
				}

				for (int j = 0; j < 9; j++)
				{
					canInsert[row][j][i] = colCanInsert[j];
				}

			}
		}
		return false;
	}
public:
	bool canInsert[9][9][9];
	void solveSudoku(vector<vector<char>>& board)
	{
		vector<pair<int, int>> blankPos;
		memset(canInsert, 1, sizeof(canInsert));

		for (int row = 0; row < 9; row++)
		{
			for (int col = 0; col < 9; col++)
			{
				if (board[row][col] == '.')
				{
					blankPos.push_back(make_pair(row, col));
					//搜索行
					for (int i = 0; i < 9; i++)
					{
						if (board[row][i] <= '9' && board[row][i] > '0')
						{
							canInsert[row][col][board[row][i] - '1'] = 0;
						}
					}
					//搜索列
					for (int i = 0; i < 9; i++)
					{
						if (board[i][col] <= '9' && board[i][col] > '0')
						{
							canInsert[row][col][board[i][col] - '1'] = 0;
						}
					}
					//搜索块
					int leftbound = col / 3;
					int upbound = row / 3;
					for (int i = leftbound * 3; i < leftbound * 3 + 3; i++)
					{
						for (int j = upbound * 3; j < upbound * 3 + 3; j++)
						{
							if (board[j][i] <= '9' && board[j][i] > '0')
							{
								canInsert[row][col][board[j][i] - '1'] = 0;
							}
						}
					}
				}
			}
		}
		auto blankPosSize = blankPos.size();
		if (blankPos.size() != 0)
		{
			FillBoard(board,  blankPos[0].first, blankPos[0].second, 0, blankPos);
		}
		

	}
};