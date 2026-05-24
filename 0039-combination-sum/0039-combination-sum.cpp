class Solution {
public:
    void pickele(vector<int>& candidates,int i,int target,vector<int>&pick,vector<vector<int>>& ans){
        if(i==candidates.size()){
            if(target==0)ans.push_back(pick);
            return;
        }
        if(candidates[i]<=target){
            pick.push_back(candidates[i]);
            pickele(candidates,i,target-candidates[i],pick,ans);
            pick.pop_back();
        }
        pickele(candidates,i+1,target,pick,ans);

    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>>ans;
        vector<int>pick;
        pickele(candidates,0,target,pick,ans);
        return ans;
        }   
    
};