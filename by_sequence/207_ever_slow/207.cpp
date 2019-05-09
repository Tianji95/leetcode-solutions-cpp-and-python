class Node{
public:
    vector<Node*> next;
    bool isPass;
    int val;
    Node(int v){
        isPass = false;
        val = v;
        next.clear();
    }
};
class Solution {
public:
    unordered_map<int, Node*> nodeMap;
    bool isCircle(Node* node){
        if(node->isPass)
            return true;
        
        node->isPass = true;
        for(int i = 0; i < node->next.size(); i++){
            if(isCircle(node->next[i]))
                return true;
        }
        node->isPass = false;
        return false;
    }
    bool canFinish(int numCourses, vector<pair<int, int>>& prerequisites) {
        
        Node* fontN;
        Node* afterN;
        int len = prerequisites.size();
        
        for(int i = 0; i < len; i++){
            int font = prerequisites[i].second;
            int after= prerequisites[i].first;
            
            if(nodeMap.find(font) != nodeMap.end()){
                fontN = nodeMap[font];
            }
            else{
                fontN = new Node(font);
                nodeMap[font] = fontN;
            }
            
            if(nodeMap.find(after) != nodeMap.end()){
                afterN = nodeMap[after];
            }
            else{
                afterN = new Node(after);
                nodeMap[after] = afterN;
            }
            
            fontN->next.push_back(afterN);
                
        }
        
        for(int i = 0; i < numCourses; i++){
            if(nodeMap.find(i)==nodeMap.end())
                continue;
            else{
                if(isCircle(nodeMap[i]))
                    return false;
            }
        }
        return true;
    }
};