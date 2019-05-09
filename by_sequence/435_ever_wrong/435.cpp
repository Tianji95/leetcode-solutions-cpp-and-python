int mycompare(Interval& left, Interval& right) {
	return left.start < right.start;
}

class Solution {
public:
	int eraseOverlapIntervals(vector<Interval>& intervals) {
		int len = intervals.size();
		if (len == 0 || len == 1) {
			return 0;
		}
		sort(intervals.begin(), intervals.end(), mycompare);
		int count = 0;
        int pre = 0;
		for (int i = 1; i < intervals.size();i++) {
			if (intervals[i].start < intervals[pre].end) {
				count++;
                if (intervals[i].end < intervals[pre].end) pre = i;
			}
			else
                pre = i;
		}
        return count;
	}
};