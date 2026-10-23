class Solution {
public:
    int sortPermutation(vector<int>& nums) {
          vector<int> a;
          for(int i=0;i<nums.size();i++){
            if(nums[i]!=i){
                a.push_back(nums[i]);
            }
          }
          if(a.empty()) return 0;
          int k=a[0];
          for(int i=1;i<a.size();i++){
            k=(k &a[i]);
          }
          return k;
    }
};