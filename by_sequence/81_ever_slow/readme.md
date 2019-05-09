这道题其实还是有些麻烦的，，，这里面用的方法是优先2分，然后实在都一样的话就用暴力搜素

    class Solution {
    public:
        bool search(vector<int>& a, int t) {
            int s=0, e=a.size()-1;
            while(e-s+1>=3) {
                int m=s+(e-s)/2;
                if (t==a[m]) return true;
                if (a[s]==a[m] && a[m]==a[e]) break;
                else if (a[s]<a[m]) {
                    if (t>=a[s] && t<a[m]) e=m-1;
                    else s=m+1;
                }
                else if(a[s]>a[m]) {
                    if (t>=a[s] || t<a[m]) e=m-1;
                    else s=m+1;
                }
                else if (a[e]>a[m]) {
                    if (t>a[m] && t<=a[e]) s=m+1;
                    else e=m-1;
                }
                else if(a[e]<a[m]) {
                    if (t>a[m] || t<=a[e]) s=m+1;
                    else e=m-1;
                }            
            }
            
            for (int i=s; i<=e; ++i) {
                if (a[i]==t) return true;
            }
            return false;
        }
    };