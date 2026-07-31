class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        int  V=numCourses;
        vector<vector<int>> adj(V);
		
		int E = prerequisites.size();
		vector<int>indegree(V, 0);
		for (int j = 0; j<E; j++) {
			int u = prerequisites[j][0];
			int v = prerequisites[j][1];
			adj[u].push_back(v);
			indegree[v]++;
		}
		queue<int> q;
		for (int i = 0; i<V; i++) {
			if (indegree[i] == 0) {
				q.push(i);
			}
		}
		
		while (!q.empty()) {
			int node = q.front();
			q.pop();
			for (int i = 0; i<adj[node].size(); i++) {
				indegree[adj[node][i]] = indegree[adj[node][i]]-1;
				if (indegree[adj[node][i]] == 0) {
					q.push(adj[node][i]);
				}
			}
		}
        for(int i=0;i<V;i++){
            if(indegree[i]!=0)return false;
        }
        return true;
    }
};