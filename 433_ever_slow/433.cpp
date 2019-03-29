class Solution {
public:
	int minMutation(string start, string end, vector<string>& bank) {
		queue<string> Q;
		Q.push(start);

		set<string> visited;
		set<string> bankSet;

		for (auto b : bank) {
			bankSet.insert(b);
		}

		vector<char> geneList = { 'A', 'C', 'G', 'T' };
		int times = 0;

		while (!Q.empty()) {
			int size = Q.size();
			while (size-- > 0) {
				auto now = Q.front();
				if (now == end) {
					return times;
				}
				Q.pop();

				for (int i = 0; i < now.size(); i++) {
					auto old = now[i];
					for (auto c : geneList) {
						now[i] = c;
						if (bankSet.find(now) != bankSet.end() && visited.find(now) == visited.end()) {
							Q.push(now);
							visited.insert(now);
						}
					}
					now[i] = old;
				}
			}
			times++;
		}
		return -1;
	}
};