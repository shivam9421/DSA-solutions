class Solution {
public:
    int longestSubsequence(vector<int>& nums) {
        if(nums.size()==0)return 0;

        int all_zero=true;
        int a=0;
        for(int i=0;i<nums.size();i++){
            a=a^nums[i];
            if(a!=0){
                all_zero=false;
            }
        }
        if(all_zero)return 0;
        if(a==0)return nums.size()-1;
        return nums.size();


    }
};