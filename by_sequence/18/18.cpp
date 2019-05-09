class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> out;
        int len = nums.size();
        std::sort(nums.begin(), nums.end());
        
        for(int i = 0; i < len - 3; i++){
            if(i>0&&nums[i]==nums[i-1]) continue;
            if(nums[i]+nums[i+1]+nums[i+2]+nums[i+3]>target) break;
            if(nums[i]+nums[len-3]+nums[len-2]+nums[len-1]<target) continue;
            
            for(int j = i + 1; j < len - 2; j++){
                if(j>i+1&&nums[j]==nums[j-1]) continue;
                if(nums[i]+nums[j]+nums[j+1]+nums[j+2]>target) break;
                if(nums[i]+nums[j]+nums[len-2]+nums[len-1]<target) continue;
                
                int left  = j + 1;
                int right = len - 1;
                while(left < right){
                    int distance = nums[i] + nums[j] + nums[left] + nums[right] - target;
                    if(distance == 0){
                        out.push_back({nums[i], nums[j], nums[left], nums[right]});
                        while(left + 1 < len - 1 && nums[left] == nums[left+1]) 
                            left++;
                        while(right - 1 > 2 && nums[right] == nums[right-1]) 
                            right--;
                        left++;
						right--;
                    }
                    else if(distance < 0) 
                        left++;
                    else if(distance > 0)
                        right--;
                }
                while(j+1 < len - 2 && nums[j] == nums[j+1])
                    j++;
                
            }
            while(i + 1 < len - 3 && nums[i] == nums[i+1])
                i++;
        }
        return out;
        
        
    }
};