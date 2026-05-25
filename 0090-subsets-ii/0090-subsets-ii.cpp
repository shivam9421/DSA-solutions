class Solution {
public: 
    void subset(int i,vector<int> & nums,vector<vector<int>>& ans,vector<int>&pickarr ){
        if(i==nums.size()){
            ans.push_back(pickarr);
            return;
        }
        pickarr.push_back(nums[i]);
        subset(i+1,nums,ans,pickarr);
        pickarr.pop_back();
        while(i+1<nums.size() &&nums[i]==nums[i+1]) i++;
        subset(i+1,nums,ans,pickarr);
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());   
        vector<vector<int>> ans;
        vector<int> pickarr;
        subset(0,nums,ans,pickarr);
        return ans;
    }
};