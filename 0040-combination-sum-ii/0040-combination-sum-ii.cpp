class Solution {
public:
    void cc(int i,int target,vector<int>& candidates,vector<vector<int>> & ans,vector<int> &pick ,int sum){
               if(sum == target){
            ans.push_back(pick);
            return;
        }
        if(i==candidates.size() || sum>target) return;
        pick.push_back(candidates[i]);
        cc(i+1,target,candidates,ans, pick ,sum+candidates[i]);
        pick.pop_back();
        while(i+1<candidates.size() && candidates[i]==candidates[i+1]) i++;
        
        cc(i+1,target,candidates,ans, pick ,sum);
    }

    
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> pick;
        sort(candidates.begin(), candidates.end()); 
        cc(0,target,candidates,ans, pick ,0);
        return ans;
    }
};