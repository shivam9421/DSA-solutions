class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        unordered_map<int,int>mpp;
        int maxi_window=0;
        int n=nums.size();
        int i=0,j=0;
        while(j<n){
            mpp[nums[j]]++;
            while(mpp[nums[j]]>k){
                mpp[nums[i]]--;
                i++; }
                int window=j-i+1;
                maxi_window=max(window,maxi_window);
                j++;
        }
        return maxi_window;
    }
};