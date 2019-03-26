bool mysort(pair<int, int> l, pair<int, int> r){
    if(l.first == r.first){
        return l.second < r.second;
    }
    return l.first > r.first;
}
class Solution {
public:

    vector<pair<int, int>> reconstructQueue(vector<pair<int, int>>& people) {
        vector<pair<int, int>> out;
        int len = people.size();
        
        sort(people.begin(), people.end(), mysort);
        
        for(int i = 0; i < len; i++){
            int pos = people[i].second;
            out.insert(out.begin()+pos, people[i]);
        }
        
        return out;
    }
};