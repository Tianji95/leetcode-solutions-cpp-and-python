class Solution {
public:
	vector<int> topKFrequent(vector<int>& nums, int k) {
		unordered_map<int, int> mp;
		int len = nums.size();
		vector<int> out;

		for (int i = 0; i < len; i++) {
			mp[nums[i]]++;
		}

		priority_queue<pair<int, int>> pq;
		for (auto num : mp) {
			pq.push(make_pair(num.second, num.first));
		}

		for (int i = 0; i < k; i++) {
			auto topItem = pq.top();
			pq.pop();
			out.push_back(topItem.second);
		}
		return out;
	}
};