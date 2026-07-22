class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        int n=strs.size();
        vector<string> strs1=strs;
        unordered_map <string,int>mpp;  
        vector<vector<string>> ans;
        if(n==0)return ans;    
        for(int i=0;i<n;i++ ){
            sort(strs1[i].begin(),strs1[i].end());
            if(mpp.find(strs1[i])!=mpp.end()){
                ans[mpp[strs1[i]]].push_back(strs[i]);
            }
            else{
                vector<string> temp;
                temp.push_back(strs[i]);
                ans.push_back(temp);
                int n1=ans.size();
                mpp[strs1[i]]=n1-1;
            }
        }
        return ans;
    }
};