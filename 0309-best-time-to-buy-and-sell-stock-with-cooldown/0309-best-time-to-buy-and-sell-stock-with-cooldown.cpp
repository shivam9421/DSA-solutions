class Solution {
public:
        vector<vector<vector<int>>> dp;
    int f(int i,int buy,int cooldown,vector<int>& prices){
        if(i==prices.size())return 0;
        if(dp[i][buy][cooldown]!=-1) return dp[i][buy][cooldown];
        if(cooldown){
            int  buyonnextday=f(i+1,1,0,prices);
            dp[i][buy][cooldown]=buyonnextday;
            
        }
        else if(buy ){
            int buytak=-prices[i]+f(i+1,0,0,prices);
            int nbuytak=f(i+1,1,0,prices);
            dp[i][buy][cooldown]=max(buytak,nbuytak);
        }
        else{
          int  sell=prices[i]+f(i+1,0,1,prices);
          int  notsell= f(i+1,0,0,prices);
          dp[i][buy][cooldown]=max(sell,notsell);
        }
        return dp[i][buy][cooldown];
    }
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        if(n==0||n==1) return 0;
        dp.assign(n+1,vector<vector<int>>(2,vector<int>(2,-1)));
        return f(0,1,0,prices);
    }
};