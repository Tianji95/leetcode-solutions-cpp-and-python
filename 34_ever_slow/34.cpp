class Solution {
public:
    vector<int> findIdx(vector<int>&nums, int left, int right, int target){
        int len = right - left + 1;
        vector<int> out;
        if(len == 1){
            if(nums[left] == target){
                out.push_back(left);
                out.push_back(left);
                return out;
            }
            else{
                out.push_back(-1);
                out.push_back(-1);
                return out;
            }
        }
        else if(len==2){
            if(nums[left] == target){
                out.push_back(left);
            }
            if(nums[right] == target){
                out.push_back(right);
            }
            if(out.size()==0){
                out.push_back(-1);
                out.push_back(-1);
            }
            else if(out.size()==1){
                out.push_back(out[0]);
            }
            return out;
        }
        
        int middle = nums[left + len/2];
        if(middle < target){
            out = findIdx(nums, left + len/2, right, target);
        }
        else if(middle > target){
            out = findIdx(nums,0, left + len/2, target);
        }
        else{
            vector<int> tmpoutleft;
            vector<int> tmpoutright;
            tmpoutleft = findIdx(nums,left, left + len/2, target);
            tmpoutright= findIdx(nums, left + len/2, right, target);
            out.push_back(tmpoutleft[0]);
            out.push_back(tmpoutright[1]);
        }
        return out;
    }
    vector<int> searchRange(vector<int>& nums, int target) {
        int len = nums.size();
        vector<int> out;
        if(len == 0){
            out.push_back(-1);
            out.push_back(-1);
            return out;
        }
        else if(len == 1){
            if(nums[0] == target){
                out.push_back(0);
                out.push_back(0);
                return out;
            }
            else{
                out.push_back(-1);
                out.push_back(-1);
                return out;
            }
        }
        
        if(target < nums[0] || target>nums[len-1]){
            out.push_back(-1);
            out.push_back(-1);
            return out;
        }
        
        int middle = nums[len/2];
        if(middle < target){
            out = findIdx(nums, len/2+1, len-1, target);
        }
        else if(middle > target){
            out = findIdx(nums,0, len/2-1, target);
        }
        else{
            vector<int> tmpoutleft;
            vector<int> tmpoutright;
            tmpoutleft = findIdx(nums,0, len/2, target);
            tmpoutright= findIdx(nums, len/2, len-1, target);
            out.push_back(tmpoutleft[0]);
            out.push_back(tmpoutright[1]);
        }
        return out;
    }
};