class Solution {
public:
    vector<vector<vector<int>>> dp;
    int f(int i,vector<int>& prices,int cap ,int buy){
        if(i==prices.size())return 0;
        if(cap==0) return 0;
        if(dp[i][buy][cap]!=-1) return dp[i][buy][cap];
        if(buy){
            int buytaken=-prices[i]+f(i+1,prices,cap,0);
            int buyntake=0+f(i+1,prices,cap,1);
            dp[i][buy][cap]=max(buytaken,buyntake);
        }
        else{
            int soldtake=prices[i]+f(i+1,prices,cap-1,1);
            int soldntake=0+f(i+1,prices,cap,0);
            dp[i][buy][cap]=max(soldtake,soldntake);
        }
        return dp[i][buy][cap];
    }
    int maxProfit(vector<int>& prices) {
        int n= prices.size();
        dp.assign(n+1, vector<vector<int>>(2, vector<int>(3, -1)));
        return f(0,prices,2,1);
    }
};