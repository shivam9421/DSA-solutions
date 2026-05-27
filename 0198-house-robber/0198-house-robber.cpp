class Solution {
public:
    int amaxrob(int i,vector<int> nums,vector<int>&dp){
   //base case i>=n; adjacent element skip ka kuch logic ,i+2  ka pahla logic
   if(nums.size()<=i) return 0;
    if(dp[i]!=-1) return dp[i];
   //adjacent skip
   int pick=nums[i] +amaxrob(i+2,nums,dp);
   int skip=amaxrob(i+1,nums,dp);
   return dp[i]= max(skip,pick);
    }
    int rob(vector<int>& nums) {
        vector<int> dp(nums.size()+1,-1);
        return amaxrob(0,nums,dp);
    
    }
};