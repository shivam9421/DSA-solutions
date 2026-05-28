class Solution {
public:
    int f(int i,int j,int m,int n,vector<vector <int>>& dp){
        if(i==m-1&&j==n-1)return 1;
        else if(i==m)return 0;
        else if(j==n)return 0;
        if(dp[i][j]!=-1)return dp[i][j];
        int pathdown=f(i+1,j,m,n,dp);
        int pathright=f(i,j+1,m,n,dp);
        
        dp[i][j]=pathdown+pathright;
       
        return dp[i][j];
    } 
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m, vector<int>(n, -1));
        return f(0,0,m,n,dp);         
    }
};