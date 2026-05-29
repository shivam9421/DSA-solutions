class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        int j=0;
        int i=0;
        int n=nums.size();
        long long maxi = 0; long long sum=0;
        unordered_map<int,int> mpp;
        while(j<n){
            mpp[nums[j]]++;
            sum=nums[j]+sum;
            if(j-i+1>k){
                mpp[nums[i]]--;
                if (mpp[nums[i]] == 0) {  // ← yeh add kar
                    mpp.erase(nums[i]);}
                sum=sum-nums[i];
                i++;
            }
            if(j-i+1==k &&  mpp.size()==k){
                maxi=max(sum,maxi);
            }
            j++;
        }

        return maxi;
    }
};