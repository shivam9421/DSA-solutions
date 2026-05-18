class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int i=0;
        int j=0;
        int n=nums.size();
        int count_zero=0;
        int maxlength=0;
        while(j<n){
            int length;
            if(nums[j]==0){
                count_zero++;
            }
            while(k<count_zero){
                if (nums[i] == 0) {
                    count_zero--;
                }
            i++;
            }
            maxlength = max(maxlength, j - i + 1);
            j++;
           

        }
        return maxlength;
    }
};