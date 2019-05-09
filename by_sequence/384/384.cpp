class Solution {
public:
	Solution(vector<int> nums) {
		vec = nums;
		shuf = nums;
		srand(time(nullptr));
	}

	/** Resets the array to its original configuration and return it. */
	vector<int> reset() {
		return vec;
	}

	/** Returns a random shuffling of the array. */
	vector<int> shuffle() {

		for (int i = 0; i < shuf.size(); i++)
		{
			int index = (RAND_MAX - rand()) % vec.size();
			int curr = shuf[i];
			shuf[i] = shuf[index];
			shuf[index] = curr;
		}

		return shuf;
	}
private:
	vector<int> vec;
	vector<int> shuf;
};