class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int maxi=INT_MIN;
        int s_maxi=INT_MIN;
        int n=nums.size();
        for(int i=0;i<n;i++){
            if(nums[i]>maxi){
                s_maxi=maxi;
                maxi=nums[i];
                

            }
           else if(s_maxi<nums[i]){
                s_maxi=nums[i];
                
            }

        }
        return (maxi-1)*(s_maxi-1);
        
    }
};