class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int count=0;
        for(int a:nums){
            if(count<2 || a!=nums[count-2]){
                nums[count]=a;
                count++;
            }
        }
        return count;
    }
};