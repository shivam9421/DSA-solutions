class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        vector<vector<int>> distance(n,vector<int>(n,1e8));
        vector<vector<int>> ways(n,vector<int>(n,-1));
        for(int i=0;i<edges.size();i++){
            int u=edges[i][0];
            int v=edges[i][1];;
            int dist=edges[i][2];
            
            distance[u][v]=dist;
            distance[v][u]=dist;
        }
        for(int i=0;i<n;i++)distance[i][i]=0;

        for(int via=0;via<n;via++){
            for(int i=0;i<n;i++){
                for(int j=0;j<n;j++){
                    if(distance[i][via]!=1e8&&distance[via][j]!=1e8){
                        distance[i][j]=min(distance[i][j],distance[i][via]+distance[via][j]);

                    }
                }
            }}
            int mini=1e8;
            int node=-1;
            for(int i=0;i<n;i++){
                int count=0;
                for(int j=0;j<n;j++){
                    if(distance[i][j]!=1e8 &&distance[i][j]<=distanceThreshold){
                        count+=1;
                    }
                }
                if(mini>=count){
                    mini=min(count,mini);
                    node=i;
                }
            }
        
        return node;
        
    }
};