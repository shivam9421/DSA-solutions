class Solution {
public:
    bool f(int i,int target ,vector<vector<int> >&dp,vector<int> &nums){
        if(i==0){
            return target == nums[0];
            }
        if(target==0) return true;
        if(dp[i][target]!=-1)return dp[i][target];

        bool sntaken= f(i-1,target,dp,nums);
        bool staken=false;
        if(nums[i]<=target)  staken=f(i-1,target-nums[i],dp,nums);
        return dp[i][target] =(sntaken  ||staken);

            }
    bool canPartition(vector<int>& nums) {
        int totalsum=0;
        int n=nums.size();
        for(int i=0;i<nums.size();i++)totalsum=totalsum+nums[i];
        if(totalsum%2!=0)return false;
        int target =totalsum/2;
        vector<vector<int>> dp(n,vector<int>(target+1,-1));
        return f(n-1,target,dp,nums);
    }
};