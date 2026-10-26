class Solution {
public:
    int countIslands(vector<vector<int>>& grid, int k) {
        int count=0;
        int m=grid.size();
        int n=grid[0].size();
        int  drow[]={-1,0,1,0};
        int  dcol[]={0,-1,0,1};
        vector<vector<int>> vis(m,vector<int>(n,0));
        for(int row=0;row<m;row++){
            for(int col=0;col<n;col++){
                if(vis[row][col]!=0 ||grid[row][col]==0)continue;
                queue<pair<int,int>>q;//row,col
                q.push({row,col});
                long long val=grid[row][col];
                vis[row][col]=1;
                while(!q.empty()){
                    auto it=q.front();
                    q.pop();
                    int r=it.first;
                    int c=it.second;
                   
                    for(int i=0;i<4;i++){
                        int nrow=drow[i]+r;
                        int ncol=dcol[i]+c;
                        if(nrow>=0 && ncol>=0 && nrow<m && ncol<n &&
                        vis[nrow][ncol]==0 && grid[nrow][ncol]!=0
                        ){
                        vis[nrow][ncol]=1;
                        val=val+grid[nrow][ncol];
                        q.push({nrow,ncol});}
                    }
                }
                if(val%k==0)count++;
                
            }
        }
        return count;
        
    }
};