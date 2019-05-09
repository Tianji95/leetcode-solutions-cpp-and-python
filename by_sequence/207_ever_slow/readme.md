更快的使用queue的方法：

    class Solution {
    public:
        bool canFinish(int numCourses, vector<pair<int, int>>& prerequisites) {
            vector<vector<int>> graph(numCourses);
            vector<int> indegree(numCourses,0);
            for(auto edge : prerequisites)
            {
                graph[edge.second].push_back(edge.first);
                ++indegree[edge.first];
            }
            queue<int> Q;
            for(int i = 0;i < numCourses;i++)
                if(indegree[i] == 0)
                    Q.push(i);
            int counter = 0;
            while(!Q.empty())
            {
                int u = Q.front();
                Q.pop();
                ++counter;
                for(auto v : graph[u])
                {
                    if(--indegree[v] == 0)
                        Q.push(v);
                }
            }
            return counter == numCourses;
        }
    };