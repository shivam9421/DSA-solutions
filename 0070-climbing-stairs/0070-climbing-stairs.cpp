class Solution {
public:
    int stair(int sum,int n,vector<int>& dp){
        if(sum==n ){     
            return 1 ;
        }
        if(sum>n)return 0;
        if(dp[sum]!=-1)return dp[sum];
        dp[sum]= stair(sum+1,n,dp)+stair(sum+2,n,dp);
        return dp[sum];


    }
    int climbStairs(int n) {
        vector<int>dp(n+1,-1);
        
       return stair(0,n,dp);
        }
        };
