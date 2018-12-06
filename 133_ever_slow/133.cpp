/**
 * Definition for undirected graph.
 * struct UndirectedGraphNode {
 *     int label;
 *     vector<UndirectedGraphNode *> neighbors;
 *     UndirectedGraphNode(int x) : label(x) {};
 * };
 */
class Solution {
public:
    UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
        if(!node)
            return nullptr;
        UndirectedGraphNode* out = new UndirectedGraphNode(node->label);
        hasClonedList.push_back(node->label);
        nodeList.push_back(out);
        
        for(int i = 0; i < node->neighbors.size(); i++){
            auto isFind = std::find(hasClonedList.begin(), hasClonedList.end(), node->neighbors[i]->label);
            if(isFind==hasClonedList.end()){
                out->neighbors.push_back(cloneGraph(node->neighbors[i]));
            }
            else{
                out->neighbors.push_back(nodeList[isFind-hasClonedList.begin()]);
            }
        }
        return out;
        
    }
    vector<int> hasClonedList;
    vector<UndirectedGraphNode*> nodeList;
};