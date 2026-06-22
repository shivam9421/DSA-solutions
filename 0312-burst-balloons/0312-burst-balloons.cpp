class Solution {
public:vector<vector<int>>dp;
    int f(int i,int j,vector<int>& nums){
        if(j<i) return 0;
        if (dp[i][j] != -1) return dp[i][j];
        int maxi=0;
        for(int k=i;k<=j;k++){
            int coins=(nums[i-1]*nums[k]*nums[j+1])+f(i,k-1,nums)+f(k+1,j,nums);
            maxi=max(maxi,coins);

        }
        return dp[i][j]=maxi;
    } 
    int maxCoins(vector<int>& nums) {
        nums.push_back(1);
        nums.insert(nums.begin(),1);
        int n=nums.size();
        dp.assign(n+1,vector<int>(n,-1));
        return f(1,n-2,nums);
        
    }
};