这道题我写的太麻烦了。。。。看了别人写的发现有更好更清晰的解法

    class Solution {
    public:
        vector<TreeNode*> generateTreesUseRecursion(const int start, const int end)
        {
            if (start > end)
            {
                return { nullptr };
            }

            vector<TreeNode*> trees;
            for (int i = start; i <= end; ++i)
            {
                for (TreeNode* leftRoot : generateTreesUseRecursion(start, i - 1)) // left child, low..i - 1
                {
                    for (TreeNode* rightRoot : generateTreesUseRecursion(i + 1, end)) // right child i+1..high
                    {
                        TreeNode* root = new TreeNode(i);
                        root->left = leftRoot;
                        root->right = rightRoot;
                        trees.push_back(root);
                    }
                }
            }

            return trees;
        }
        vector<TreeNode *> generateTrees(int n) {
            if(n == 0){
                vector<TreeNode *> out;
                return out;
            }
            
            return generateTreesUseRecursion(1, n);
        }
    };