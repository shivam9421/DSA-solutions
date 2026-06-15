class Solution {
public:
vector<vector<int>>dp;
    bool f(int i,int j,string &s,string &p){
        if(i<0 &&j<0)return true;
        if(i>=0 && j<0)return false;
        if(i<0 &&j>=0){
            while(j>=0){
                if(p[j]!='*')return false;
                j--;
            }
            return true;
        }
        if(dp[i][j]!=-1)return dp[i][j]; 
        if(p[j]=='*'){
            return dp[i][j]= f(i-1,j,s,p)||f(i,j-1,s,p);
        }///important aspect 
        if(p[j]=='?'||s[i]==p[j]) return dp[i][j]=f(i-1,j-1,s,p);
        return dp[i][j]= false;
    }

    bool isMatch(string s, string p) {
        int n1=s.size(),n2=p.size();
        if (n1 == 0 && n2 == 0) return true;
        dp.assign(n1,vector<int>(n2,-1));
        return  f(n1-1,n2-1,s,p);
    }
};