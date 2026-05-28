class Solution {
public:
    int  f(int i,int j,vector<vector<int>>& obstacleGrid,vector<vector<int>>&dp){
        //base
        if(i<0||j<0) return 0; 
        if (obstacleGrid[i][j]==1) return 0;
        if(i==0&&j==0) return 1;
        if(dp[i][j]!=-1) return dp[i][j];
        //stuff
        int leftpath=f(i,j-1,obstacleGrid,dp);
        int uppath=f(i-1,j,obstacleGrid,dp);
        //return
        return dp[i][j]=uppath+leftpath;
    }
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m=obstacleGrid.size();
        int n=obstacleGrid[0].size();
        vector<vector<int>>dp(m,vector<int>(n,-1));
        return  f(m-1,n-1,obstacleGrid,dp);

    }
};