class Solution {
public:
    int f(int i,int j1,int j2,vector<vector<int>>& grid,vector<vector<vector<int>>>&dp){
        if(grid.size()<=i)return 0;
        if(grid[0].size()<=j1 ||grid[0].size()<=j2 || j1<0||j2<0 )return 0;
        if(i==grid.size()-1){
            if (j1 == j2) return grid[i][j1];
            else return grid[i][j1]+grid[i][j2];
        }
        if(dp[i][j1][j2]!=-1) return dp[i][j1][j2];
        int maxi=0;
        for(int dj1=-1 ;dj1<=1;dj1++){
            for(int dj2=-1;dj2<=1;dj2++){
                int cherries = 0;
                if(j1==j2){
                    cherries = grid[i][j1];
                }
                else {
                    cherries = grid[i][j1] + grid[i][j2];
                }
                cherries+=f(i+1,j1+dj1,j2+dj2,grid,dp);
                maxi=max(maxi,cherries);
            }
            }
        return dp[i][j1][j2]=maxi;
    }
    int cherryPickup(vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();

vector<vector<vector<int>>> dp1(rows, vector<vector<int>>(cols, vector<int>(cols, -1)));
       return f(0,0,cols-1,grid,dp1);
    }
};