class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<pair<int,int>>> adj(n);
        for(int i = 0; i < flights.size(); i++){
            int u = flights[i][0];
            int v = flights[i][1];
            int price = flights[i][2];
            adj[u].push_back({v, price});
        }
        
        using p = pair<int, pair<int, int>>;
        priority_queue<p, vector<p>, greater<p>> pq;
        vector<int> minstops(n, 1e9);
        
        pq.push({0, {0, src}}); // {price, {stops, node}}
        
        while(!pq.empty()){
            auto it = pq.top();
            pq.pop();
            
            int price = it.first;
            int stop = it.second.first;
            int from = it.second.second;
            
            if(from == dst) return price;
            
            // If we reached 'from' node with more or equal stops than previously seen, skip it
            if(stop >= minstops[from]) continue;
            minstops[from] = stop;
            
            if(stop > k) continue;
            
            for(int i = 0; i < adj[from].size(); i++){
                auto destination_price = adj[from][i];
                int totalprice = price + destination_price.second;
                int destination = destination_price.first;
                
                // Only push if the next stop count is within bounds
                if(stop <= k){
                    pq.push({totalprice, {stop + 1, destination}});
                }
            }
        }
        return -1;
    }
};