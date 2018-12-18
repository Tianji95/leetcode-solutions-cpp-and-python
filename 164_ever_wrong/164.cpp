class Solution {
public:
    int maximumGap(vector<int>& nums) {
        int len = nums.size();
        if(len < 2)
            return 0;
        
        int MinNum = INT_MAX;
        int MaxNum = INT_MIN;
        for(auto& num : nums){
            if(num > MaxNum){
                MaxNum = num;
            }
            if(num < MinNum){
                MinNum = num;
            }
        }
        int gap = std::max((MaxNum-MinNum) / (len-1), 1);
        int bucketNum = (MaxNum-MinNum) / gap + 1;
        vector<int> MinBucket(bucketNum, INT_MAX);
        vector<int> MaxBucket(bucketNum, INT_MIN);
        
        for(auto& num : nums){
            int k = (num - MinNum) / gap;
            if(MinBucket[k] > num)
                MinBucket[k] = num;
            if(MaxBucket[k] < num)
                MaxBucket[k] = num;
        }
        int i = 0;
        int j;
        gap = MaxBucket[0] - MinBucket[0];
        while(i < bucketNum){
            j = i + 1;
            while(j < bucketNum && MinBucket[j] == INT_MAX){
                j++;
            }
            if(j == bucketNum)
                break;
            int nowGap = MinBucket[j] - MaxBucket[i];
            if(nowGap > gap){
                gap = nowGap;
            }
            i = j;
        }
        return gap;
        
    }
};