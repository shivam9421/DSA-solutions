class Solution {
    
public:
vector<vector<int>>dp;
   int f(int i,int j,vector<int>& cuts){
    if (j  < i) return 0;
    if (dp[i][j] != -1) return dp[i][j];
    int mini=1e9;
    for(int k=i;k<=j;k++){
        int cost_cut=(cuts[j+1]-cuts[i-1])+f(i,k-1,cuts)+f(k+1,j,cuts);
        mini=min(mini,cost_cut);
    }
    return dp[i][j]=mini;
   }
    int minCost(int n, vector<int>& cuts) {
        cuts.push_back(0);
        cuts.push_back(n);
        sort(cuts.begin(),cuts.end());
        int size=cuts.size();
        dp.assign(size,vector<int>(size,-1));
        
       return f(1,size-2,cuts);
    }
};