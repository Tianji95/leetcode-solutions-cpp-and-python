这道题主要慢在我的vector以及暴力编码上面了，下面是比较快的解法

    class Solution {
    public:
        vector<vector<int>> res;
        
        void fun(vector<int> nums,int pos)
        {
            int i;
            int n=nums.size();
            if(pos==n)
            {
                res.push_back(nums);
                return;
            }
            for(i=pos;i<n;i++)
            {
                swap(nums[i],nums[pos]);
                fun(nums,pos+1);
            }
        }
        
        vector<vector<int>> permute(vector<int>& nums) {
            fun(nums,0);
            return res;
        }
    };