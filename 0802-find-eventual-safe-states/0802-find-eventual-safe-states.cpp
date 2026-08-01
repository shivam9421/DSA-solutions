class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int V = graph.size();
        vector<vector<int>> revgraph(V);
        vector<int> outdegree(V, 0);
        vector<int> ans;
        queue<int> q;
        for (int i = 0; i < V; i++) {
            outdegree[i] =graph[i].size(); 
            for (int node = 0; node < graph[i].size(); node++) {
                revgraph[graph[i][node]].push_back(i); 
            }
        }
        for (int i = 0; i < V; i++) {
            if (outdegree[i] == 0) {
                q.push(i);
            }
        }
        while (!q.empty()) {
            int node = q.front();
            q.pop();
            for (int i = 0; i < revgraph[node].size(); i++) {
                outdegree[revgraph[node][i]] = outdegree[revgraph[node][i]] - 1;
                if (outdegree[revgraph[node][i]] == 0) {
                    q.push(revgraph[node][i]);
                }
            }
        }
        for (int i = 0; i < V; i++) {
            if (outdegree[i] == 0)
                ans.push_back(i);
        }
        return ans;
    }
};