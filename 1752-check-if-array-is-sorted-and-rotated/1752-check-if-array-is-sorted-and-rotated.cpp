class Solution {
public:
    bool check(vector<int>& nums) { 
        int d=0;
        int n=nums.size();
        for(int i=0;i<n;i++){
            if(nums[(i+1)%n]<nums[i]){
                d++;
            }
            
        }
        if(d>1)return false;
        return true;
    }
};