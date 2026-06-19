class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        int n=nums.size();
        if (n == 0) return 0;
       
        vector<int>dp(n,1);
        vector<int>count(n,1);   
        int maxi=0;
        for(int i=0;i<n;i++){
            for(int  pre=0;pre<i;pre++){
              if(1+dp[pre]>dp[i]&&nums[i]>nums[pre]){
                dp[i]=1+dp[pre];
                count[i]=count[pre];
                }
                else if(nums[i] > nums[pre]&&1+dp[pre]==dp[i])  
                    count[i]+=count[pre];
                }
             maxi=max(maxi,dp[i])   ;
        }
        int ans = 0;
        for(int i = 0; i < n; i++) {
                if(dp[i]==maxi)
                ans += count[i];
        }
 return ans;
    }
};