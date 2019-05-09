class Solution {
public:
    int findH(vector<int>& cit, int font, int back){
        if(font > back)
            return -1;
        
        int middle = (back+font) / 2;
        
        if(cit[middle] >= len-middle){
            auto findLarger = findH(cit, font, middle-1);
            if(findLarger!=-1)
                return findLarger;
            else
                return len-middle;
        }
        else{
            return findH(cit, middle+1, back);
        }
    }
    
    int hIndex(vector<int>& citations) {
        len  = citations.size();
        if(len == 0)
            return len;
        
        return findH(citations, 0, len);
        
    }
    int len;
};