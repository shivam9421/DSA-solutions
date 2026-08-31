class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int, int>>> adj(n+1);
        for (int i = 0; i < times.size(); i++) {
            int u = times[i][0];
            int v = times[i][1];
            int time_taken = times[i][2];
            adj[u].push_back({v, time_taken});
        }
        if (adj[k].size() == 0)
            return -1;
        using p = pair<int, int>;
        priority_queue<p, vector<p>, greater<p>> pq;
        vector<int> time4n(n+1, 1e9);
        time4n[k] = 0;
        pq.push({0, k});
        while (!pq.empty()) {
            auto it = pq.top();
            int node = it.second;
            int time4reach = it.first;
            pq.pop();
            if (time4reach > time4n[node])
                continue;
            for (const auto& neighbor : adj[node]) {
                int next_node = neighbor.first;
                int weight = neighbor.second;

                if (time4reach + weight < time4n[next_node]) {
                    time4n[next_node] = time4reach + weight;
                    pq.push({time4n[next_node], next_node});
                }
            }
        }
        int min_time_4_reach_all_n = 0;
        for(int i=1;i<=n;i++){
            if(time4n[i]==1e9)return -1;
            min_time_4_reach_all_n = max(      min_time_4_reach_all_n ,time4n[i]);
        }
        return min_time_4_reach_all_n;
    }
};