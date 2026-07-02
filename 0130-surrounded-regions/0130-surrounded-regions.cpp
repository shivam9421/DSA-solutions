class Solution {
public:
    void dfs(int r,int c,vector<vector<int>>&vis,vector<int>&drow,vector<int>&dcol,vector<vector<char>>& board){
        int m=board.size();
        int n=board[0].size();
        vis[r][c]=1;
        for(int i=0;i<4;i++){
            int nrow=r+drow[i];
            int ncol=c+dcol[i];
            if((nrow>=0&&ncol>=0&&nrow<m&&ncol<n)&&(vis[nrow][ncol]==0&&board[nrow][ncol]=='O')){
                dfs(nrow,ncol,vis,drow,dcol,board);
        }
    }}
    void solve(vector<vector<char>>& board) {
        int m=board.size();
        int n=board[0].size();
        vector<vector<int>>vis(m,vector<int>(n,0));
        vector<int> drow={-1,0,1,0};
        vector<int>dcol={0,-1,0,1};
        for(int j=0;j<n;j++ ){
            if(board[0][j]=='O'){
                dfs(0,j,vis,drow,dcol,board);
            }
        }
        for(int j=0;j<n;j++ ){
            if(board[m-1][j]=='O'){
                dfs(m-1,j,vis,drow,dcol,board);
            }
        }
         for(int i=0;i<m;i++ ){
            if(board[i][0]=='O'){
                dfs(i,0,vis,drow,dcol,board);
            }
        }
        for(int i=0;i<m;i++ ){
            if(board[i][n-1]=='O'){
                dfs(i,n-1,vis,drow,dcol,board);
            }
        }
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(vis[i][j]==0&& board[i][j]=='O')board[i][j]='X';
            }
        }
        
    }
};