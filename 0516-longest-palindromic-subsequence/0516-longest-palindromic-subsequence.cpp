class Solution {
public:
    vector<vector<int>>dp;
    int f(int i,int j,string &s,string & r){
        if(i<0 ||j<0){
            return 0;
        }
        if(dp[i][j]!=-1)return dp[i][j];
        if(s[i]==r[j]){
            return 1+f(i-1,j-1,s,r);
        }
        else{
            return dp[i][j] = max(f(i-1, j, s, r), f(i, j-1, s, r));
        }

 
    }
    int longestPalindromeSubseq(std::string s) {
        int n1=s.size();
        string r=s;
        reverse(r.begin(),r.end());
        dp.assign(n1+1,vector<int>(n1+1,-1));
        return f(n1-1,n1-1,s,r);

    }
};