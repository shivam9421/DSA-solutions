class Solution {
public:
    int lineartabulation(int l, int r, vector<int>& nums){
        int n = r - l + 1;
        vector<int> dp(n, 0);      // fix 1

        dp[0] = nums[l];
        if(n == 1) return dp[0];   // fix 2

        dp[1] = max(nums[l], nums[l+1]);

        for(int i = 2; i < n; i++){
            int pick = nums[l+i] + dp[i-2];
            int skip = dp[i-1];
            dp[i] = max(pick, skip);
        }
        return dp[n-1];
    }

    int rob(vector<int>& nums) {
        if(nums.size() == 1) return nums[0];

        int case1 = lineartabulation(0, nums.size()-2, nums);
        int case2 = lineartabulation(1, nums.size()-1, nums);
        return max(case1, case2);
    }
};