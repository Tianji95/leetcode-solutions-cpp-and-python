#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <unordered_map>
#include <algorithm>
#include <list>
#include <stack>
#include <set>
#include <numeric>
#include <unordered_set>
using namespace std;

struct ListNode
{
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}

};

struct CompClass
{
	bool operator()(const int& left, const int& right) {
		return left < right;
	}
};
/*
test cases
1


*/


int main() {
	//CompClass mycompare;
	//vector<int> test = { 1,45,6,7,1,34 };
	//sort(test.begin(), test.end(), mycompare);
	
	int T;
	cin >> T;
	for (int i = 1; i <= T; i++)
	{
		int R, C, K;
		int out = 0;
		cin >> R >> C >> K;
		vector<vector<int>> square(R, vector<int>(C, 0));
		vector<vector<int>> dp(R, vector<int>(C, 0));
		for (int r = 0; r < R; r++)
		{
			for (int c = 0; c < C; c++)
			{
				cin >> square[r][c];
			}
		}

		int maxval = 0;
		int minval = 2147483647;

		for (int r = 0; r < R; r++)
		{
			for(int left = 0; left < C; left++){
				maxval = square[r][left];
				minval = square[r][left];
				int right = left + 1;
				for (; right < C; right++)
				{
					maxval = max(maxval, square[r][right]);
					minval = min(minval, square[r][right]);
					if (maxval - minval > K)
					{
						break;
					}
					
				}
				dp[r][left] = right - left;
			}
		}
		for (int c = 0; c < C; c++)
		{
			for (int top = 0; top < R; top++)
			{
				minval = dp[top][c];
				for (int bottom = top; bottom < R; bottom++)
				{
					minval = min(dp[bottom][c], minval);
					out = max(out, minval * (bottom - top + 1));
				}
			}
		}
		cout << "Case #" << i << ": " << out << endl;
	}
	return 0;
}