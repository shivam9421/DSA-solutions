class Solution {
public: vector<vector<int>> dp;
    int f(int i,int j,string &text1,string &text2){
        //base
        if(i==text1.size()||j==text2.size())return 0;
        if(dp[i][j]!=-1)return dp[i][j];
        if(text1[i]==text2[j]){
         return dp[i][j]= 1+ f(i+1,j+1,text1,text2);
        }
        else{
         return dp[i][j]= max(f(i+1,j,text1,text2),f(i,j+1,text1,text2));
        }
    }
    int longestCommonSubsequence(string text1, string text2) {
        int n1=text1.size(),n2=text2.size();
        dp.assign(n1+1,vector<int>(n2+1,-1));
        return f(0,0,text1,text2);
    }
};