//比较快速的方法
class Solution {
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        stack<TreeNode*> st;
        TreeNode *right = NULL, *root = NULL;
        
        for(int p = 0, i = 0; p < preorder.size();){
            do{
                TreeNode* n = new TreeNode(preorder[p]);
                if(root == NULL)
                    root = n;
                if(st.size() > 0){
                    if(st.top() == right){
                        st.top()->right = n;
                        right = NULL;
                        st.pop();
                    }else{
                        st.top()->left = n;
                    }
                }
                st.push(n);
            }while(i < inorder.size() && p < preorder.size() && preorder[p++] != inorder[i]);
            
            while(i < inorder.size() && st.size() > 0 && inorder[i] == st.top()->val){
                i++;
                right = st.top();
                st.pop();
            }
            
            if(right != NULL)
                st.push(right);
        }
        
        return root;
    }
};


// 用hash_map来做的方法

class Solution {
public:
    
    TreeNode* recBuild (vector<int>& preorder, int low, int high, int &pre) {
        if (low > high) {
            return NULL;
        }
        
        TreeNode *cur = new TreeNode(preorder[pre++]);
        
        if (low == high) {
            return cur;
        }
        
        int pos = hash[cur->val];
        
        cur->left = recBuild(preorder, low, pos - 1, pre);
        cur->right = recBuild(preorder, pos + 1, high, pre);
        
        return cur;
    }
    
    
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        if (preorder.empty() || inorder.empty() || preorder.size() != inorder.size()) {
            return NULL;
        }
        
        for (int i = 0; i < inorder.size(); i++) {
            hash[inorder[i]] = i;
        }
        
        int pre = 0;
        
        return recBuild(preorder, 0, preorder.size() - 1, pre);
        
    }
    
private:
    unordered_map<int, int> hash;
};


//以及一个稍微比较好理解的方法

class Solution {

public:
    /* from Preorder and Inorder Traversal */
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {

        return helper(preorder,0,preorder.size(),inorder,0,inorder.size());
    
    }

    TreeNode* helper(vector<int>& preorder,int i,int j,vector<int>& inorder,int ii,int jj)
    {
        // tree        8 4 5 3 7 3
        // preorder    8 [4 3 3 7] [5]
        // inorder     [3 3 4 7] 8 [5]

        // 每次从 preorder 头部取一个值 mid，作为树的根节点
        // 检查 mid 在 inorder 中 的位置，则 mid 前面部分将作为 树的左子树，右部分作为树的右子树

        if(i >= j || ii >= j)
            return NULL;

        int mid = preorder[i];
        auto f = find(inorder.begin() + ii,inorder.begin() + jj,mid);

        int dis = f - inorder.begin() - ii;

        TreeNode* root = new TreeNode(mid);
        root -> left = helper(preorder,i + 1,i + 1 + dis,inorder,ii,ii + dis);
        root -> right = helper(preorder,i + 1 + dis,j,inorder,ii + dis + 1,jj);
        return root;
    }
};
