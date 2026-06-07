class Solution {
public:
   int  f(int i,int target,int absolutesum,vector<vector<int>> &dp,vector<int>& nums){
    if(i<0){
        if(target==0) return 1;
        return 0;
    }
    if (target > absolutesum || target < -absolutesum) return 0;
    int safetarget=absolutesum+target;
    if(dp[i][safetarget]!=-1) return dp[i][safetarget];
    int minuspath = f(i - 1, target - nums[i],absolutesum, dp, nums );
    int pluspath  = f(i - 1, target + nums[i],absolutesum ,dp, nums);
    return dp[i][safetarget]=minuspath+pluspath;
    }
   

    int findTargetSumWays(vector<int>& nums, int target) {
        int n= nums.size();
        int absolutesum=0;
        int totalsum=0;
        for(int i=0;i<n;i++){absolutesum=abs(nums[i])+absolutesum;
       totalsum=(nums[i])+totalsum;
        }
        if (abs(target) > totalsum) return 0;
        vector<vector<int>>  dp(n+1,vector<int>(2*absolutesum+1,-1));
        return f(n-1,target,absolutesum,dp,nums);
}};