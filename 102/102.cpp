class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> out;
        if(!root)
            return out;
        
        queue<pair<TreeNode*, int>> Q;
        Q.push(make_pair(root, 1));
        pair<TreeNode*, int> nodePair;

        while(Q.size() != 0){
            nodePair = Q.front();
            Q.pop();
            if(out.size() < nodePair.second){
               vector<int> tmp;
                tmp.push_back(nodePair.first->val);
                out.push_back(tmp);
            }
            else{
                out[nodePair.second-1].push_back(nodePair.first->val);
            }
            
            if(nodePair.first->left)
                Q.push(make_pair(nodePair.first->left, nodePair.second+1));

            if(nodePair.first->right)
                Q.push(make_pair(nodePair.first->right, nodePair.second+1));
        }
        
        return out;
    }
};