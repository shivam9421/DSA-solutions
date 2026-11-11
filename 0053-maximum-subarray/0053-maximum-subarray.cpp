class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        
        int sum=0;
        int n=nums.size();
        int maxi=INT_MIN;
        if (n==1){
            return nums[0];
        }
         else{
        for (int i =0;i<n;i++)
        {
           
            // if (n=1 ){
            //     return nums[0];
            // }
            sum=sum+nums[i];
            maxi=max(sum,maxi);
            if(sum<0){
                sum=0;
            }

        }
        return maxi;}
    }
};