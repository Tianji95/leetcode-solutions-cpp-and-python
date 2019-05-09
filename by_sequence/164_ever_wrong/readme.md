这里面用到的是桶排序，其实看到linear 的time/space 已经能够想到桶排序了，不过因为实在用得少，手生了，发现不太会写

在这里面，把认为所有的数字的平均gap是最大数-最小数/数的个数，然后桶的数量就是最大数-最小数除以gap，这两个桶里面存放范围为gap的n个数，把这n个数的最大值和最小值放在里面，当然也有可能出现的情况时，所有的数都在同一个桶里面，也就是同一个gap里面，不过我们只需要吧max-min就可以了，代码见另外一个文件



    class Solution {
    public:
        int maximumGap(vector<int>& nums) {
            if(nums.size()<2)
                return 0;
            priority_queue<int, vector<int>> pq(nums.begin(), nums.end());
            int diff=0;
            while(!pq.empty()){
                int a = pq.top();
                pq.pop();
                int b;
                if(!pq.empty())
                    b = pq.top();
                
                diff = max(diff, abs(a-b));
            }
            return diff;
        }
    };