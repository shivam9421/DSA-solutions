class Solution {
public:
    bool f(int i, vector<int>& nums, vector<int>& dp) {
        // base
        if ((nums.size() - 1) <= i)
            return true;
        if (nums[i] == 0)
            return false;
        if (dp[i] != -1)
            return dp[i];
        ///
        for (int step = 1; step <= nums[i]; step++) {
            if (f(i + step, nums, dp))
                return dp[i] = true;
        }

        return dp[i] = false;
    }
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n, -1);
        bool a = f(0, nums, dp);
        return a;
    }
};