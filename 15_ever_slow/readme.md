这道题做的太慢了，下面是最快的方法：
    
    class Solution {
        public:
            vector<vector<int>> threeSum(vector<int>& nums) {
                vector<vector<int>> res;
                int size = nums.size();
                if(size < 3)
                    return res;
                sort(nums.begin(), nums.end());
                if(nums[0] > 0 || nums[size-1] < 0)
                    return res;
                for(int k=0; k<size-2; k++)
                {
                    int target = 0-nums[k];
                    if (nums[k] > 0)
                        break;
                    if(k>0 && nums[k] == nums[k-1])
                        continue;
                    int i=k+1, j = size-1;
                    while(i<j)
                    {
                        if(nums[i] + nums[j] == target)
                        {
                            res.push_back({nums[k], nums[i], nums[j]});
                            while(i<j && nums[i] == nums[i+1])
                                i++;
                            while(i<j && nums[j] == nums[j-1])
                                j--;
                            i++;j--;
                        }
                        else if(nums[i] + nums[j] < target)
                            i++;
                        else
                            j--;
                    }

                }
                return res;
            }
        };

下面是比较常见的较快方法：
    
    class Solution {
    public:
        vector<vector<int>> threeSum(vector<int>& num) {
            vector<vector<int> > res;

            std::sort(num.begin(), num.end());
            for (int i = 0; i < num.size(); i++) {
                
                int target = -num[i];
                int front = i + 1;
                int back = num.size() - 1;

                while (front < back) {

                    int sum = num[front] + num[back];
                    
                    if (sum < target)
                        front++;

                    else if (sum > target)
                        back--;

                    else {
                        vector<int> triplet(3, 0);
                        triplet[0] = num[i];
                        triplet[1] = num[front];
                        triplet[2] = num[back];
                        res.push_back(triplet);
                    
                        while (front < back && num[front] == triplet[1]) front++;

                        while (front < back && num[back] == triplet[2]) back--;
                    }
                    
                }
                while (i + 1 < num.size() && num[i + 1] == num[i]) 
                    i++;
            }
            return res; 
        }
    };