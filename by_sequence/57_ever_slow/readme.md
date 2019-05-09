 一段更简洁并且更容易理解的代码   
    
    class Solution {
    public:
        vector<Interval> insert(vector<Interval>& intervals, Interval n) {
            vector<Interval> sol;
            int i = 0;
            while (i < intervals.size()&& intervals[i].end < n.start) {
                sol.push_back(intervals[i++]);
            }
            
            while (i < intervals.size() && n.end >= intervals[i].start) {
                n.start = min(n.start, intervals[i].start);
                n.end = max(n.end, intervals[i++].end);
            }
            
            sol.push_back(n);
            
            while (i < intervals.size()) {
                sol.push_back(intervals[i++]);
            }
            
            return sol;
        }
    };