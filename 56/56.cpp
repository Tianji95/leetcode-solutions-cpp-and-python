/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
class Solution {
public:
    bool mysort(Interval left, Interval right){
        return left.start < right.start;
    }
    vector<Interval> merge(vector<Interval>& intervals) {
        vector<Interval> out;
        int len = intervals.size();
        if(len == 0 || len == 1)
            return intervals;
        std::sort(intervals.begin(), intervals.end(), mysort);
        for(int i = 0; i < len; i++){
            
        }
        
    }
};