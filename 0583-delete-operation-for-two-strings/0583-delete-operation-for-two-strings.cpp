class Solution {
public:
 int f(int i,int j,vector<vector<int>>&dp,string &word1,string& word2){
    if(i<0||j<0) return 0;
    if(dp[i][j]!=-1){
        return  dp[i][j];
    }
    if(word1[i]==word2[j]){
    return dp[i][j]=1+f(i-1,j-1,dp,word1,word2);
    }
    else{
        return  dp[i][j]=max(f(i-1,j,dp,word1,word2),f(i,j-1,dp,word1,word2));
    }}

    int minDistance(string word1, string word2) {
        int n1=word1.size();
        int n2=word2.size();
        vector<vector<int>> dp(n1+1,vector<int>(n2+1,-1));
        int maxwordpresent=f(n1-1,n2-1,dp,word1,word2);
        return (n1-maxwordpresent)+(n2-maxwordpresent);
    }
};