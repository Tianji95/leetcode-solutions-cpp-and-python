bool mysort(Interval left, Interval right){
    return left.start < right.start;
}
class Solution {
public:

    vector<Interval> merge(vector<Interval>& intervals) {
        vector<Interval> out;
        int len = intervals.size();
        if(len == 0 || len == 1)
            return intervals;
        std::sort(intervals.begin(), intervals.end(), mysort);
        
        int prevStart = intervals[0].start;
        int prevEnd = intervals[0].end;
        int prevIdx = 0;
        out.push_back(intervals[0]);
        
        for(int i = 1; i < len; i++){
            if(intervals[i].start <= prevEnd){
                if(intervals[i].end > prevEnd){
                    out[prevIdx].end = intervals[i].end;
                    prevEnd = out[prevIdx].end;
                }
            }
            else{
                out.push_back(intervals[i]);
                prevIdx++;
                prevEnd = intervals[i].end;
                prevStart = intervals[i].start;
            }
        }
        return out;
        
    }
};