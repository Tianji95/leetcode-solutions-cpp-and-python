bool mysort(pair<int, int>& left, pair<int, int>& right){
    if(left.second == right.second){
        return left.first < right.first;
    }
    return left.second < right.second;
}

class Solution {
public:
    int findMinArrowShots(vector<pair<int, int>>& points) {
        int len = points.size();
        sort(points.begin(), points.end(), mysort);
        int count = 0;
        int now = INT_MIN;
        
        for(int i = 0; i < len; i++){
            if(points[i].first > now || now==INT_MIN){
                count++;
                now = points[i].second;
            }
            
        }
        
        return count;
    }
};