class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n=grid.size();
        if (grid[0][0] != 0 || grid[n - 1][n - 1] != 0) {
            return -1;
        }
        queue<vector<int>> q;
        q.push({0,0,1});
        grid[0][0]=1;
        int drow[]={-1,-1,0,1,1,1,0,-1};
        int dcol[]={0,1,1,1,0,-1,-1,-1};
        while(!q.empty()){
            auto curr=q.front();
            int row=curr[0];
            int col=curr[1];
            int dis=curr[2];
            q.pop();
            if (row == n - 1 && col == n - 1) {
                return dis;
            }
            for(int i=0;i<8;i++){
                int nrow=row+drow[i];
                int ncol=col+dcol[i];
                if(0<=nrow&&nrow<n&&0<=ncol&&ncol<n&&grid[nrow][ncol]==0){
                    grid[nrow][ncol]=1;
                    q.push({nrow,ncol, dis+1});
                }
            }
        }
        return -1;

    }
};