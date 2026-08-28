class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int m=heights.size();
        int n=heights[0].size();
        vector<vector<int>> dis(m,vector<int>(n,1e9));
        using pair_int=pair<int,pair<int,int>>;
        priority_queue<pair_int,vector<pair_int>,greater<pair_int>> pq;
        dis[0][0]=0;
        pq.push({0,{0,0}});
        int drow[]={-1,0,1,0};
        int dcol[]={0,1,0,-1};
        while(!pq.empty()){
            int effort=pq.top().first;
            int row_node=pq.top().second.first;
            int col_node=pq.top().second.second;
            pq.pop();
            if(row_node==m-1&&col_node==n-1)return effort;
            if (effort > dis[row_node][col_node]) continue;
            for(int i=0;i<4;i++){
                int nrow=row_node+drow[i];
                int ncol=col_node+dcol[i];
                if(0<=nrow && nrow<m && 0<=ncol && ncol<n ){
                int newEffort = max(effort, abs(heights[nrow][ncol] - heights[row_node][col_node]));
                if(newEffort<dis[nrow][ncol]){
                    dis[nrow][ncol]=newEffort;
                    pq.push({newEffort,{nrow,ncol}});
                }
                }
            }

        }
        return 0;
        
    }
};