这里面应该搜索的是target+1和target的位置，这样就可以省去所有copy vector的开销了，再二分的时候只需要获得两个最开始出现的位置就行了，sample代码如下：
    
    class Solution {
    public:
        vector<int> searchRange(vector<int>& nums, int target) {
            vector<int> res(2, -1);
            if (nums.empty()) return res;
            int left = lowboundBS(target, nums);
            if (left == nums.size() || nums[left] != target) return res;
            res[0] = left;
            int right = lowboundBS(target + 1, nums) - 1;
            res[1] = right;
            return res;
        }
        
        int lowboundBS(int target, vector<int>& nums) {
            int left = 0, right = nums.size();
            while (left < right) {
                int mid = left + (right - left) / 2;
                if (target <= nums[mid]) right = mid;
                else left = mid + 1;
            }
            return left;
        }
    };