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
    vector<int> findRightInterval(vector<Interval>& intervals) {
        int len = intervals.size();
        map<int, int> mp;
        vector<int> out;
        
        for(int i = 0; i < len; i++){
            mp[intervals[i].start] = i;
        }
        
        for(int i = 0; i < len; i++){
            auto it = mp.lower_bound(intervals[i].end);
            if(it == mp.end()){
                out.push_back(-1);
                continue;
            }
            
                out.push_back(it->second);
            
        }
        
        return out;
    }
};