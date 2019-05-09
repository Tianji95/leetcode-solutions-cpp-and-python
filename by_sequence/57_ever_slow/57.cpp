class Solution {
public:
    vector<Interval> insert(vector<Interval>& intervals, Interval newInterval) {
        vector<Interval> out;
        int len = intervals.size();
        if(len == 0){
            intervals.push_back(newInterval);
            return intervals;
        }
        bool isInsert = false;
        //std::sort(intervals.begin(), intervals.end(), [](auto&& left, auto&& right){return left.start < right.start});
        for(int i = 0; i < len; i++){
            if(newInterval.start <= intervals[i].end && newInterval.end >= intervals[i].start){
                newInterval.start = min(newInterval.start, intervals[i].start);
                newInterval.end = max(newInterval.end, intervals[i].end);
                isInsert = true;
            }
            else if(i+1<len && newInterval.start > intervals[i].end && newInterval.end < intervals[i+1].start){
                out.push_back(intervals[i]);
                out.push_back(newInterval);
            }
            else{
                if(isInsert){
                    out.push_back(newInterval);
                    isInsert = false;
                }
                out.push_back(intervals[i]);
            }
        }
        if(isInsert || newInterval.start > intervals[len-1].end)
            out.push_back(newInterval);
        if(newInterval.end < intervals[0].start)
            out.insert(out.begin(), newInterval);
        return out;
        
    }
};