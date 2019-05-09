class Solution {
public:
	string minWindow(string s, string t) {
		int left = 0;
		int right = 0;
		std::unordered_map<char, int> tMap;
		std::unordered_map<char, int> sMap;

		string out;

		int tLen = t.size();
		int sLen = s.size();
		if (sLen == 0)
			return "";
		if (tLen == 0)
			return "";
		if (sLen == 1 && tLen == 1) {
			if (s[0] == t[0])
				return s;
			else
				return "";
		}

		for (int i = 0; i < tLen; i++) {
			if (tMap.find(t[i]) != tMap.end()) {
				tMap[t[i]]++;
			}
			else {
				tMap.insert(make_pair(t[i], 1));
			}
		}

		int totalChars = tMap.size();

		int schars = 0;
		int finalLeft = 0;
		int finalRight = sLen + 1;

		bool check = false;

		while (right < sLen) {
			if (tMap.find(s[right]) != tMap.end()) {
				sMap[s[right]]++;
				check = true;
				for (auto tMapIter : tMap) {
					if (sMap.find(tMapIter.first) == sMap.end() || tMapIter.second > sMap[tMapIter.first]) {
						check = false;
						break;
					}
				}
			}




			if (check) {
				if (finalRight - finalLeft > right - left) {
					finalLeft = left;
					finalRight = right;
				}
				while (left <= right) {
					if (tMap.find(s[left]) != tMap.end()) {
						if (finalRight - finalLeft > right - left) {
							finalLeft = left;
							finalRight = right;
						}
						sMap[s[left]]--;

						check = true;
						for (auto tMapIter : tMap) {
							if (sMap.find(tMapIter.first) == sMap.end() || tMapIter.second > sMap[tMapIter.first]) {
								check = false;
								break;
							}
						}
						if (!check) {
							sMap[s[left]]++;
							break;
						}
					}
					left++;

				}
			}
			right++;
		}
		if (finalLeft == 0 && finalRight == sLen + 1) {
			return "";
		}
		else {
			return s.substr(finalLeft, finalRight - finalLeft + 1);
		}

	}
};