
一个不要脸的解法。。。。。

    class Solution {
    public:
        vector<vector<int>> permuteUnique(vector<int>& nums) {
            vector<vector<int>> ans;
            sort(nums.begin(),nums.end());
            do
            {
                ans.push_back(nums);
            }while(next_permutation(nums.begin(),nums.end()));
            return ans;
        }
    };

一个比较快的正常的解法：

    class Solution {
    public:
        void recursion(vector<int> num, int i, int j, vector<vector<int> > &res) {
            if (i == j-1) {
                res.push_back(num);
                return;
            }
            for (int k = i; k < j; k++) {
                if (i != k && num[i] == num[k]) continue;
                swap(num[i], num[k]);
                recursion(num, i+1, j, res);
            }
        }
        vector<vector<int> > permuteUnique(vector<int> &num) {
            sort(num.begin(), num.end());
            vector<vector<int> >res;
            recursion(num, 0, num.size(), res);
            return res;
        }
    };