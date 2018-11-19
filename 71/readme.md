还有一种方法是把字符串用split 把字符串用/分开，然后删除掉空的（连续两个/），然后用字符串相等来进行运算
    
    class Solution {
    public:
        string simplifyPath(string path) {
            int p1 = 0, p2 = 0;
            while (p2 < path.length()) {
                int st = p2;
                while (p2 < path.length() && path[p2] != '/') p2++;
                string tmp = path.substr(st, p2 - st);
                if (tmp == "..") {
                    if (p1 != 0) {
                        while(p1-- >= 0 && path[p1] != '/');
                    } 
                } else if (tmp.length() != 0 && tmp != ".") {
                    path[p1++] = '/';
                    for (int i = 0; i < tmp.length(); i++) {
                        path[p1++] = tmp[i];
                    }
                }
                p2++;
            }
            path = path.substr(0, p1).empty() ? "/" : path.substr(0, p1);
            return path;
        }
    };