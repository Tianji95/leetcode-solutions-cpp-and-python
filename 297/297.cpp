/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:
    void seriIter(TreeNode* node, string& s){
        s += ",";
        s += to_string(node->val);
        if(node->left)
            seriIter(node->left, s);
        else
            s += ",#";
        if(node->right)
            seriIter(node->right, s);
        else
            s += ",#";
        
    }
    
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if(!root)
            return "";
        
        string out("");
        out += to_string(root->val);
        if(root->left)
            seriIter(root->left, out);
        else
            out+=",#";
        
        if(root->right)
            seriIter(root->right, out);
        else
            out+=",#";
        
        return out;
        
    }
    
    int findNum(string s, int& idx){
        bool isMinus = false;
        if(s[idx] == '-'){
            isMinus = true;
            idx++;
        }
        int out = s[idx++] - '0';
        while(s[idx]!=',' && idx < s.size()){
            out = out*10+s[idx]-'0';
            idx++;
        }
        if(isMinus)
            out = -out;
        return out;
    }
    
    TreeNode* deserIter(string& data, int& idx){
        int nextNum = findNum(data, idx);
        TreeNode* node = new TreeNode(nextNum);
        if(idx == data.size())
            return node;
        idx++;
        if(data[idx] == '#'){
            idx+=2;
            node->left = nullptr;
        }
        else{
            node->left = deserIter(data, idx);
        }
        
        if(idx == data.size())
            return node;
        
        if(data[idx] == '#'){
            idx+=2;
            node->right = nullptr;
        }
        else{
            node->right = deserIter(data, idx);
        }
        
        return node;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        int len = data.size();
        if(len == 0)
            return nullptr;
        
        int idx = 0;
        int nextNum = findNum(data, idx);
        TreeNode* root = new TreeNode(nextNum);
        TreeNode* now  = root;
        if(idx == data.size())
            return root;
        idx++;
        if(data[idx] == '#'){
            idx+=2;
            root->left = nullptr;
        }
        else{
            root->left = deserIter(data, idx);
        }
        if(idx == data.size())
            return root;
        
        if(data[idx]=='#'){
            idx+=2;
            root->right == nullptr;
        }
        else{
            root->right = deserIter(data, idx);
        }
        
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));