class Solution {
public:
    int hIndex(vector<int>& citations) {
        int len = citations.size();
        
        vector<int> bucket(len+1, 0);
        for(int i = 0; i < len; i++){
            if(citations[i] > len){
                bucket[len]++;
            }
            else{
                bucket[citations[i]]++;
            }
        }
        
        int count = 0;
        for(int i = len; i >= 0; i--){
            count += bucket[i];
            if(count >= i)
                return i;
        }
        return 0;
        
    }
};