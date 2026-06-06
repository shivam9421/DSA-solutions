class Solution {
public:
vector<vector<int>> dp;
    int f(int i, int amount, vector<int>& coins) {
        if (i < 0||amount<0)
            return 1e9;
        if (dp[i][amount]!= -1)
            return dp[i][amount];
        if(amount==0)    return 0;
        int take=1e9;
        if (amount >= coins[i]) {
            take = 1 + f(i, amount - coins[i], coins);
        }
        int nottake = f(i - 1, amount, coins);
        return dp[i][amount] = min(take, nottake);
    }
    int coinChange(vector<int>& coins, int amount) {
        int n=coins.size();

        dp.assign(n+1,vector<int>(amount+1,-1));
        int result=f(n-1,amount,coins);
        if(result>=1e9) return -1;
        return result;
    }
};