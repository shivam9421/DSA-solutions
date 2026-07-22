class Solution {
public:
    void helper(vector<vector<char>>& grid,vector<vector<int>>&vis,int i,int j,vector<int>&d_row,vector<int>d_col){
        vis[i][j]=1;
        int m=grid.size();
        int n= grid[0].size();        
        for(int p=0;p<4;p++){
            int n_row=d_row[p]+i;
            int n_col=d_col[p]+j;
            if(n_row>=0&&n_col>=0&&n_row<m&&n_col<n&&vis[n_row][n_col]==0&&grid[n_row][n_col]=='1'){
                helper(grid,vis,n_row,n_col,d_row,d_col);                
            }
        }

    }
    int numIslands(vector<vector<char>>& grid) {
        int m=grid.size();
        int n= grid[0].size();
        vector<vector<int>>vis(m,vector<int>(n,0));
        int count=0;
        vector<int> d_row={-1,0,1,0};
        vector<int> d_col={0,-1,0,1};
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(vis[i][j]==0 &&grid[i][j]=='1'){
                    count=count+1;
                    helper(grid,vis,i,j,d_row,d_col);
                }
            }
        }
        return count;
    }
};