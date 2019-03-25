class Solution {
public:
    bool isValidSerialization(string preorder) {
        int indegree = 1;
        for(int i = 0; i < preorder.size(); i++){
            if(preorder[i]==','){
                continue;
            }
            if(i+1<preorder.size()&&preorder[i+1]!=','){
                continue;
            }
            if(--indegree < 0){
                return false;
            }
            if(preorder[i]!='#'){
                indegree += 2;
            }
            
        }
        if(indegree==0){
            return true;
        }
        return false;
    }
};