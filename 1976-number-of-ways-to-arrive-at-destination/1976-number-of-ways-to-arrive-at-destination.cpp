class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        vector<vector<pair<int, int>>> adj(n);
        long long MOD = 1e9 + 7;
        for (int i = 0; i < roads.size(); i++) {
            int u = roads[i][0];
            int v = roads[i][1];
            int time_taken = roads[i][2];
            adj[u].push_back({v, time_taken});
            adj[v].push_back({u,time_taken});
        }
        using p = pair<long long, long long>;
        
        priority_queue<p, vector<p>, greater<p>> pq;
        vector<long long>time(n,1e18);
        time[0]=0;
        pq.push({0,0});
        long long mintime=0;
        vector<long long> ways(n,0);
        ways[0]=1;
        while(!pq.empty()){
            auto it =pq.top();
            pq.pop();
            long long from=it.second;
            long long time_taken=it.first;
            if(time[from]<time_taken) continue;
            for(auto &it:adj[from]){
                long long destination=it.first;
                long long time_stored_inadj=it.second;
                long long new_time = time_stored_inadj + time_taken;
                if(new_time<time[destination]) {
                    time[destination]=new_time;
                    ways[destination] = ways[from];
                    pq.push({new_time,destination});
                }
                else if (new_time == time[destination]) {
                    ways[destination] = (ways[destination] + ways[from]) % MOD;
                }
            }

        }
        return ways[n-1];
    }
};