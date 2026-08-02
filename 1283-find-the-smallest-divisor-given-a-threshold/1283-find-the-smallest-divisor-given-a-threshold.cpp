class Solution {
public:
    bool possible(vector<int>& nums,int &threshold,int mid){
        int sum_div=0;
        for(int i=0;i<nums.size();i++){
            sum_div+=(nums[i]+mid-1)/mid;
        }
        if(threshold>=sum_div)return true;
        return false;
    }
    int smallestDivisor(vector<int>& nums, int threshold) {
        int low = 1;
        int high = *max_element(nums.begin(), nums.end());
        int mini=high;
        while(low<=high){
            int mid=low+(high-low)/2;
            if(possible(nums,threshold,mid)){
                mini=min(mini,mid);
                high=mid-1;
            }
            else{
                low=mid+1;
            }
        }
        return mini;
    }
};