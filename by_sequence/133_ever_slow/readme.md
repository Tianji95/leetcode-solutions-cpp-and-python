这一次代码运行的太慢了，主要是用了一个vector来保存已经new过的节点，应该用unordered_map的

    class Solution {
    public:
        UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
            unordered_map<UndirectedGraphNode*, UndirectedGraphNode*> mp;
            UndirectedGraphNode* newRoot = cloneGraph(node, mp);
            return newRoot;
        }
        
        UndirectedGraphNode* cloneGraph(UndirectedGraphNode* root, unordered_map<UndirectedGraphNode*, UndirectedGraphNode*>& mp) {
            if (root == NULL) return NULL;
            if (mp.find(root) != mp.end()) return mp[root];
            UndirectedGraphNode* newRoot = new UndirectedGraphNode(root->label);
            mp[root] = newRoot;
            for (auto n : root->neighbors) {
                newRoot->neighbors.push_back(cloneGraph(n, mp));
            }
            return newRoot;
        }
    };