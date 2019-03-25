class Solution {
    private:
    
    struct Node{
        map <string,double> mathMap;
        
        Node(){}
    };

    map<string,Node*> nodeMap;


    
    double findMath(string start, string finish, vector<string> traverse) {
        traverse.push_back(start);
        
  //      cout << start << endl;
        
        if (nodeMap.count(start) == 0) {
            return -1;
        }
        if (start == finish) {
            return 1;
        }
        
        double tmp = 0;
        for (auto i:nodeMap[start]->mathMap) {
            if(find(traverse.begin(),traverse.end(),i.first) == traverse.end()) {
                tmp = findMath(i.first,finish,traverse) * i.second;
 //               cout << tmp << endl;
            }
            if (tmp > 0) {
                return tmp;
            }
        }
        return -1;
    }
    
public:
    vector<double> calcEquation(vector<pair<string, string>> equations, vector<double>& values, vector<pair<string, string>> queries) {
        
        set <string> vars;
        
        for(auto i: equations)
        {
            vars.insert(i.first);
            vars.insert(i.second);
        }
        
        Node* temp;
        for (auto i: vars)
        {
            temp = new Node;
            nodeMap[i] = temp;
        }
        
        for(int i=0; i<values.size(); i++)
        {
            nodeMap[equations[i].first]->mathMap[equations[i].second] = values[i];
            nodeMap[equations[i].second]->mathMap[equations[i].first] = 1/values[i];
        }
        
        vector <string> traverse;
        vector <double> answer;
        double tempNum;
        for (auto i : queries)
        {
   //         cout << "input:  " << i.first << "  " << i.second << endl;
            tempNum = findMath(i.first,i.second,traverse);
            if (tempNum > 0) {
                answer.push_back(tempNum);
            }
            else
                answer.push_back(-1);
        }
        return answer;
    }
};