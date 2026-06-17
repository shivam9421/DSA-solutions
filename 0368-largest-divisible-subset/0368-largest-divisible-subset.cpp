class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n=nums.size();
        vector<int>dp(n,1);
        vector<int>hash(n);
        int  lastindex;
        int maxi=0;
        for(int i=0;i<n;i++){
            hash[i]=i;
            for(int prev=0;prev<i;prev++){
                if(1+dp[prev]>dp[i]&&nums[i]%nums[prev]==0){
                    dp[i]=1+dp[prev];
                    hash[i]=prev;
                }

            }
            if(dp[i]>maxi){
                maxi=max(dp[i],maxi);
                lastindex=i;
            } 
        }
        vector<int>temp;
        while(hash[lastindex]!=lastindex){
            temp.push_back(nums[lastindex]);
            lastindex=hash[lastindex];
        }
        temp.push_back(nums[lastindex]);
        reverse(temp.begin(),temp.end());
        return temp;
    }
};