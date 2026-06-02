class Solution {
public:
    vector<vector<int>> dp;
    int f(int i,int buy,int & fee,vector<int>& prices){
        if(i==prices.size())return 0;
        if(dp[i][buy]!=-1) return dp[i][buy];
         if(buy ){
            int buytak=-(prices[i]+fee)+f(i+1,0,fee,prices);
            int nbuytak=f(i+1,1,fee,prices);
            dp[i][buy]=max(buytak,nbuytak);
        }
        else{
          int  sell=prices[i]+f(i+1,1,fee,prices);
          int  notsell= f(i+1,0,fee,prices);
          dp[i][buy]=max(sell,notsell);
        }
        return dp[i][buy];
    }    
    int maxProfit(vector<int>& prices, int fee) {
         int n=prices.size();
        if(n==0||n==1) return 0;

        dp.assign(n + 1, vector<int>(2, -1));
        return f(0,1,fee,prices);
        
    }
};