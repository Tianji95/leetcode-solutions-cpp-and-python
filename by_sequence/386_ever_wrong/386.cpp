class Solution {
public:
    vector<int> out;
    
    void dfs(int father, int n){
        if(father > n){
            return ;
        }
        else{
            out.push_back(father);
            for(int i = 0; i < 10; i++){
                if(father*10+i > n){
                    return;
                }
                dfs(father*10+i, n);
            }
        }
    }
    
    vector<int> lexicalOrder(int n) {
        for(int i = 1; i < 10; i++){
            dfs(i, n);
        }
        return out;
    }
};