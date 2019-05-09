class Myhash {
    public:
    size_t operator () (tuple<int, int> const &t) const {
        return get<0>(t) + get<1>(t);
    }
};
class Solution {
public:
    int maxPoints(vector<Point>& points) {
        if (points.size() == 0) return 0;
        int retval = 0;
        for(int i = 0 ; i < points.size(); ++i) {
            unordered_map<tuple<int, int>, int, Myhash> hashmap;
            int samepoints = 0;
            for(int j = i+1; j < points.size(); ++j) {
                if (points[i].x == points[j].x && \
                    points[i].y == points[j].y) {
                    samepoints++;
                }
                else if (points[i].x == points[j].x) {
                    hashmap[make_tuple(INT_MAX,1)]++;
                }
                else {
                    int num = (points[i].y - points[j].y) ;
                    int den = (points[i].x - points[j].x);
                    int GCD = __gcd(num, den);
                    num /= GCD;
                    den /= GCD;
                    hashmap[make_tuple(num, den)]++;
                }
            }
            int localmax = 0;
            for(auto &n : hashmap) {
                localmax = max(localmax, n.second);
            }
            localmax += samepoints;
            retval = max(retval, localmax+1);
        }
        return retval;
    }
};