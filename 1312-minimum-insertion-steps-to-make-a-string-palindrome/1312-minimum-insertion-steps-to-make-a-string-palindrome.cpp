class Solution {
public:
 int f(int i,int j,vector<vector<int>>&dp,string &s,string& r){
    if(i<0||j<0) return 0;
    if(dp[i][j]!=-1){
        return  dp[i][j];
    }
    if(s[i]==r[j]){
    return dp[i][j]=1+f(i-1,j-1,dp,s,r);
    }
    else{
        return  dp[i][j]=max(f(i-1,j,dp,s,r),f(i,j-1,dp,s,r));
    }

 }
    int minInsertions(string s) {
        string r=s;
        reverse(r.begin(),r.end());
        int n=s.size();
        vector<vector<int>> dp(n+1,vector<int>(n+1,-1));
        int maximumpallandromic_present=f(n-1,n-1,dp,s,r);
        return n-maximumpallandromic_present;
        
    }
};