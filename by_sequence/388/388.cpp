class Solution {
public:
	int lengthLongestPath(string input) {
		stack<string> stk;

		int len = input.size();
		int maxLen = 0;
		int nowLen = 0;

		int lastIdx = 0;
		int tabcount = 0;

		for (int i = 0; i < len; i++) {
			if (input[i] == '\n') {
				string ss = input.substr(lastIdx, i - lastIdx);
				lastIdx = i + 1;
				while (tabcount < stk.size()) {
					string tmps = stk.top();
					nowLen -= (tmps.size() + 1);
					stk.pop();
				}

				if (tabcount >= stk.size()) {
					stk.push(ss);
					nowLen += ss.size() + 1;
					if (nowLen > maxLen && ss.find(".") != string::npos) {
						maxLen = nowLen - 1;
					}
				}
				tabcount = 0;
			}
			else if (input[i] == '\t') {
				lastIdx = i + 1;
				tabcount++;
			}
		}

		string ss = input.substr(lastIdx, len - lastIdx);
		lastIdx = len + 1;
		while (tabcount < stk.size()) {
			string tmps = stk.top();
			nowLen -= (tmps.size() + 1);
			stk.pop();
		}

		if (tabcount >= stk.size()) {
			stk.push(ss);
			nowLen += ss.size() + 1;
			if (nowLen > maxLen && ss.find(".") != string::npos) {
				maxLen = nowLen - 1;
			}
		}

		return maxLen;
	}
};