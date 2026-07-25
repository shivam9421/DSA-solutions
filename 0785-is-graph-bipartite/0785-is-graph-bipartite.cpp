class Solution {
public:
    bool dfs(int i,vector<int >&color,vector<vector<int>>& graph){
        int n1=graph[i].size();
        for(int j=0;j<n1;j++){
            int nbr=graph[i][j];
            if(color[nbr]==-1){
                color[nbr] = 1 - color[i];  
                if(dfs(nbr,color,graph)==false)return false;
                }
                 else if(color[i]==color[nbr])return false;
        }
       return true;
    
    }
    bool isBipartite(vector<vector<int>>& graph) {
        int v=graph.size();
        vector<int>color(v,-1);
        
        for(int i=0;i<v;i++){
            if(color[i]==-1){
                color[i]=0;
            if(dfs(i,color,graph)==false)return false;
            }
        }
        return true;
        
    }
};