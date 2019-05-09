class Solution {
public:
	string convert(string s, int numRows) {
		vector<string> strArr;
		int pointer = 0;
		bool isDown = true;
        
		if (numRows == 1) {
			return s;
		}

		for (int i = 0; i < s.size(); i++) {
			int idxArr = i % numRows;
			if (strArr.size() <= idxArr) {
				string firstStr(1, s[i]);
				strArr.push_back(firstStr);
				pointer = idxArr;
			}
			else {
				if (isDown) {
					pointer++;
				}
				else {
					pointer--;
				}
				string thisStr(1, s[i]);
				strArr[pointer] += thisStr;

			}
			if (pointer == numRows - 1 || (pointer == 0 && i!=0)) {
				isDown = !isDown;
			}
		}

		//拼接str
		string outStr("");
		for (auto str : strArr) {
			outStr = outStr + str;
		}
		return outStr;
	}
};