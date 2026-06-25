class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        queue<pair<pair<int, int>,int>> q;
        vector<vector<int>> vis(m, vector<int>(n, 0));
        int cnt_one=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==2){
                    q.push({{i,j},0});
                    vis[i][j]=2;
                }
                else if(grid[i][j]==1)cnt_one++;
                else{
                    vis[i][j]=0;
                }
                
          }
        }
        int max_time=0;
        int drow[]={-1,0,1,0};
        int dcol[]={0,-1,0,1};
        int cnt=0;
        while(!q.empty()){
         int r=q.front().first.first;
         int c=q.front().first.second;
         int t=q.front().second;
         q.pop();
        max_time=max(max_time,t);
        for(int i=0;i<4;i++){
            int nrow=drow[i]+r;
            int ncol=dcol[i]+c;
            if(nrow>=0&&nrow<m&&ncol>=0&&ncol<n&&vis[nrow][ncol]!=2&&grid[nrow][ncol]==1){
                vis[nrow][ncol]=2;
                q.push({{nrow,ncol},t+1});
                cnt++;}
        }
        }
    if(cnt_one!=cnt)return -1;
    return max_time;
    }
};