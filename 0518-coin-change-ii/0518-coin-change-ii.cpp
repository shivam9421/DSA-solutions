class Solution {
public:
    int f(int i,int amount ,vector<int>& coins,vector<vector<int>>&dp){
        //base
        if(i<0)return 0;
        if(amount==0)return 1;
        if(amount<0) return 0;
        if(dp[i][amount]!=-1)return dp[i][amount];
        int take=0;
        if(amount>=coins[i]){
            take=f(i,amount-coins[i],coins,dp);
        }
        int ntake=f(i-1,amount,coins,dp);

        return dp[i][amount]=take+ntake;

    }
    int change(int amount, vector<int>& coins) {
       int n=coins.size();
       vector<vector<int>>dp(n+1,vector<int>(amount+1 ,-1));
        return f(n-1,amount ,coins,dp);
    }
};