class Solution {
public:
    vector<vector<int>> dp;
    int f(int i, int j, string& s, string& t) {
        if (j == -1)
            return 1;
        if (i < 0 & j >= 0)
            return 0;
        if(dp[i][j]!=-1)return dp[i][j];
        if (s[i] == t[j]) {
            int taken = f(i - 1, j - 1, s, t);
            int nottaken = f(i - 1, j, s, t);
            return dp[i][j]= taken + nottaken;
        } else
            return dp[i][j]=f(i - 1, j, s, t);
    }
    int numDistinct(string s, string t) {
        int n1 = s.size(), n2 = t.size();
        dp.assign(n1, vector<int>(n2, -1));
        return f(n1 - 1, n2 - 1, s, t);
    }
};